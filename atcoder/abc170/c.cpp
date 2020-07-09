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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int x, n;
	cin >> x >> n;
	vi a(n);
	loop(n) cin >> a[i];
	sort(iter(a));
	int p = lower_bound(iter(a), x) - a.begin();
	int b = x, c = x;
	if (n) for (int i = p;i >= 0 and a[i] == b;i--, b--); 
	for (int i = p;i < n and a[i] == c;i++, c++);
	cout << (abs(x - b) <= abs(x - c) ? b : c) << endl;
	return 0;
}

