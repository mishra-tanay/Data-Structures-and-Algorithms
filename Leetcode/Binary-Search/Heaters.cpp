class Solution {
public:
    bool canCover(int radius, vector<int> &houses, vector<int>&heaters) {
        int n = houses.size();
        int m = heaters.size();
        vector<bool> covered(n, false);
        int i = 0;
        int j = 0;
        while (j < m) {
            while (i < n && heaters[j] - houses[i] > radius) {
                i++;
            }
            while (i < n && abs(heaters[j] - houses[i]) <= radius) {
                covered[i] = true;
                i++;
            }
            j++;
        }
        return std::all_of(covered.begin(), covered.end(), [](bool b) {return b;});
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long int low = 0;
        long long int high = 1e9;
        long long int ans = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        while (low <= high) {
            long long int mid = (low + high) / 2;
            if (canCover(mid, houses, heaters)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
