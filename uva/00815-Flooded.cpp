#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  for (int t = 1;cin >> n >> m and n | m;t++) {
    vi a(n * m);
    loop(n * m) cin >> a[i];
    sort(iter(a));
    ll tot;
    cin >> tot;
    double h = a[0];
    int qtd = 1;
    for (int i = 1;i < n * m;i++) {
      while (a[i] == a[i - 1]) i++;
      if (i >= n * m) break;
      ll mx = 100 * (a[i] - a[i - 1]) * i;
      if (tot < mx) {
        break;
      }
      h = a[i];
      qtd = i + 1;
      tot -= mx;
    }
    while (a[qtd] == a[qtd - 1]) qtd++;
    h += tot / (100.0 * qtd);
    double p = 100.0 * qtd / (n * m);
    cout << "Region " << t << endl;
    cout << "Water level is " << fixed << setprecision(2) << h << " meters." << endl;
    cout << fixed << setprecision(2) << p << " percent of the region is under water." << endl << endl;
  }
  return 0;
}

