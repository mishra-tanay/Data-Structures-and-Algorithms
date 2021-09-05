/** Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * Complexity : Medium
 */
class Solution {
public:
    int countSmaller(vector<vector<int>> &arr,int k){
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += upper_bound(arr[i].begin(),arr[i].end(),k)-arr[i].begin();
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long long low = -1e9;
        long long  high = 1e9;
        int ans =0;
        while(low<=high){
            long long int mid = (low+high)/2;
            int smaller_count = countSmaller(matrix,mid);
            if(smaller_count >= k){
                high = mid-1;
                ans = mid;
            } else{
                low = mid+1;
            }
        }
        return ans;
    }
};
