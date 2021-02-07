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

vi cache;
int n;

int ask(int x) {
  if (x < 0 or x >= n) return INF;
  if (cache[x] == -1) {
    cout << "? " << x + 1 << endl;
    cout.flush();
    cin >> cache[x];
  }
  return cache[x];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  int l = 0, r = n - 1;
  cache.resize(n, -1);
  while (l < r) {
    int mid = avg(l, r);
    int x = ask(mid);
    int y = ask(mid + 1);
    if (x < y) r = mid;
    else l = mid + 1;
  }
  cout << "! " << l + 1 << endl;
  return 0;
}

