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

vi divs(int x) {
  vi ds;
  for (int i = 1;i * i < x;i++) {
    if (x % i == 0) {
      ds.push_back(i);
      if (i * i != x) ds.push_back(x / i);
    }
  }
  return ds;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  mii cnt;
  loop(n) {
    int x;
    cin >> x;
    auto d = divs(x);
    each(y, d) cnt[y]++;
  }
  cnt.erase(1);
  int ans = 0;
  for (auto& [d, q] : cnt) {
    if (cnt[ans] < q) ans = d;
  }
  cout << ans << endl;
  return 0;
}

