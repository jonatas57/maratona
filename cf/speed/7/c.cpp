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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

vi divs(int x) {
	vi d;
	for (int i = 1;i * i <= x;i++) {
		if (x % i == 0) {
			d.push_back(i);
			d.push_back(x / i);
		}
	}
	sort(iter(d));
	return d;
}

int mdc(int a, int b) {
	return (a ? mdc(b, b % a) : b);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b, n, l, h;
	cin >> a >> b >> n;
	auto d = divs(gcd(a, b));
	loop(n) {
		cin >> l >> h;
		auto it = lower_bound(iter(d), h);
		if (it == d.end() || *it != h) {
			it--;
		}
		cout << (*it >= l ? *it : -1) << endl;
	}
	return 0;
}
