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

  int n;
  cin >> n;
  vector<ll> a(n), b(n + 1, 0);
  ll l = 0, r = INF;
  loop(n) {
    cin >> a[i];
    b[i + 1] = a[i] - b[i];
    if (~i & 1) r = min(r, b[i + 1]);
    else l = min(l, b[i + 1]);
  }
  r = min(r, a[0]);
  cout << max(0ll, r + l + 1) << endl;
  return 0;
}

