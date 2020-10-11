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

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
  bool operator!=(point& p) {
    return abs(x) != abs(p.x) or abs(y) != abs(p.y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    int x, y;
    vector<point> pin, hol[4];
    loop(n) {
      cin >> x >> y;
      pin.emplace_back(x, y);
    }
    loop(n) {
      cin >> x >> y;
      loop(2) hol[i].emplace_back(x * (i ? -1 : 1), y * (i ? -1 : 1));
      loop(2) hol[2 + i].emplace_back(y * (i ? 1 : -1), x * (i ? -1 : 1));
    }
    sort(iter(pin));
    bool ans = false;
    for (int i = 0;i < 4 and !ans;i++) {
      sort(iter(hol[i]));
      bool ok = true;
      for (int j = 1;ok and j < n;j++) {
        point del1 = pin[j] - pin[j - 1];
        point del2 = hol[i][j] - hol[i][j - 1];
        if (del1 != del2) ok = false;
      }
      ans |= ok;
    }
    cout << (ans ? "MATCHED" : "NOT MATCHED") << endl;
  }
  return 0;
}

