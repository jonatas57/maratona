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

bool solve(string& s, string& t, int poss, int post = 0, bool r = true) {
  if (!t[post]) return true;
  if (s[poss] != t[post] or poss < 0) return false;
  if (r) {
    if (solve(s, t, poss + 1, post + 1, r)) return true;
    r = false;
  }
  return solve(s, t, poss - 1, post + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    string s, q;
    cin >> s >> q;
    bool ans = false;
    for (int i = 0;s[i] and !ans;i++) ans = solve(s, q, i);
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}

