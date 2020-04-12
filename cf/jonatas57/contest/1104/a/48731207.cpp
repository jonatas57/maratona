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

int main() {
	ios_base::sync_with_stdio(false);

  int n, d, k, d2;
  cin >> n;
  bool p = false;
  for (int i = 9;i > 0 && !p;i--) {
    if (n % i == 0) {
      p = true;
      d = i;
    }
  }
  if (p) {
    k = n / d;
  }
  else {
    k = n / 9;
    d = 9;
    d2 = n - (9 * k);
    k++;
  }
  cout << k << endl;
  int aux = p ? k : k - 1;
  loop(aux) {
    cout << d << " ";
  }
  if (!p) cout << d2;
  cout << endl;
	return 0;
}
