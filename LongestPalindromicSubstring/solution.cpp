#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return ""; // no substring

        int start = 0;
        int maxLength = 1;

        // helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            // while indices are within bounds
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            return right - left - 1; // length of the palindrome
        };

        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(i, i); // odd-length palindromes (centered at i)
            int len2 = expandAroundCenter(i, i + 1); // even-length palindromes (centered between i and i+1)

            // Update the longest palindrome
            int len = max(len1, len2);

            // condition is updated if the helper function detected a substring with length 2 (or above)
            if (len > maxLength) {
                maxLength = len;              // update the maxLength, depicting the lps
                start = i - (len - 1) / 2;    // update the start point of the substring
            }
            // condition is triggered again if a substring with greater length is found
        }

        return s.substr(start, maxLength);
    }
};
