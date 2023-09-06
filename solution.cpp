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

LL f[N];

void upd(int x, int delta) {
	for (int i = x; i < N; i |= i + 1)
		f[i] += delta;
}

LL get(int x) {
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res += f[i];
	return res;
}

LL get(int l, int r) {
	if (l) return get(r) - get(l - 1);
	return get(r);
}

void solve() {
	int n;
	cin >> n;
	vector<LL>a(n);
	for (LL& i : a) {
		cin >> i;
	}
	set<int>st;
	for (int i = 1; i <= n; i++) {
		upd(i, 1);
		st.insert(i);
	}
	
	vector<int>result(n);
	for (int i = n - 1; i > 0; i--) {
		LL difference = i + 1 - (a[i] - a[i - 1]);
		int l = 0, r = n;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (get(mid) >= difference) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		int num = get(r) == difference ? r : l;
		result[i] = num;
		upd(num, -1);
		st.erase(num);
	}
	result[0] = *st.begin();
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
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

