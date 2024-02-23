class Solution {
public:
    int findMin(vector<int>& nums) {
        int left {0};
        int right = nums.size() - 1;
        int result = nums[0];


        // Start binary search 
        while (left <= right){

            // Condition if array is not rotated
            if (nums[left] < nums[right])
            {
                result = min(result, nums[left]);
                break;
            }

            int mid = ((right - left) / 2) + left;
           
            // Update the min value
            result = std::min(result, nums[mid]);

            // if midpoint val  is greater than right val, we serach target is in the right side of
            // the array to the midpoint i.e [mid+1, r] other wise we search in the left part of the array 
            // i.e [l, mid-1]
            if (nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }   
        }
        
        return result;
        
    }
};