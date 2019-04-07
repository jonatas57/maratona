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

int a[N], cnt[1000010], bsize, ans[200010], aux = 0;

struct query {
  int id, l, r;
  query(int id, int l, int r) : id(id), l(l), r(r) {}
  bool operator<(query& q) {
    int a = l / bsize, b = q.l / bsize, c = r / bsize, d = q.r / bsize;
    if (a < b) return true;
    return (a == b && c < d);
  }
};
void add(int p) {
  if (cnt[a[p]]++ == 0) aux++;
}
void rem(int p) {
  if (--cnt[a[p]] == 0) aux--;
}

int main() {
  ios_base::sync_with_stdio(false);
  memset(ans, 0, sizeof ans);
  memset(cnt, 0, sizeof cnt);

  int n, q;
  scanf("%d", &n);
  loop(n) scanf("%d", a + i);
  scanf("%d", &q);
  bsize = sqrt(q);
  vector<query> qs;
  int l, r;
  loop(q) scanf("%d %d", &l, &r), qs.emplace_back(i, l, r);
  sort(qs.begin(), qs.end());

  int L = 0, R = 0;
  aux = 1;
  cnt[a[0]]++;
  each(q, qs) {
    int x = q.id, l = q.l - 1, r = q.r - 1;
    while (L < l) rem(L++);
    while (L > l) add(--L);
    while (R < r) add(++R);
    while (R > r) rem(R--);
    ans[x] = aux;
  }
  loop(q) printf("%d\n", ans[i]);
  return 0;
}
