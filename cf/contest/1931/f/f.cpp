#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

bool check(vi& a, vi& p) {
  int n = a.size();
  bool ok = false;
  for (int i = 0, j = 1;i < n;) {
    if (p[i] == a[0] and !ok) {
      i++;
      ok = true;
    }
    else if (p[i] == a[j]) i++, j++;
    else return false;
  }
  return true;
}

int getAnt(vi& a, int x) {
  int ant = -1;
  for (size_t i = 1;i < a.size();i++) {
    if (a[i] == x) break;
    ant = a[i];
  }
  return ant;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    cin >> n >> k;
    vector<vi> a(k, vi(n));
    loop(k) vloop(j, n) {
      cin >> a[i][j];
    }
    bool ok = true;
    if (k > 1) {
      vi pos(n + 1, -1), p;
      for (int i = 1;i < n;i++) {
        p.push_back(a[0][i]);
        pos[a[0][i]] = i;
      }
      int ant = getAnt(a[1], a[0][0]);
      int ant2 = getAnt(a[0], a[1][0]);
      if (ant == ant2 and k > 2) {
        int ant3 = getAnt(a[2], a[0][0]);
        if (ant3 == a[1][0]) {
          ant = a[1][0];
        }
      }
      int at = ant == -1 ? 0 : pos[ant];
      p.insert(p.begin() + at, a[0][0]);
      each(v, a) {
        ok &= check(v, p);
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

