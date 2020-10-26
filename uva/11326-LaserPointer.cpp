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

  int t;
  cin >> t;
  loop(t) {
    int l, w, th;
    cin >> l >> w >> th;
    if (!th) {
      cout << "1.000" << endl;
      continue;
    }
    double x = w / sin(th * acos(-1) / 180);
    double st = w / tan(th * acos(-1) / 180);
    double qtd = l / st;
    double a = qtd * x;
    int q = qtd + EPS;
    qtd -= q;
    double y = q & 1 ? w * (1 - qtd) : w * qtd;
    double b = sqrt(l * l + y * y);
    cout << fixed << setprecision(3) << a / b << endl;
  }
  return 0;
}

