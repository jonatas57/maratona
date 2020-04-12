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

#define pb                 push_back

void remove(vi& a, vi& b) {
  int n = a.size(), m = b.size();
  vi c;
  for (int i = 0, j = 0;i < n;) {
    if (j >= m || a[i] != b[j]) {
      c.pb(a[i]);
      i++;
    }
    else {
      i++;
      j++;
    }
  }
  a = c;
}
vi divisors(int x) {
  int aux = x;
  vi div;
  for (int i = 1;i <= aux;i++) {
    if (x % i == 0) {
      div.pb(i);
      aux = x / i;
      div.pb(aux);
    }
  }
  set<int> aux2(div.begin(), div.end());
  vi divs(aux2.begin(), aux2.end());
  return divs;
}
int main() {
	ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vi divs(n);
  loop (n) {
    cin >> divs[i];
  }
  sort(divs.begin(), divs.end());
  int x, y;
  y = divs[n - 1];
  vi divy = divisors(y);
  remove(divs, divy);
  x = divs[divs.size() - 1];
  cout << x << " " << y << endl;
	return 0;
}
