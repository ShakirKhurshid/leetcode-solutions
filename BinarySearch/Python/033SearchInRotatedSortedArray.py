# Time Complexity: O(Logn)
# Space Complexity: O(1)

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while (l <= r):
            m = ((r - l) // 2) + l
            # Start the conditions
            if target == nums[m]:
                return m

            if nums[l] <= nums[m]: # Left half is sorted (we in the left sorted array):
                if target > nums[m] or target < nums[l]:
                    l = m + 1  # Target is in the right half
                else:
                    r = m - 1  # Target is in the left half
            
            else: # Right half is sorted
                if target < nums[m] or target > nums[r]:
                    r = m - 1 # Target is in the left half
                else:
                    l = m + 1 # Target is in the right half
        return - 1
 