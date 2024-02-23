# Time complexity: O(Logn)
# Space complexit: O(1)
class Solution:
    def search(self, nums: List[int], target: int) -> int:
    	left = 0
    	right = len(nums) - 1

    	# Continue till we exhause the search space
    	while (left	<= right):
    		# Calculate the midpoint
    		midpoint = left + ((right - left) // 2)  # (l + r) // 2 can lead to overflow
    		if target > nums[midpoint]:
    			l = m + 1
    		elif target < mums[midpoint]:
    			r = m - 1
    		else:
    			return m
    	return -1
