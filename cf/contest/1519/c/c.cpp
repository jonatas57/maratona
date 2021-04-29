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
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi us(n);
    loop(n) cin >> us[i];
    vector<vector<ll>> sum(n, vector<ll>(1, 0));
    vector<ll> ans(n, 0);
    loop(n) {
      ll s;
      cin >> s;
      sum[us[i] - 1].push_back(s);
    }
    loop(n) {
      int sz = sum[i].size() - 1;
      if (sz == 0) continue;
      sort(sum[i].rbegin(), sum[i].rend() - 1);
      for (int j = 1;j <= sz;j++) {
        sum[i][j] += sum[i][j - 1];
      }
      for (int k = 1;k <= sz;k++) {
        ans[k - 1] += sum[i][sz - (sz % k)];
      }
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

