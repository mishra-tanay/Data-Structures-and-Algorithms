class Solution {
public:
    string smallestGoodBase(string n) {
	   long long int smallest_good_base = n;
	   for(int len = 63;len >=1; len--){
	        long long int low = 1;
		long long int high = n;
		while(low <= high){
			long long int mid = (low+high)/2;
			bool exceeded{false};
			long long int curr = 1;
			long long int num = 0;
			for(int j=0;j<=len;j++){
				num += curr;
				curr*= mid;
				if(num > n){
					exceeded = true;
					break;
				}
			}
			if(num == n){
				smallest_good_base = mid;
				high = mid-1;
			} else if(exceeded){
				high = mid-1;
			} else{
				low = mid+1;
			}
		}
			
	   } 
         return smallest_good_base;
    }
};
