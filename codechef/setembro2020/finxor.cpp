#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const int MAX = 1 << 20;

int ask(int k) {
  cout << 1 << " " << k << endl;
  cout.flush();
  int x;
  cin >> x;
  if (x < 0) exit(0);
  return x;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    int tot = ask(MAX) - n * MAX;
    int ans = 0, sum = 0;
    for (int m = 1, i = 0;i < 19;i++, m <<= 1) {
      int x = ask(m);
      int del = (tot - x) / m;
      int y = (del + n) >> 1;
      if (y & 1) ans += m;
      sum += m * y;
    }
    int y = (tot - sum) / (1 << 19);
    if (y & 1) ans += 1 << 19;
    cout << 2 << " " << ans << endl;
    cout.flush();
    int ok;
    cin >> ok;
    if (ok == -1) exit(0);
  }
	return 0;
}

