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
                isAllSame = false; // If any element is different, return false
                maxBeauty = 0; // Update maxBeauty
            }
        }
        
        if (isAllSame != true) {
            sort(nums.begin(), nums.end());
            
            // Use sliding window to count elements in the range [nums[i] - k, nums[i] + k]
            int left = 0;
            for (int right = 0; right < n; ++right) {
                // While nums[right] - nums[left] > 2 * k, move the left pointer
                while (nums[right] - nums[left] > 2 * k) {
                    left++;
                }
                // Update the maximum beauty
                maxBeauty = max(maxBeauty, right - left + 1);
            }
        }

        return maxBeauty;
    }
};
