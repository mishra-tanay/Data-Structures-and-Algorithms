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
#define case(i) cout<<"Case #"<<i<<": ";
#define pii pair <ll , ll >
#define pb push_back
#define PRECISION 10
const ll inf = 1e16;
const int MAXN = 100005;
const int LOGN = 22;
const int MAXBIT = 21;
const ll DIGITSIZE = 19;
ll max(ll a, ll b) {
    return a > b ? a : b;
}
ll mod = 1e9 + 7;
ll MOD = 998244353;
int x4[] = {1, -1, 0, 0};
int y4[] = {0, 0, 1, -1};
int n;
ll subtree_size[MAXN];
ll chain[MAXN];
ll chainHead[MAXN];
ll position[MAXN];
ll level[MAXN];
ll U[MAXN];
ll V[MAXN];
vector < int > parent[MAXN];
ll segtree[4 * MAXN];
ll arr[MAXN]; // will hold values from 1 to n-1 ;
ll chainId = 0;
int pos = 0;
vector < vector < pair < int , int > > > adj;
void dfs_subtree(int v, int par , int l) {
    parent[v][0] = par;
    for (int i = 1; i <= LOGN; i++) {
        if (parent[v][i - 1] != 0) {
            parent[v][i] = parent[parent[v][i - 1]][i - 1];
        }
    }
    subtree_size[v] += 1;
    level[v] = l;
    int i = 0;
    for (auto it : adj[v]) {
        int to = it.first;
        if (to != par) {
            dfs_subtree(to, v, l + 1);
            subtree_size[v] += subtree_size[to];
        }
    }
    return ;
}
void dfs_hld(int v , int par) {
    int heavyChild = -1;
    int heavySize = 0;
    int heavyEdgeWeight = -1;
    chain[v] = chainId;
    position[v] = pos++;
    for ( auto it : adj[v]) {
        int to = it.first;
        if (to != par) {
            if (subtree_size[to] > heavySize)
            {
                heavySize = subtree_size[to];
                heavyChild = to;
                heavyEdgeWeight = it.second;
            }
        }
    }
    if (heavyChild != -1) {
        arr[pos] = heavyEdgeWeight;
        dfs_hld(heavyChild, v);
    }

    for (auto it : adj[v]) {
        int to = it.first;
        int cost = it.second;
        if ( to != par && to != heavyChild) {
            chainId++;
            chainHead[chainId] = to;
            arr[pos] = cost;
            dfs_hld(to, v);
        }
    }
    return ;
}
void build(int curr, int s, int e) {
    if (s == e) {
        // node* a=getnode();
        segtree[curr] = s;
        return ;
    }
    int mid = (s + e) / 2;
    build(2 * curr, s, mid);
    build(2 * curr + 1, mid + 1, e);
    segtree[curr] = // segtree[2*curr], segtree[2*curr+1];
        return ;
}


ll query(int curr, int qs, int qe, int s, int e, int val) {
    if (qe < s || qs > e)
        return 0;  // base condition
    if (qs <= s && e <= qe) {
        return segtree[curr]; // current segment lies completly inside range segment
    }
    else {
        int mid = (s + e) / 2;
        return max(query(2 * curr, qs, qe, s, mid, val), query(2 * curr + 1, qs, qe, mid + 1, e, val)); // return result from both left and right ;
    }
}
ll get_query(int l, int r, int val)
{
    if (l > r) {
        return 0;
    }
    return query(1, l , r , 0, n - 1 , val);
}
// void update_query(int idx, int val)
// {
//     update(1, 0, n - 1, idx, val);
//     return ;
// }
ll query_up(int from , int to, int val) {
    int curr = from;
    ll ans = 0;
    if (from == to)return 0;
    while (chain[curr] != chain[to]) {

        int currHead = chainHead[chain[curr]];
        int l = position[currHead];
        int r = position[curr];
        ans = max(ans, get_query(l, r, val));
        curr = parent[currHead][0];
    }
    ans = max(ans, get_query(position[to] + 1, position[curr], val));
    return ans;
}
int get_lca(int u , int v) {
    if (level[u] > level[v]) {
        swap(u, v);
    }
    int diff = level[v] - level[u];
    for (int i = LOGN - 1; i >= 0 ; i-- ) {
        if ((diff & (1 << i)) != 0) {
            v = parent[v][i];
        }
    }
    if (u == v) {
        return v;
    }
    for (int i = LOGN - 1; i >= 0; i--) {
        int pu = parent[u][i];
        int pv = parent[v][i];
        if (pu != pv) {
            u = pu;
            v = pv;
        }
    }
    return parent[u][0];
}

void initialise(int n) {
    adj.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i <= n; i++) {
        parent[i].clear();
        parent[i].resize(LOGN + 1, 0);
        subtree_size[i] = 0;
        chain[i] = 0;
        chainHead[i] = 0;
        position[i] = 0;
        chainId = 0;
        level[i] = 0;
        U[i] = 0;
        V[i] = 0;
        pos = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        U[i] = x;
        V[i] = y;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    dfs_subtree(1, 0, 0);
    chainHead[0] = 1;
    dfs_hld(1, 0);
    build(1, 0, n - 1);

}
void getac(int T) {
    cin >> n;
    int q;
    cin >> q;

    initialise(n);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int lca = get_lca(x, y);
        int ans1 = query_up(x, lca, z);
        int ans2 = query_up(y, lca, z);
        cout << max(ans1, ans2) << '\n';
    }
    return ;
}
int  main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;


    int t = 1;
    //cin >> t;
    int t_t = 1;
    while (t--) {

        getac(t_t);
        t_t++;
    }
    return 0;
}