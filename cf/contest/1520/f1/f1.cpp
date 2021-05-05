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

vi cnt;

int ask(int r) {
  if (cnt[r - 1] == -1) {
    cout << "? " << 1 << " " << r << endl;
    cout.flush();
    int x;
    cin >> x;
    cnt[r - 1] = r - x;
  }
  return cnt[r - 1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, t;
  cin >> n >> t;
  cnt.resize(n, -1);
  loop(t) {
    int k;
    cin >> k;
    int l = 1, r = n;
    while (l < r) {
      int mid = avg(l, r);
      int x = ask(mid);
      if (x < k) l = mid + 1;
      else r = mid;
    }
    cout << "! " << l << endl;
    cout.flush();
  }
  return 0;
}

