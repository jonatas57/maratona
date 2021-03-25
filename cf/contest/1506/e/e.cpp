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
    int n;
    cin >> n;
    vi q;
    vb used(n + 2, false), used2(n + 1, false);
    int p = 1, last = -1;
    vi a, b;
    loop(n) {
      int x;
      cin >> x;
      if (x > last) {
        used[x] = true;
        for (int i = last + 1;i < x;i++) q.push_back(i);
        a.push_back(x);
        b.push_back(x);
        last = x;
      }
      else {
        while (used[p]) p++;
        a.push_back(p++);
        b.push_back(q.back());
        q.pop_back();
      }
    }
    each(x, a) cout << x << " ";
    cout << endl;
    each(x, b) cout << x << " ";
    cout << endl;
  }
  return 0;
}

