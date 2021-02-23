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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, x;
    cin >> n >> x;
    vi a(n);
    int cnt = 0;
    loop(n) {
      cin >> a[i];
      if (i and a[i] >= a[i - 1]) cnt++;
    }
    bool pos = true;
    int ans = 0;
    for (int i = 0;i < n and pos and cnt < n - 1;i++) {
      if (a[i] > x) {
        swap(a[i], x);
        ans++;
        if (i < n - 1 and a[i] <= a[i + 1] and x > a[i + 1]) cnt++;
      }
      else if (i and a[i] < a[i - 1]) pos = false;
    }
    cout << (pos ? ans : -1) << endl;
  }
  return 0;
}

