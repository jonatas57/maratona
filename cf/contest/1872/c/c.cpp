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
    int l, r;
    cin >> l >> r;
    int p = l == r ? r : r - (r & 1);
    int d = p;
    for (int i = 2;i * i <= p;i++) {
      if (p % i == 0) {
        d = i;
        break;
      }
    }
    if (p / d <= 1) cout << -1 << endl;
    else cout << d << " " << p - d << endl;
  }
  return 0;
}

