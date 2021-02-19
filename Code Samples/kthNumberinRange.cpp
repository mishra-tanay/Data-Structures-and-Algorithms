#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#pragma GCC optimize ("-O3")
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define tolower(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define toupper(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define ll long long int
ll max(ll a, ll b) {  return a > b ? a : b; }
ll gcd(ll a, ll b) { if (a == 0) return b; return b == 0 ? a : gcd(b, a % b);}
#define case(i) cout<<"Case #"<<i<<": ";
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << "[ " << *it << " = " << a << " ]"; err(++it, args...);}
#define pii pair <ll , ll >
#define pb push_back
#define PRECISION 10
const ll inf = 1e16;
const int MAXN = 100001;
const int LOGN = 22;
const int MAXBIT = 61;
const int DIGITSIZE = 19;
ll mod = 1e9 + 7;
ll MOD = 998244353;
int x4[] = {1, -1, 0, 0};
int y4[] = {0, 0, 1, -1};
bool take_test_cases = 0;
bool print_case_no = 0;
struct node {
    ll val;
    node *left;
    node *right;
    node() {
        val = 0 ;
        left = NULL;
        right = NULL;
    }
};
ll temp[MAXN];
ll arr[MAXN];
node *segvers[MAXN];
ll pos[MAXN];
ll posinv[MAXN];
void build(node* curr, int s, int e) {
    if (s == e) {
        return ;
    }
    int mid = (s + e) / 2;
    curr->left = new node();
    curr->right = new node();
    build(curr->left, s, mid);
    build(curr->right, mid + 1, e);
}
void update(node* prev, node* curr, int s, int e , int ind , ll val) {
    if (e < ind || s > ind) {
        return ;
    }
    if (s == e) {
        curr->val = val;
        return ;
    }
    int mid = (s + e) / 2;
    if (ind <= mid) {
        curr->right = prev->right;
        curr->left = new node();
        update(prev->left, curr->left, s, mid, ind, val);
    }
    else {
        curr->left = prev->left;
        curr->right = new node();
        update(prev->right , curr->right, mid + 1, e, ind, val);
    }

    curr->val = curr->left->val + curr->right->val ;
}

ll query(node* prev, node *curr, int s, int e , ll k) {
    if (s == e) {
        return s;
    }
    int mid = (s + e) / 2;
    if (curr->left->val - prev->left->val >= k) {
        return query(prev->left, curr->left, s, mid, k);
    } else {
        return query(prev->right, curr->right, mid + 1, e, k - (curr->left->val - prev->left->val));
    }
}
void getac(int T) {
    int n;
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(temp, temp + n);
    for (int i = 0; i < n; i++) {
        pos[i] = lower_bound(temp, temp + n, arr[i]) - temp;
        posinv[pos[i]] = arr[i];
    }
    segvers[0] = new node();
    build(segvers[0], 0, n - 1);
    for (int i = 0; i < n; i++) {
        segvers[i + 1] = new node();
        update(segvers[i], segvers[i + 1], 0, n - 1, pos[i], 1);
    }
    while (q--) {
        int l , r , k;
        cin >> l >> r >> k;
        cout << posinv[query(segvers[l - 1], segvers[r], 0, n - 1, k)] << '\n';
    }
}
int  main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    fastio;
    int t = 1;
    if (take_test_cases) cin >> t;
    int t_t = 1;
    while (t--) {
        if (print_case_no)
        case (t_t);
        getac(t_t);
        t_t++;
    }
    return 0;
}