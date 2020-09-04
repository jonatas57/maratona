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

int getSum(ll x) {
  int ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    ll n;
    int s, sum = 0;
    cin >> n >> s;
    sum = getSum(n);
    ll ans = 0, b = 1;
    while (n % 10 == 0) n /= 10, b *= 10;
    while (sum > s) {
      int r = 10 - n % 10;
      ans += r * b;
      n += r;
      sum = getSum(n);
      while (n % 10 == 0) n /= 10, b *= 10;
    }
    cout << ans << endl;
  }
	return 0;
}

