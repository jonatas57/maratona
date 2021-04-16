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

  vector<string> a(3);
  loop(3) cin >> a[i];
  string ans(a[0].length(), ' ');
  vi diffs;
  for (int i = 0;a[0][i];i++) {
    if (a[0][i] == a[1][i] and a[1][i] == a[2][i]) ans[i] = a[0][i];
    else diffs.push_back(i);
  }
  int sz = diffs.size();
  bool amb = false, imp = false;
  if (sz > 3) imp = true;
  else if (sz == 3) {
    vb ok(3, false);
    each(x, diffs) {
      map<char, vi> cnt;
      loop(3) cnt[a[i][x]].push_back(i);
      for (auto& [c, v] : cnt) {
        if (v.size() == 2) {
          ans[x] = c;
        }
        else if (ok[v[0]]) imp = true;
        else ok[v[0]] = true;
      }
      if (ans[x] == ' ') {
        imp = true;
      }
    }
  }
  else if (sz == 2) {
    vi aux(2, -1);
    string cs(2, ' ');
    loop(2) {
      map<char, vi> cnt;
      vloop(j, 3) cnt[a[j][diffs[i]]].push_back(j);
      for (auto& [c, v] : cnt) {
        if (v.size() == 1) {
          if (aux[i] == -1) aux[i] = v[0];
          else aux[i] = -2;
        }
        else cs[i] = c;
      }
    }
    int p = 0;
    if (aux[p] < 0) p = 1;
    if (aux[p] < 0) imp = true;
    else if (aux[p] == aux[!p]) amb = true;
    else {
      ans[diffs[p]] = cs[p];
      ans[diffs[!p]] = aux[!p] < 0 ? a[aux[p]][diffs[!p]] : cs[!p];
    }
  }
  else amb = true;
  cout << (imp ? "Impossible" : amb ? "Ambiguous" : ans) << endl;
  return 0;
}
