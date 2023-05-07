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
    vi ts(4, INF);
    loop(n) {
      int k;
      string s;
      cin >> k >> s;
      int p = (s[0] - '0') * 2 + (s[1] - '0');
      ts[p] = min(ts[p], k);
    }
    int ans = min(ts[1] + ts[2], ts[3]);
    cout << (ans >= INF ? -1 : ans) << endl;
  }
  return 0;
}

