#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define N                  100000
#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)        for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

int a[N], block[N], bsize;
void sqrtdec(int* v, int n) {
  bsize = sqrt(n);
  int j = -1;
  loop(n) {
    if (i % bsize == 0) {
      j++;
    }
    block[j] += a[i];
  }
}
ll sum(int l, int r) {
  ll sum = 0;
  while (l < r && l % bsize && l) sum += a[l++];
  while (l + bsize <= r) sum += block[l / bsize], l += bsize;
  while (l <= r) sum += a[l++];
  return sum;
}
void update(int p, int val) {
  int aux = p / bsize;
  block[aux] += val - a[p];
  a[p] = val;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  loop(n) cin >> a[i];
  char op;
  int l, r;
  sqrtdec(a, n);
  while (q--) {
    cin >> op >> l >> r;
    if (op == '?') {
      cout << sum(l - 1, r - 1) << endl;
    }
    else {
      update(l - 1, r);
    }
  }
  return 0;
}
