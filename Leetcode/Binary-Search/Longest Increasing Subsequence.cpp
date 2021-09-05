/** Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/submissions/
  * Category: Medium
  */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector < int > lis;
        for(auto it:nums){
            if(lis.empty()){
                lis.push_back(it);
            } else{
                auto lb = lower_bound(lis.begin(),lis.end(),it)-lis.begin();
                if(lb==lis.size()){
                    lis.push_back(it);
                } else{
                    lis[lb]=it;
                }
            }
        }
        return lis.size();
    }
};
