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
    vector<ii> a(n);
    loop(n) cin >> a[i].first, a[i].second = i;
    sort(riter(a));
    vi ans(n);
    vb used(n);
    int lnu = n - 1;
    int top, toppos = INF;
    for (auto& [x, p] : a) {
      while (lnu and used[lnu]) lnu--;
      if (lnu < toppos) {
        ans[p] = x;
        top = x;
        toppos = p;
      }
      else {
        ans[p] = top;
        toppos = min(p, toppos);
      }
      used[p] = true;
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

