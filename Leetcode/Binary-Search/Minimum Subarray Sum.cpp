/** Problem link: https://leetcode.com/problems/minimum-size-subarray-sum/
  * Category: Medium
  */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        long long int prefix[n];
        for(int i=0;i<n;i++){
            prefix[i] = nums[i];
            if(i>0){
                prefix[i]+=prefix[i-1];
            }
        }
        int ans = n+1;
        for(int i=0;i<n;i++){
            int low = i;
            int high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                long long int sum = prefix[mid] - (i>0?prefix[i-1]:0);
                if(sum>=target){
                    high = mid-1;
                    ans = min(ans , mid-i+1);
                } else{
                    low = mid+1;
                }
            }
        }
        return ans == n+1 ? 0:ans;
    }
};
