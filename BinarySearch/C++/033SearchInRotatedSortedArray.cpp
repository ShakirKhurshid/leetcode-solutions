/* 
    Search an element in a rotated sorted array 
    Time complexity : O(Logn)
    Space complexity : O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        // Start binary search
        while (l <= r){
            int m = ((r - l) / 2) + l;
            // If midpoint is the target
            if (nums[m] == target){
                return m;
            }
            
            if (nums[l] <= nums[m]){ 
                // we in the left sorted array. The use of the equality check handles 
                // the cases where the left half consists of only one element
                if(target > nums[m] || target < nums[l]){
                   l = m + 1; // Target is in the right sorted array 
                } else {
                    r = m - 1; // Tatget is in the left sorted array
                }
            } else {
                // we in the right sorted array
                if(target < nums[m] || target > nums[r]){
                    r = m - 1; // Target is in the left sorted array
                } else {
                    l = m + 1; // Target is in the right sorted array
                }
            } 
        }

        return -1; 
    }
};