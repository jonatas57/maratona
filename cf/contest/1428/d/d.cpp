#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vi a(n);
  loop(n) cin >> a[i];
  vector<ii> ans;
  bool pos = true;
  int linempty = n;
  priority_queue<ii> one, two;
  for (int i = n - 1;pos and i >= 0;i--) {
    if (a[i] == 1) {
      ans.emplace_back(linempty, i + 1);
      one.emplace(linempty--, i + 1);
    }
    if (a[i] == 2) {
      if (one.empty()) pos = false;
      else {
        int x = one.top().first;
        one.pop();
        ans.emplace_back(x, i + 1);
        two.emplace(x, i + 1);
      }
    }
    if (a[i] == 3) {
      int x;
      if (two.empty()) {
        if (one.empty()) pos = false;
        else x = one.top().second, one.pop();
      }
      else x = two.top().second, two.pop();
      ans.emplace_back(linempty, i + 1);
      ans.emplace_back(linempty, x);
      two.emplace(linempty--, i + 1);
    }
  }
  if (pos) {
    cout << ans.size() << endl;
    for (auto [x, y] : ans) cout << x << " " << y << endl;
  }
  else cout << -1 << endl;
  return 0;
}

