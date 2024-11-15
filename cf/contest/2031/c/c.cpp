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
    int n;
    cin >> n;
    vi ans(n);
    if (n & 1) {
      if (n < 27) ans.clear();
      else {
        ans[0] = ans[9] = ans[25] = 1;
        ans[22] = ans[26] = 2;
        int next = 3;
        for (int i = 0;i < n - 1;i++) {
          if (ans[i] or ans[i + 1]) continue;
          ans[i] = ans[i + 1] = next++;
          i++;
        }
      }
    }
    else {
      loop(n) ans[i] = i / 2 + 1;
    }
    if (ans.empty()) cout << -1 << endl;
    else {
      each(x, ans) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}

