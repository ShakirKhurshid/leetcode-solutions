class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        res = nums[l]

        # Start binary seach
        while l <= r:
            # if array is aleady sorted, break the loop
            if nums[l] < nums[r]:
                return min(nums[l], res)
                break
                
            m = (l + r) // 2
            #If nums[m] is greater than nums[r], then the minimum value must
            #lie in the range [m+1, r]. So, res is updated with min(res, nums[m+1]).
            if nums[m] > nums[r]:
                l = m + 1
                res = min(res, nums[m + 1])
            #f nums[m] is not greater than nums[r], then the minimum value may lie in the range [l, m]. 
            #So, res is updated with min(res, nums[m]).
            else:
                r = m - 1
                res = min(res, nums[m])
        return res