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
    int n;
    cin >> n;
    int p1, p2, pn;
    loop(n) {
      int x;
      cin >> x;
      if (x == 1) p1 = i + 1;
      else if (x == 2) p2 = i + 1;
      else if (x == n) pn = i + 1;
    }
    vi a = {p1, p2, pn};
    sort(iter(a));
    if (a[1] == pn) cout << "1 1" << endl;
    else cout << pn << " " << a[1] << endl;
  }
  return 0;
}

