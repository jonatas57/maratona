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

  int n, m;
  cin >> n >> m;
  vector<vi> a(n + 2, vi(m + 2));
  ll sum = 0;
  loop(n + 2) vloop(j, m + 2) cin >> a[i][j], sum += a[i][j];
  vector<string> ss(n, string(m, '.'));
  bool pos = true;
  loop(n) {
    vloop(j, m) {
      if (a[i][j]) {
        ss[i][j] = 'X';
        sum -= 9;
        vloop(k, 3) vloop(l, 3) {
          if (--a[i + k][j + l] < 0) {
            pos = false;
            i = j = k = l = INF;
          }
        }
      }
    }
  }
  if (pos and !sum) each(s, ss) cout << s << endl;
  else cout << "impossible" << endl;
  return 0;
}

