#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int h, w, m;
  cin >> h >> w >> m;
  mii l, c;
  map<ii, bool> used;
  int x, y;
  loop(m) {
    cin >> x >> y;
    l[x]++;
    c[y]++;
    used[ii(x, y)] = true;
  }
  vector<ii> ls(iter(l)), cs(iter(c));
  sort(iter(ls), [](ii a, ii b) { return a.second == b.second ? a.first > b.first : a.second > b.second; });
  sort(iter(cs), [](ii a, ii b) { return a.second == b.second ? a.first > b.first : a.second > b.second; });
  x = ls.size(), y = cs.size();
  int ans = 0;
  int ml = 0, mc = 0;
  for (;ml < x and ls[0].second == ls[ml].second;ml++);
  for (;mc < y and cs[0].second == cs[mc].second;mc++);

  bool ok = false;
  int trg = ls[0].second + cs[0].second;
  loop(ml) vloop(j, mc) {
    if (ok) break;
    int aux = ls[i].second + cs[j].second;
    int u = used[ii(ls[i].first, cs[j].first)];
    aux -= u;
    if (!u and aux > ans) ok = true;
    ans = max(aux, ans);
  }
  loop(ml) for (int j = mc;j < y;j++) {
    if (ok) break;
    int aux = ls[i].second + cs[j].second;
    if (aux < trg) break;
    int u = used[ii(ls[i].first, cs[j].first)];
    aux -= u;
    if (!u and aux >= ans) ok = true, ans = aux;
  }
  for (int i = ml;i < x;i++) vloop(j, mc) {
    if (ok) break;
    int aux = ls[i].second + cs[j].second;
    if (aux < trg) break;
    int u = used[ii(ls[i].first, cs[j].first)];
    aux -= u;
    if (!u and aux >= ans) ok = true, ans = aux;
  }
  cout << ans << endl;
	return 0;
}

