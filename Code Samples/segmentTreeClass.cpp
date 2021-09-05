class SegmentTree {
public:
    SegmentTree(int n) {
        d_n = n;
        d_tree.resize(4 * (n + 1));
        d_base_arr.resize(n + 1);
        constructTree(1, 1, d_n);
    }
    SegmentTree(vector<int> &arr, int n) {
        d_n = n;
        d_tree.resize(4 * (d_n + 1));
        d_base_arr = arr;
        constructTree(1, 1, d_n);
    }

    void constructTree(int curr, int _start, int _end) {
        if (_start == _end) {
            d_tree[curr] = d_base_arr[_start];
            return ;
        }
        int mid = (_start + _end) / 2;
        constructTree(2 * curr, _start, mid);
        constructTree(2 * curr + 1, mid + 1, _end);
        d_tree[curr] = treeFunction(d_tree[2 * curr], d_tree[2 * curr + 1]);
    }
    /** Updates value at index pos of array.
     * Should be called as 'update(1,1,SIZE,pos,val)'
     */
    void update(int curr, int s, int e , int pos , ll val) {
        if (s == e) {
            d_tree[curr] = val;
            return ;
        }
        int mid = (s + e) / 2;
        if (pos <= mid) {
            update(2 * curr, s, mid, pos, val);
        } else {
            update(2 * curr + 1, mid + 1, e, pos, val);
        }
        d_tree[curr] = treeFunction(d_tree[2 * curr], d_tree[2 * curr + 1]);
    }
    /** Returns value from range l to r.
     *  Should be called as query(1,1,SIZE,l,r);
     */
    ll query(int curr, int s, int e, int l, int r) {
        if (r < s || l > e)
            return invalidValue();  // base condition
        if (l <= s && e <= r) {
            return d_tree[curr]; // current segment lies completly inside range segment
        }
        else {
            int mid = (s + e) / 2;
            auto left = query(2 * curr, s, mid, l, r);
            auto right = query(2 * curr + 1, mid + 1, e, l, r);
            return treeFunction(left, right); // return result from both left and right ;
        }
    }
    /**
     * Returns value after merging 'a' and 'b';
     */
    ll treeFunction(int a, int b) {
        return a + b;
    }
    /**Returns invalid value for example
     * INT_MIN when tree stores max value.
     * 0 when tree stores sum.
     * INT_MAX when tree stores min value.
     */
    ll invalidValue() {
        return 0;
    }
    vector<int> d_tree;
    vector<int> d_base_arr;
    int d_n;
};