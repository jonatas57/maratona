#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

auto divs(ll n) {
  int x = 0;
  vi d = {2, 3, 5};
  for (int i = 0;i <= 2;) {
    if (n % d[i] == 0) {
      x++;
      n -= n / d[i];
      i = 0;
    }
    else i++;
  }
  return make_pair(x, n == 1);
}

int main() {
  ios_base::sync_with_stdio(false);

  int q;
  ll n;
  cin >> q;
  loop(q) {
    cin >> n;
    auto x = divs(n);
    cout << (x.second ? x.first : -1) << endl;
  }
  return 0;
}
