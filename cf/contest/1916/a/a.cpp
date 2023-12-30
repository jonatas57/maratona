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
    int n, k;
    cin >> n >> k;
    vi a(n);
    int x = 2023;
    vi ans;
    bool ok = true;
    loop(n) {
      cin >> a[i];
      if (x % a[i]) {
        ok = false;
      }
      else {
        x /= a[i];
      }
    }
    for (int i = 2;i * i <= x;i++) {
      while (x % i == 0) {
        ans.push_back(i);
        x /= i;
      }
    }
    if (x > 1) ans.push_back(x);
    while (ans.size() < k) ans.push_back(1);
    while (ans.size() > k) {
      int y = ans.back();
      ans.pop_back();
      ans.back() *= y;
    }
    if (ok) {
      cout << "YES" << endl;
      each(x, ans) cout << x << " ";
      cout << endl;
    }
    else cout << "NO" << endl;
  }
  return 0;
}

