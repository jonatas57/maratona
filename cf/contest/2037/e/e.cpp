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

int ask(int l, int r) {
  cout << "? " << l << " " << r << endl;
  cout.flush();
  int x;
  cin >> x;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    int cnt = ask(1, n);
    string s(n, '0');
    if (!cnt) s = "IMPOSSIBLE";
    else {
      int r = -1;
      for (int i = n - 1;i > 1;i--) {
        int x = ask(1, i);
        if (x != cnt) {
          s[i] = '1';
          if (!x) {
            r = i + 1;
            break;
          }
          cnt = x;
        }
      }
      if (r == -1) {
        s[1] = '1';
      }
      else {
        for (int i = 2;i < r;i++) {
          int x = ask(i, r);
          if (x == cnt) s[i - 2] = '1';
        }
      }
    }
    cout << "! " << s << endl;
    cout.flush();
  }
  return 0;
}
