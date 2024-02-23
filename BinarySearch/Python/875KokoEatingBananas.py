# Time Complexity: O(PLogK)
# Space Complexity: O(1)
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
    	# Define a search range
    	l = 1
    	r = max(piles)
    	result = r

    	# Use binary search to find the lowest eating rate
    	while l <= r:
    		k = ((r - l) // 2) + l
    		hours = 0
    		# Hours taken to eat all the bananas given the current eating rate
    		for p in piles:
    			hours += math.ceil( p / k)
    		if hours <= h:
    			result = k
    			r = k - 1
    		else:
    			l = k + 1
    	return result


