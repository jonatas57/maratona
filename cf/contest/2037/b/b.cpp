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
    int k;
    cin >> k;
    map<int, int> cnt;
    loop(k) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int x = k - 2;
    int n, m;
    for (int i = 1;i * i <= x;i++) {
      if (x % i == 0) {
        n = x / i;
        m = i;
        if (cnt.count(n) and cnt.count(m) and (n != m or cnt[n] >= 2)) {
          break;
        }
      }
    }
    cout << n << " " << m << endl;
  }
  return 0;
}

