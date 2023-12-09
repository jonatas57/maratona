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
    vector<pair<ll, int>> a(n);
    loop(n) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(iter(a));
    vector<ll> acc(n, a[0].first);
    loop(n - 1) acc[i + 1] = acc[i] + a[i + 1].first;
    vi ans(n);
    for (int i = 0, j = 0;i < n;i++) {
      j = max(j, i);
      while (j < n - 1 and acc[j] >= a[j + 1].first) j++;
      ans[a[i].second] = j;
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

