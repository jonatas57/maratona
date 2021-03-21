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

int calc(int x) {
  x >>= 1;
  return pow(10, x) - 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  ll n;
  cin >> n;
  string s = to_string(n);
  int l = s.length();
  ll ans = calc(l & 1 ? l - 1 : l - 2);
  if (~l & 1) {
    int x = stoi(s.substr(0, l / 2));
    int y = stoi(s.substr(l / 2));
    ans += x - pow(10, l / 2 - 1) + 1;
    if (y < x) ans--;
  }
  cout << ans << endl;
  return 0;
}

