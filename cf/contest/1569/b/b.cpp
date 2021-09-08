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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    string s;
    cin >> n >> s;
    vector<string> ans(n, string(n, ' '));
    bool ok = true;
    vi two;
    mii next;
    loop(n) if (s[i] == '2') two.push_back(i);
    if (!two.empty() and two.size() < 3) ok = false;
    if (!two.empty()) two.push_back(two[0]);
    loop((int)two.size() - 1) next[two[i]] = two[i + 1];
    loop(n) {
      if (!ok) break;
      vloop(j, n) {
        if (!ok) break;
        if (i == j) ans[i][j] = 'X';
        else if (s[i] == '1') {
          ans[i][j] = s[j] == '1' ? '=' : '+';
        }
        else {
          ans[i][j] = s[j] == '1' ? '-' : j == next[i] ? '+' : next[j] == i ? '-' : '=';
        }
      }
    }
    if (ok) {
      cout << "YES" << endl;
      each(s, ans) cout << s << endl;
    }
    else cout << "NO" << endl;
  }
  return 0;
}

