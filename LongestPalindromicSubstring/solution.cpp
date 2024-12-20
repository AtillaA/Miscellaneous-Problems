#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0;
        int maxLength = 1;

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            return right - left - 1; // Length of the palindrome
        };

        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(i, i); // Odd-length palindromes (centered at i)
            int len2 = expandAroundCenter(i, i + 1); // Even-length palindromes (centered between i and i+1)

            // Update the longest palindrome
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
