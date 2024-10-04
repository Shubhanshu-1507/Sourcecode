# Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

# '?' Matches any single character.
# '*' Matches any sequence of characters (including the empty sequence).
# The matching should cover the entire input string (not partial).

# Example 1:

# Input: s = "aa", p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
# Example 2:

# Input: s = "aa", p = "*"
# Output: true
# Explanation: '*' matches any sequence.
# Example 3:

# Input: s = "cb", p = "?a"
# Output: false
# Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'. 

# Constraints:

# 0 <= s.length, p.length <= 2000
# s contains only lowercase English letters.
# p contains only lowercase English letters, '?' or '*'.

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = [[None] * (len(p) + 1) for _ in range(len(s) + 1)]
        return self.f(s, 0, p, 0, memo)
    
    def f(self, s, i, p, j, memo):
        if i == len(s) and j == len(p): #both strings end : match successfull
            return True

        #Pattern is over but string is left: match unsuccessful.
        #Point to note : if String is over and pattern is left,
        #it 'might' still be possible to match the string.
        #Take for eg. s = "" and p = "*******". 
        if j == len(p): 
            return False
        
        if memo[i][j] is None:  #subproblem not solved earlier.
            flag = False

            #match single character, but string s should be left,
            #else we get IndexError
            if i < len(s) and (s[i] == p[j] or p[j] == '?'): 
                flag = self.f(s, i + 1, p, j + 1, memo)

            elif p[j] == '*':   # can match variable no. of characters, so loop over them and see when it matches.
                for t in range(i, len(s) + 1):
                    if self.f(s, t, p, j + 1, memo):
                        flag = True
                        break
            #if it doesn't ever match, the flag will be False by default.
            memo[i][j] = flag

        return memo[i][j]


