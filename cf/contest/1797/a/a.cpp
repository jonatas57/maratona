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
    int a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    int cnta = 0, cntb = 0;
    loop(4) {
      int x = a + (i == 0) - (i == 1);
      int y = b + (i == 2) - (i == 3);
      cnta += x <= 0 or x > n or y <= 0 or y > m;
    }
    loop(4) {
      int x = c + (i == 0) - (i == 1);
      int y = d + (i == 2) - (i == 3);
      cntb += x <= 0 or x > n or y <= 0 or y > m;
    }
    cout << 4 - max(cnta, cntb) << endl;
  }
  return 0;
}

