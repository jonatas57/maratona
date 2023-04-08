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
    int n, k;
    cin >> n >> k;
    vector<vi> p(n);
    int x;
    loop(n) {
      vloop(j, n) {
        cin >> x;
        p[i].push_back(x);
      }
    }
    int cnt = k;
    for (int i = 0, i2 = n - 1;i <= i2;i++, i2--) {
      for (int j = 0, j2 = n - 1;i < i2 ? j < n : j < j2;j++, j2--) {
        if (p[i][j] != p[i2][j2]) cnt--;
      }
    }
    cout << ((n & 1 or cnt % 2 == 0) and cnt >= 0 ? "YES" : "NO") << endl;
  }
  return 0;
}

