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
    vi a(n);
    int x = 0;
    loop(n) {
      cin >> a[i];
      x ^= a[i];
    }
    vector<ii> ans;
    if (n & 1) {
      ans.emplace_back(1, n);
      ans.emplace_back(2, n);
      ans.emplace_back(1, 2);
      ans.emplace_back(1, 2);
    }
    else {
      ans.emplace_back(1, n);
      ans.emplace_back(1, n);
    }
    cout << ans.size() << endl;
    for (auto& [a, b] : ans) cout << a << " " << b << endl;
  }
  return 0;
}

