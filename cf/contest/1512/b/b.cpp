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
    ii a(-1, -1), b;
    int n;
    cin >> n;
    vector<string> s(n);
    loop(n) {
      cin >> s[i];
      for (int j = 0;s[i][j];j++) {
        if (s[i][j] == '*') {
          if (a.first == -1) a = {i, j};
          else b = {i, j};
        }
      }
    }
    if (a.first == b.first) {
      int x = a.first == n - 1 ? -1 : 1;
      s[a.first + x][a.second] = s[b.first + x][b.second] = '*';
    }
    else if (a.second == b.second) {
      int x = a.second == n - 1 ? -1 : 1;
      s[a.first][a.second + x] = s[b.first][b.second + x] = '*';
    }
    else {
      s[a.first][b.second] = s[b.first][a.second] = '*';
    }
    each(x, s) cout << x << endl;
  }
  return 0;
}

