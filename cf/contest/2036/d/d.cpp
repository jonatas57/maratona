#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    vector<string> ss(n);
    loop(n) cin >> ss[i];
    vector<string> ls;
    int x = min(n, m) / 2;
    loop(x) {
      ls.emplace_back();
      for (int j = i;j < m - i;j++) ls[i] += ss[i][j];
      for (int k = i + 1;k < n - i;k++) ls[i] += ss[k][m - i - 1];
      for (int j = m - i - 2;j >= i;j--) ls[i] += ss[n - i - 1][j];
      for (int k = n - i - 2;k > i;k--) ls[i] += ss[k][i];
      ls[i] += ls[i].substr(0, 3);
    }
    int cnt = 0;
    each(s, ls) {
      int p = 0;
      while (true) {
        size_t p2 = s.find("1543", p);
        if (p2 == string::npos) break;
        cnt++;
        p = p2 + 4;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

