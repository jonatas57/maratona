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
#define rep(x, y, z)       for(int i = x;i <= y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)

#define pb                 push_back

int main() {
	ios_base::sync_with_stdio(false);

  int n, k, maxx = -1;
  cin >> n >> k;
  vi a(n);
  mii c, qtd;
  loop(n) {
    cin >> a[i];
    c[a[i]]++;
    maxx = max(maxx, c[a[i]]);
  }
  if (maxx > k || n < k) {
    cout << "NO" << endl;
  }
  else {
    vi color(n, 0);
    vb used(k, false);
    loop(n) {
      color[i] = c[a[i]]--;
      qtd[color[i]]++;
      used[color[i]] = true;
    }
    deque<int> miss;
    rep(1, k, 1) {
      if (!used[i]) {
        miss.push_back(i);
      }
    }
    for (int i = 0;i < n && !miss.empty();i++) {
      if (qtd[color[i]] > 1) {
        qtd[color[i]]--;
        color[i] = miss[0];
        miss.pop_front();
        qtd[color[i]]++;
      }
    }
    cout << "YES" << endl;
    each(x, color) cout << x << " ";
    cout << endl;
  }
	return 0;
}
