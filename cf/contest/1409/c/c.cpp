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
    int n, x, y;
    cin >> n >> x >> y;
    int del = y - x;
    int r = INF, st = INF;
    for (int i = 1;i <= del;i++) {
      if (del % i == 0) {
        int ns = del / i;
        int rs = y % ns;
        if (!rs) rs = ns;
        int qtd = max(n - 1, y / ns - (rs == ns));
        int nr = qtd * ns + rs;
        if (nr < r and (qtd - n + 1) * ns + rs <= x) {
          r = nr;
          st = ns;
        }
      }
    }
    for (int i = 0, x = r;i < n;i++, x -= st) cout << x << " ";
    cout << endl;
  }
	return 0;
}

