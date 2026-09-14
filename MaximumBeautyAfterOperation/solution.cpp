#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int firstElement = nums[0];
        bool isAllSame = true;
        int maxBeauty = n;

        for (int i = 1; i < n; i++) {
            if (nums[i] != firstElement) {
                isAllSame = false; // if any elt is different
                maxBeauty = 0; // update maxBeauty
            }
        }
        
        if (isAllSame != true) {
            sort(nums.begin(), nums.end());
            
            // sliding window approach to count elts in range: [ nums[i] - k, nums[i] + k ]
            int left = 0;
            for (int right = 0; right < n; ++right) {
                // while [ nums[right] - nums[left] > 2 * k ], move the left ptr
                while (nums[right] - nums[left] > 2 * k) {
                    left++;
                }
                
                maxBeauty = max(maxBeauty, right - left + 1); // update maxBeauty
            }
        }

        return maxBeauty;
    }
};
