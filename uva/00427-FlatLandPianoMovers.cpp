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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  while (getline(cin, s)) {
    stringstream ss;
    ss << s;
    int w, h, x, y;
    char t;
    ss >> w >> t >> h;
    if (w < h) swap(w, h);
    string ans = "";
    while (ss >> x >> t >> y) {
      auto f = [&x, &y, &w](double ang) {
        return sin(ang) * x + cos(ang) * y - w * cos(ang) * sin(ang);
      };
      double l = 0, r = acos(-1) / 2;
      while (abs(l - r) > EPS) {
        double del = (r - l) / 3;
        double a = l + del, b = r - del;
        double f1 = f(a), f2 = f(b);
        if (f1 + EPS > f2) l = a;
        if (f1 < EPS + f2) r = b;
      }
      ans += (f(l) + EPS > h ? 'Y' : 'N');
    }
    cout << ans << endl;
  }
  return 0;
}

