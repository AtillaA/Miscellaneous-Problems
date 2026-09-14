#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        // base case
        if (n == 0) return "";

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

            // update the longest palindrome
            int len = max(len1, len2);

            // update if helper func detected a substring with greater length
            if (len > maxLength) {
                maxLength = len;              // update maxLength
                start = i - (len - 1) / 2;    // update start pt of the substr
            }
            
            // triggered again if a substr w/ greater length is found
        }

        return s.substr(start, maxLength);
    }
};
