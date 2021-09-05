/** Problem Link : https://leetcode.com/problems/find-peak-element/
 *  Category : Medium 
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while(low<=high){
            int mid  = (low+high)/2;
            long long int left_bound = -1e10;
            long long int right_bound = -1e10;
            if(mid-1>=0){
                left_bound = nums[mid-1];
            }
            if(mid+1 < n){
                right_bound = nums[mid+1];
            }
            long long int curr = nums[mid];
            if(curr>left_bound && curr > right_bound){
                return mid;
            }
            else if(curr > left_bound){
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        return -1;
    }
};
