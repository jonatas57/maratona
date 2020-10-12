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

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  ll operator*(point& p) {
    return x * p.y - y * p.x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<point> ps(n);
    loop(n) cin >> ps[i].x >> ps[i].y;
    ps.push_back(ps[0]);
    double vol = 0;
    loop(n) vol += ps[i] * ps[i + 1];
    ll w;
    cin >> w;
    vol *= w;
    vol /= 2.0;
    double per, cons, rec;
    cin >> per >> cons >> rec;
    double tot = vol * per / 100;
    if (cons > EPS + tot) cout << "Lack of water. ";
    tot = max(0.0, tot - cons);
    if (tot + rec > EPS + vol) cout << "Excess of water. ";
    tot = min(vol, tot + rec);
    int final = tot / vol * 100;
    cout << "Final percentage: " << final << "%" << endl;
  }
  return 0;
}

