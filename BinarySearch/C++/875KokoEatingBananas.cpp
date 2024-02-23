class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Create search range
        int left = 1;
        int right = 0;
        // Get the max element in the vector, kind of shitty in C++ , its equivalent of max()
        // in python
        for (int i : piles) {
            right = max(right, i);
        }
        int result = right;
  
        // Start binary serach
        while (left <= right){
            int k = ((right - left) / 2) + left;
            
            // Check if we all bananas can be eaten with this rate
            long int hours = 0;
            for (int i: piles){
                hours += std::ceil((double) i / k);
            }
            if (hours <= h){
                right = k - 1;
                result = std::min(result, k);

            } else {
                left = k + 1; 
            }
        }

        return result;
        
        
    }
};