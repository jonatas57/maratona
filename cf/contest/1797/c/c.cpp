#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

int ask(int r, int c) {
  cout << "? " << r << " " << c << endl;
  cout.flush();
  int x;
  cin >> x;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    set<int> rs, cs;
    int x = ask(1, 1);
    rs.insert(1 + x);
    cs.insert(1 + x);
    int y = ask(n, 1);
    rs.insert(n - y);
    cs.insert(1 + y);
    if (rs.size() == 1) {
      int r = *rs.begin();
      int z = ask(r, 1);
      cout << "! " << r << " " << z + 1 << endl;
    }
    else if (cs.size() == 1) {
      int c = *cs.begin();
      int z = ask(1, c);
      cout << "! " << z + 1 << " " << c << endl;
    }
    else {
      int z = ask(n, m);
      rs.insert(n - z);
      cs.insert(m - z);
      bool ok = false;
      each(r, rs) {
        if (ok) break;
        each(c, cs) {
          int a = max(r - 1, c - 1);
          int b = max(n - r, c - 1);
          int d = max(n - r, m - c);
          if (a == x and b == y and d == z) {
            cout << "! " << r << " " << c << endl;
            ok = true;
            break;
          }
        }
      }
    }
    cout.flush();
  }
  return 0;
}

