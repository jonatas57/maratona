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
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    int fpa = 0, fpb = 0;
    loop(n) {
      cin >> a[i];
      if (a[i] < 0) fpa++;
    }
    loop(m) {
      cin >> b[i];
      if (b[i] < 0) fpb++;
    }
    vi ok;
    for (int i = 0, j = 0;i < n and j < m;) {
      if (a[i] < b[j]) i++;
      else if (a[i] > b[j]) j++;
      else {
        ok.push_back(a[i]);
        i++;
        j++;
      }
    }
    int ml = 0, mr = 0;
    for (int at = 0, bp = fpb, bpr = fpb, ap = fpa, nbox = 0, nplc = 0;bp < m;bp++) {
      at = b[bp] - 1;
      while (ap < n and a[ap] <= at + nbox) nbox++, ap++;
      while (bpr < m and b[bpr] <= at + nbox) nplc++, bpr++;
      int aok = ok.end() - lower_bound(iter(ok), at + nbox + 1);
      ml = max(nplc + aok, ml);
      nplc--;
    }
    for (int at = 0, bp = fpb - 1, bpl = fpb - 1, ap = fpa - 1, nbox = 0, nplc = 0;bp >= 0;bp--) {
      at = b[bp] + 1;
      while (ap >= 0 and a[ap] >= at - nbox) nbox++, ap--;
      while (bpl >= 0 and b[bpl] >= at - nbox) nplc++, bpl--;
      int aok = lower_bound(iter(ok), at - nbox) - ok.begin();
      mr = max(nplc + aok, mr);
      nplc--;
    }
    cout << ml + mr << endl;
  }
  return 0;
}

