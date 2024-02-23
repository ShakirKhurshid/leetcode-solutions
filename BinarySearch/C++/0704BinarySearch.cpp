/*
  Time: O(logn)
  Space: O(1)
*/

class Solution{
public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    // Search till search space exhausted
    while (l <= r){
      // Find the midpoint of the array
      int m = ((r - l) / 2) + l;
      if(target < nums[m]){
        r = m - 1;
      } else if(target > nums[m]){
        l = m + 1;
      } else{
        return m;
      }
    }
    return -1;   
  }
}
