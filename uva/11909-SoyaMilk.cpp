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
const double EPS = 1e-8;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int l, w, h, t;
  while (cin >> l >> w >> h >> t) {
    int tot = l * w * h;
    double height = l * tan(t / 180.0 * acos(-1.0));
    double vol = w * l * height / 2;
    if (height > EPS + h) {
      double r = (height - h) / height;
      vol *= 1.0 - r * r;
    }
    cout << fixed << setprecision(3) << tot - vol << " mL" << endl;
  }
  return 0;
}

