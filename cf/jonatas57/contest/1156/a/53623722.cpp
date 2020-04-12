#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

int f(int a, int b) {
  int c = a + b;
  return c >= 5 ? INF : c;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vi a(n);
  loop(n) cin >> a[i];
  int cnt = 0;
  bool inf = false;
  loop(n - 1) {
    int x =  f(a[i], a[i + 1]);
    if (x == INF) inf = true;
    else cnt += x;
    if (i >= 1 && a[i - 1] == 3 && a[i] == 1 && a[i + 1] == 2) {
      cnt--;
    }
  }
  if (inf) cout << "Infinite\n";
  else cout << "Finite\n" << cnt << endl;
  return 0;
}
