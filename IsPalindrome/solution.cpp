#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int input = x;                     // to edit the input
        long y = 0;                        // reversed number
        int sign = (input < 0) ? -1 : 1;   // determine the sign of x
        input = abs(input);                // absolute value of x

        while (input > 0) {
            int lastDigit = input % 10;    // extract the last digit
            y = y * 10 + lastDigit;        // append the last digit
            input /= 10;                   // remove the last digit of x
        }

        y *= sign;  // apply the original sign

        return (x != y || x < 0) ? false : true; // is the reversed number equal to the original input
    }
};
