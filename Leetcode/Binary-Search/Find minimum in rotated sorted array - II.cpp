/** Problem link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * Category : Hard
 */

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n= arr.size();
        int low = 0;
        int high = n-1;
        if(arr[low] < arr[high]){
            return arr[low];
        }
        int ans = arr[low];
        while(low<=high){
            int mid = (low+high)/2;
            ans = min(ans,arr[mid]);
            if(arr[mid] > arr[high]){
                low = mid+1;
            } else if(arr[mid] < arr[high]){
                high = mid-1;
            } else{
                high--;
            }
        }
        return ans;
    }
};
