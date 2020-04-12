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

vi fats(int x) {
	vi fs;
	for (int i = 2;i * i <= x;i++) {
		if (x % i == 0) {
			fs.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) fs.push_back(x);
	return fs;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k, x;
	cin >> n >> k;
	vb c(1e6 + 1, false);
	bool p = true;
	loop(n) {
		cin >> x;
		vi xs = fats(x);
		each(y, xs) c[y] = true;
	}
	auto fs = fats(k);
	each(f, fs) {
		if (!c[f]) p = false;
	}
	cout << (p? "Yes" : "No") << endl;
	return 0;
}

