#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int input = x;
        long y = 0;
        int sign = (input < 0) ? -1 : 1;   // Determine the sign of x
        input = std::abs(input);           // Work with the absolute value of x

        while (input > 0) {
            int lastDigit = input % 10;    // Extract the last digit
            y = y * 10 + lastDigit;        // Append the last digit to the reversed number
            input /= 10;                   // Remove the last digit from x
        }

        y *= sign;  // Apply the original sign

        if (x != y || x < 0) {
            return false;
        } else {
            return true;
        }
    }
};
