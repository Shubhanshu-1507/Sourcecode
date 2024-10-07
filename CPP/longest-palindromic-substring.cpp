#include <iostream>
#include <string>

using namespace std;

// Function to expand around the center and find the longest palindrome
string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return the longest palindromic substring found
    return s.substr(left + 1, right - left - 1);
}

// Function to find the longest palindromic substring
string longestPalindromicSubstring(const string& s) {
    if (s.empty()) return "";

    string longest;
    for (int i = 0; i < s.size(); i++) {
        // Check for odd-length palindromes
        string oddPalin = expandAroundCenter(s, i, i);
        if (oddPalin.size() > longest.size()) {
            longest = oddPalin;
        }
        // Check for even-length palindromes
        string evenPalin = expandAroundCenter(s, i, i + 1);
        if (evenPalin.size() > longest.size()) {
            longest = evenPalin;
        }
    }
    return longest;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string result = longestPalindromicSubstring(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
