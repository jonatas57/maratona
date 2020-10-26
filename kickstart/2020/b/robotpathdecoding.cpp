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

const ll mod = 1000000000;

void norm(ll& x) {
	if (x < 0 or x >= mod) {
		x = (x % mod + mod) % mod;
	}
}

pair<ll, ll> solve(string& s, int& pos) {
	ll x = 0, y = 0;
	for (;s[pos];pos++) {
		if (isdigit(s[pos])) {
			ll t = s[pos] - '0', dx, dy;
			pos += 2;
			tie(dx, dy) = solve(s, pos);
			x += dx * t;
			y += dy * t;
		}
		else if (isalpha(s[pos])) {
			x += (s[pos] == 'E') - (s[pos] == 'W');
			y += (s[pos] == 'S') - (s[pos] == 'N');
		}
		else if (s[pos] == ')') {
			return make_pair(x, y);
		}
		norm(x);
		norm(y);
	}
	return make_pair(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		string s;
		cin >> s;
		ll x, y;
		int pos = 0;
		tie(x, y) = solve(s, pos);
		x++, y++;
		if (x > 1000000000) x -= 1000000000;
		if (y > 1000000000) y -= 1000000000;
		cout << "Case #" << i + 1 << ": " << x << " " << y << endl;
	}
	return 0;
}

