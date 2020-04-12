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

int ask(int t, int i, int j, int k) {
	cout << t << " " << i << " " << j << " " << k << endl;
	cout.flush();

	int ans;
	cin >> ans;
	return ans;
}

void answer(vi& p) {
	cout << 0;
	each(x, p) cout << " " << x;
	cout << endl;
	cout.flush();
}

void quick(vi& p, int l, int r) {
	if (l == r) return;
	int pivo = l;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int n;
	cin >> n;
	vi p(n);
	loop(n) p[i] = i + 1;
	shuffle(iter(p), rng);
	quick(p, 0, n - 1);
	return 0;
}

