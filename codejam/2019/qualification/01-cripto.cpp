#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

ii divide(int x) {
	for (int i = 2;i * i <= x;i++) {
		if (x % i == 0) return {i, x / i};
	}
	return {-1, -1};
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t, l;
	cin >> t;
	int n;
	loop(t) {
		cin >> n >> l;
		map<int, char> cipher;
		vi msg(l);
		loop(l) cin >> msg[i];
		int x, y;
		tie(x, y) = divide(msg[0]);
		if (msg[1] % x == 0) swap(x, y);
		vi ans;
		cipher[x] = cipher[y] = 0;
		ans.push_back(x);
		ans.push_back(y);
		rep(1, l, 1) {
			y = msg[i] / y;
			ans.push_back(y);
			cipher[y] = 0;
		}
		char c = 'A';
		each(p, cipher) p.second = c++;
		cout << "Case #" << i + 1 << ": ";
		each(x, ans) cout << cipher[x];
		cout << '\n';
	}
	return 0;
}

