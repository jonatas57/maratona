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

  int t;
  cin >> t;
  loop(t) {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    ll del = min(n, a - x);
    ll a1 = a - del;
    ll b1 = b - min(n - del, b - y);

    ll del2 = min(n, b - y);
    ll b2 = b - del2;
    ll a2 = a - min(n - del2, a - x);

    cout << min(a1 * b1, a2 * b2) << endl;
  }
	return 0;
}

