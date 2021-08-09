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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    cin >> n >> k;
    mii next;
    vi a(n);
    loop(n) {
      cin >> a[i];
      if (i) next[a[i - 1]] = a[i];
    }
    int last = a.back();
    sort(iter(a));
    int x = n;
    loop(n - 1) {
      if (a[i] == last) continue;
      if (next[a[i]] == a[i + 1]) x--;
    }
    cout << (x <= k ? "Yes" : "No") << endl;
  }
  return 0;
}

