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
    int n;
    cin >> n;
    int iv = 0, maxrem = 0;
    vi a(n + 2);
    vb hv(n + 2, false);
    loop(n) cin >> a[i + 1];
    a[0] = a[1];
    a[n + 1] = a[n];
    for (int i = 1;i <= n;i++) {
      if (a[i] == a[i - 1] or a[i] == a[i + 1]) continue;
      if ((a[i] < a[i - 1]) == (a[i] < a[i + 1])) iv++, hv[i] = true;
    }
    for (int i = 2;i < n;i++) {
      int rem = 0;
      set<int> s;
      s.insert(a[i - 1]);
      s.insert(a[i + 1]);
      each(x, s) {
        vb hv2(3, false);
        int y = a[i];
        int r = 0;
        a[i] = x;
        for (int j = -1;j <= 1;j++) {
          if (a[i + j] == a[i + j - 1] or a[i + j] == a[i + j + 1]) ;
          else if ((a[i + j] < a[i + j - 1]) == (a[i + j] < a[i + j + 1])) hv2[j + 1] = true;
          r += (int)hv[i + j] - (int)hv2[j + 1];
        }
        a[i] = y;
        rem = max(rem, r);
      }
      maxrem = max(rem, maxrem);
    }
    cout << iv - maxrem << endl;
  }
  return 0;
}

