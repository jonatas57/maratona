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

int main() {
  ios_base::sync_with_stdio(false);

  mii f = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};

  int n, x;
  cin >> n;
  vi cnt(6, 0);
  int rem = 0;
  loop(n) {
    cin >> x;
    int id = f[x];
    if (id) {
      if (cnt[id] < cnt[id - 1]) cnt[id]++;
      else rem++;
    }
    else cnt[id]++;
  }
  x = cnt[5];
  each(y, cnt) rem += (y - x);
  cout << rem << endl;
  return 0;
}
