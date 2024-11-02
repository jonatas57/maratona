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
    int n, k;
    cin >> n >> k;
    int l = k - 1, r = n - k;
    if (n == 1) cout << 1 << endl << 1 << endl;
    else if (k == 1 or k == n) cout << -1 << endl;
    else {
      int x = min(k - 2, n - k - 1);
      cerr << x << endl;
      cout << 3 << endl << 1 << " " << k - x << " " << k + x + 1 << endl;
    }
  }
  return 0;
}

