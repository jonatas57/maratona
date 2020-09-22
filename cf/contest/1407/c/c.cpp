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

int ask(int x, int y) {
  cout << "? " << x << " " << y << endl;
  cout.flush();
  int m;
  cin >> m;
  if (m == -1) exit(0);
  return m;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vi a(n);
  vb ok(n + 1, false);
  for (int i = 0, j = 1;j < n;) {
    int x = ask(i + 1, j + 1);
    int y = ask(j + 1, i + 1);
    if (x > y) {
      a[i] = x;
      ok[x] = true;
      i = j;
      j++;
    }
    else {
      a[j] = y;
      ok[y] = true;
      j++;
    }
  }
  int last;
  loop(n) if (a[i] == 0) last = i;
  for (int i = 1;i <= n;i++) if (!ok[i]) a[last] = i;
  cout << "! ";
  each(x, a) cout << x << " ";
  cout << endl;
  return 0;
}

