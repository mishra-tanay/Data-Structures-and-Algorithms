/** Problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/
  * Category : Hard
  */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        // Always have first array to be smaller in length than second array.
        int n = nums1.size() + nums2.size();
        int mid = (n + 1) / 2;
        int lo = 0, hi = nums1.size();
        int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;
        /**
          > In the end we need to find this scenario where.
          > arr1[0.....split1] arr1[split_1 + 1 .... arr1.length()-1]
          > arr2[0.....split2] arr2[split_2+1.....arr2.length()-1]
          > split1 + split2 = mid;
          > if (left1 <= right2 && left2 <= right1)  holds true.
         */
        while (true) {
            int split1 = lo + (hi - lo) / 2;
            int split2 = mid - split1;
            left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;
            if (split1 > 0) left1 = nums1[split1 - 1];
            if (split2 > 0) left2 = nums2[split2 - 1];
            if (split1 < nums1.size()) right1 = nums1[split1];
            if (split2 < nums2.size()) right2 = nums2[split2];
            if (left1 <= right2 && left2 <= right1) break;
            if (left1 > right2) hi = split1 - 1;
            else if (left2 > right1) lo = split1 + 1;
        }
        double result = 0;
        if (n % 2 == 0) {
            double l = (double)max(left1, left2);
            double r = (double)min(right1, right2);
            result = (double)((l + r) / 2);
        } else{
        result = (double)max(left1, left2);
        }
        return result;
    }
};

