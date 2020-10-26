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

struct box {
  ll x, y, z;
  ll a, b, c;
  box(ll x, ll y, ll z, ll l) : x(x), y(y), z(z), a(x + l), b(y + l), c(z + l) {}
  ll vol() {
    return max(0ll, (a - x) * (b - y) * (c - z));
  }
  void inter(box& bx) {
    x = max(x, bx.x);
    y = max(y, bx.y);
    z = max(z, bx.z);
    a = min(a, bx.a);
    b = min(b, bx.b);
    c = min(c, bx.c);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  while (cin >> n and n) {
    ll x, y, z, l;
    cin >> x >> y >> z >> l;
    box ans(x, y, z, l);
    loop(n - 1) {
      cin >> x >> y >> z >> l;
      box b(x, y, z, l);
      ans.inter(b);
    }
    cout << ans.vol() << endl;
  }
  return 0;
}

