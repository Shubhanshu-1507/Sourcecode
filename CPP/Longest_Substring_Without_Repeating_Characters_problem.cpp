#include <iostream>        // for IO Operations
#include <unordered_map>   // for std::unordered_map
#include <deque>           // for std::deque
#include <string>          // for string class/string datatype which is taken as input
#include <cassert>         // for assert

/**
 * @class Longest_Substring
 * @brief Class that solves the Longest Substring Without Repeating Characters problem.
 */
class Longest_Substring {
public:
    /**
     * @brief Function to find the length of the longest substring without repeating characters.
     * @param s Input string.
     * @return Length of the longest substring.
     */
    int lengthOfLongestSubstring(std::string s) {
        // If the size of string is 1, then it will be the answer.
        if (s.size() == 1) return 1;

        // Map used to store the character frequency.
        std::unordered_map<char, int> m;
        int n = s.length();

        // Deque to remove from back if repeating characters are present.
        std::deque<char> temp;
        std::deque<char> res;
        int i, j;

        // Sliding window approach using two pointers.
        for (i = 0, j = 0; i < n && j < n;) {
            m[s[j]]++;

            // If repeating character found, update result and remove from the front.
            if (m[s[j]] > 1) {
                if (temp.size() > res.size()) {
                    res = temp;
                }

                while (m[s[j]] > 1) {
                    temp.pop_front();
                    m[s[i]]--;
                    i++;
                }
            }

            // Add the current character to the deque.
            temp.push_back(s[j]);
            j++;
        }

        // Final check to update result.
        if (temp.size() > res.size()) {
            res = temp;
        }

        return res.size();  // Return the length of the longest substring.
    }
};

/**
 * @brief Self-test implementations
 * @returns void
 */
static void tests() {
    Longest_Substring soln;
    assert(soln.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(soln.lengthOfLongestSubstring("bbbbb") == 1);
    assert(soln.lengthOfLongestSubstring("pwwkew") == 3);
    assert(soln.lengthOfLongestSubstring("") == 0); // Test case for empty string
    assert(soln.lengthOfLongestSubstring("abcdef") == 6); // Test case for all unique characters
    assert(soln.lengthOfLongestSubstring("a") == 1); // Single character
    std::cout << "All test cases passed!" << std::endl;
}

/**
 * @brief Main function.
 * @return 0 on successful execution.
 */
int main() {
    tests(); // run self-test implementations
    return 0;
}
