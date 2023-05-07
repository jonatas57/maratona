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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    q.push(n);
    bool ok = false;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      if (x == m) {
        ok = true;
        break;
      }
      if (x % 3) continue;
      int y = x / 3;
      q.push(y);
      q.push(y << 1);
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

