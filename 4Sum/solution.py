class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        quadruplets = []
        
        for i in range(n - 3):
            # skip duplicates for 1st elt
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            for j in range(i + 1, n - 2):
                # skip duplicates for 2nd elt
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                    
                # init left/right ptrs for remaining elts
                left = j + 1
                right = n - 1
                
                while left < right:
                    current_sum = nums[i] + nums[j] + nums[left] + nums[right]
                    
                    if current_sum == target:
                        quadruplets.append([nums[i], nums[j], nums[left], nums[right]])
                        
                        # skip duplicates for 3rd elt
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        # skip duplicates for 4th elt
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                            
                        # move ptrs inward after finding a match
                        left += 1
                        right -= 1
                        
                    elif current_sum < target:
                        left += 1  # sum is too small - increase the left
                    else:
                        right -= 1  # sum is too large - decrease the right
                        
        return quadruplets
    
