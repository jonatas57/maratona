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

int ask(int l, int r) {
  if (l == r) return -1;
  cout << "? " << l << " " << r << endl;
  cout.flush();
  int x;
  cin >> x;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  int l = 1, r = n;
  int sm = ask(1, n);
  bool last;
  if (sm == n) last = true;
  else if (sm == 1) last = false;
  else if (sm == ask(1, sm)) last = true, r = sm;
  else last = false, l = sm;
  while (l + 1 < r) {
    int mid = last ? (l + r + 1) / 2 : (l + r) / 2;
    int x = last ? ask(mid, sm) : ask(sm, mid);
    if (sm != x) last ? r = mid - 1 : l = mid + 1;
    else last ? l = mid : r = mid;
  }
  if (ask(l, r) == l) l = r;
  cout << "! " << l << endl;
  return 0;
}

