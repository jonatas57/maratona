#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

pair<ll, bool> getFloor(string& s) {
	bool neg = false, dec = false, db = false;
	ll x = 0;
	each(c, s) {
		if (c == '-') neg = true;
		else if (c == '.') dec = true;
		else if (dec) {
			if (c != '0') db = true;
		}
		else {
			x *= 10;
			x += c - '0';
		}
	}
	if (neg) {
		x = -x;
		if (db) x--;
	}
	return {x, db};
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	ll sum = 0;
	vector<ll> a(n);
	vb db(n);
	loop(n) {
		string s;
		cin >> s;
		bool b;
		tie(a[i], b) = getFloor(s);
		db[i] = b;
		sum += a[i];
	}
	for (int i = 0, j = 0;i < n and j < abs(sum);i++) {
		if (db[i]) a[i]++, j++;
	}
	each(x, a) cout << x << endl;
	return 0;
}

