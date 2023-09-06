#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <iterator>
#include <string.h>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <fstream>
#include <assert.h>
#include <numeric>
#include <complex>

#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin() , x.end()
#define ff first
#define ss second
#define SZ(a) (int)a.size()
#define pii pair<int , int>
#define rall(x) x.rbegin() , x.rend()
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);srand(time(NULL));
#define debug(a) cout << #a << " = " << a << endl;
#define files freopen("bacon.in", "r", stdin);freopen("bacon.out", "w", stdout);
#define FILL(a, value) memset(a, value, sizeof(a))
#define make_unique(a) a.erase(unique (a.begin(), a.end()), a.end());
#define fff cout << "--------------------------" << endl;

using namespace std;
const LL MOD = 1e9 + 7;
const int LOG = 30;
const LL INF = 1e18;
const double PI = acos(-1);
const double EPS = 1e-9;
const int N = 3e5 + 500;
const int inf = 1e9;
const int SQRT = 448;
const int pr = 91;

void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1);
	map<int, vector<int>>cnt;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]].pb(i);
	}
	LL ans = 0;
	for (auto& it : cnt) {
		LL curSum = 0;
		for (int i = 0; i < SZ(it.ss); i++) {
			curSum += it.ss[i];
		}
		for (int i = 0; i < SZ(it.ss); i++) {
			curSum -= it.ss[i];
			int left = SZ(it.ss) - i - 1;
			ans += (curSum - left * 1LL * it.ss[i]) - left * 1LL * (left + 1) / 2;
		}
	}
	cout << ans << endl;
}

int main() {
	//files
	fast
	int tt = 1;
	//cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
