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

#define tolower(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define toupper(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define ll long long int
#define pii pair <ll , ll >
#define pb push_back
#define all(s) s.begin(),s.end()
ll gcd(ll a, ll b) { if (a == 0) return b; return b == 0 ? a : gcd(b, a % b);}
#define case(i)
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
#define debug2(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
void err(istream_iterator<string> it, T a, Args... args) { cerr << "[ " << *it << " = " << a << " ]"; err(++it, args...);}
#define time__(d) for (auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); blockTime.second; debug2("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)

/**************************************************************************/
const int x4[] = {1, -1, 0, 0};
const int y4[] = {0, 0, 1, -1};
const int x8[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int y8[] = {1, 0, -1, 1, 0, -1, 1, -1};
/***************************************************************************/
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775800;
const long double PI = 3.141592653589793;
const int PRECISION = 10;
/***************************************************************************/
const int DIGITSIZE = 18;
const int MAXN = 405;
const int LOGN = 22;
const int MAXBIT = 62;
/***************************************************************************/
const bool take_test_case = 0;
const bool print_case_no = 0;
/****************************************************************************/
vector < int> arr;
ll pre[MAXN];
ll dp[MAXN][MAXN];
ll getSum(int i, int j) {
   return pre[j] - (i > 0 ? pre[i - 1] : 0);
}
ll solve(int i, int j) {
   if (i == j) {
      return 0;
   } else if (i + 1 == j) {
      return arr[i] + arr[j];
   } else if (dp[i][j] != -1) {
      return dp[i][j];
   } else {
      dp[i][j] = INF;
      for (int k = i; k < j; k++) {
         dp[i][j] = min(dp[i][j], solve(i, k) + solve(k + 1, j) + getSum(i, j));
      }
   }
   return dp[i][j];
}
void getac(int T) {
   int n;
   cin >> n;
   arr.resize(n);
   memset(dp, -1, sizeof(dp));
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      pre[i] = arr[i];
      if (i != 0) {
         pre[i] += pre[i - 1];
      }
   }
   ll min_ans = solve(0, n - 1);
   cout << min_ans << '\n';
}
int  main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cerr.tie(NULL);
   int test_cases = 1;
   if (take_test_case) cin >> test_cases;
   for (int test_case_no = 1; test_case_no <= test_cases; test_case_no++) {
      if (print_case_no)
         cout << "Case #" << test_case_no << ": ";
      getac(test_case_no);
   }
   cerr << "Total time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
   return 0;
}

