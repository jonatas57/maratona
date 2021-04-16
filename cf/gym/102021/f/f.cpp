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

  vi fib(2, 1);
  int sz = 2;
  mii ord;
  ord[1] = 1;
  while (fib.back() < 1e6) {
    fib.push_back(fib[sz - 1] + fib[sz - 2]);
    ord[fib.back()] = sz++;
  }

  int n;
  cin >> n;
  vector<ii> a;
  int aux;
  loop(n) {
    cin >> aux;
    if (ord.count(aux)) a.emplace_back(aux, i + 1);
  }
  sort(iter(a));
  int x = -1, y;
  int m = a.size();
  loop(m - 1) {
    if (ord.count(a[i].first) and ord.count(a[i + 1].first)) {
      int p = a[i].first, q = a[i + 1].first;
      if ((p == 1 and q == 1) or ord[q] - ord[p] == 1) {
        x = a[i].second;
        y = a[i + 1].second;
        break;
      }
    }
  }
  if (x == -1) cout << "impossible" << endl;
  else cout << x << " " << y << endl;
  return 0;
}

