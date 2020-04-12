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
#define endl               "\n"

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vi a(n + 1), s(n + 1);
	a[0] = s[0] = 0;
	loop(n) {
		cin >> a[i + 1];
		a[i + 1] += a[i];
	}
	loop(n) {
		cin >> s[i + 1];
		s[i + 1] += s[i];
	}
	int l, r;
	loop(q) {
		cin >> l >> r;
		int x = a[r] - a[l - 1], y = s[r] - s[l - 1];
		cout << (x < -y ? "DECREASE" : (x < y ? "INCREASE" : "STABLE")) << endl;
	}
	return 0;
}

