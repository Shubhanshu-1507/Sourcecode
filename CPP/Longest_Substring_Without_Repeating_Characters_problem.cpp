#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::max
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    vector<int> hash(256, -1); // Hash array to store the last index of characters (256 to cover all ASCII characters)
    
    int l = 0, r = 0, maxlen = 0; // l: left pointer, r: right pointer, maxlen: to store the length of longest substring

    // Sliding window technique
    while (r < n) {
        // If character at r is already seen and lies between l and r, we update l to hash[s[r]] + 1
        if (hash[s[r]] != -1 && hash[s[r]] >= l) {
            l = hash[s[r]] + 1; // Move left pointer to right of the last occurrence
        }

        // Calculate the current length of the substring
        int len = r - l + 1;
        maxlen = max(len, maxlen); // Update maxlen with the maximum of current length and previous maxlen

        hash[s[r]] = r; // Update the hash with the current index of s[r]
        r++; // Move right pointer to the next character
    }

    return maxlen;
}

int main() {
    // example test case
    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s3) << endl;
    return 0;
}
