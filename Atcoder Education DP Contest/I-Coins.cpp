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
const int MAXN = 100001;
const int LOGN = 22;
const int MAXBIT = 62;
/***************************************************************************/
const bool take_test_case = 0;
const bool print_case_no = 0;
/****************************************************************************/
double dp[3000][3000];
double arr[3000];
int min1;
void solve(int n) {

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
			}
			else if (i == 0 && j != 0) {
				dp[i][j] = 0;
			} else if (i != 0 && j == 0) {
				dp[i][j] = dp[i - 1][j] * (1 - arr[i - 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j] * (1 - arr[i - 1]) + dp[i - 1][j - 1] * arr[i - 1];
			}
		}
	}
}
void getac(int T) {
	int n ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(n);

	int x = n / 2;
	x = n - n / 2;
	double ans = 0;
	for (int i = x; i <= n; i++) {
		ans += dp[n][i];
	}
	cout << fixed << setprecision(9) << ans;
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
