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
    int n, m;
    cin >> n >> m;
    vi a(n);
    int x = 0;
    string s;
    loop(n) {
      cin >> s;
      x += s.length();
      while (!s.empty() and s.back() == '0') {
        s.pop_back();
        a[i]++;
      }
    }
    sort(iter(a));
    for (int i = 0;!a.empty() and a.back();i++) {
      if (~i & 1) {
        x -= a.back();
      }
      a.pop_back();
    }
    cout << (x <= m ? "Anna" : "Sasha") << endl;
  }
  return 0;
}

