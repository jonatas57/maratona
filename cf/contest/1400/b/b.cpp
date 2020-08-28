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

int a, b, s, w;

int calc(int p, int f, int sp) {
  int ps = sp;
  int fs = s ? min(f / s, a - ps) : 0;
  int pw = w ? min((p - ps * s) / w, b) : 0;
  int fw = w ? min((f - fs * s) / w, b - pw) : 0;
  return ps + fs + pw + fw;
}

int solve(int p, int f) {
  int ans = 0;
  int lim = min(p / s, a);
  loop(lim + 1) {
    ans = max(ans, calc(p, f, i));
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int p, f;
    cin >> p >> f;
    cin >> a >> b >> s >> w;
    if (s > w) swap(s, w), swap(a, b);
    int ans = solve(p, f);
    cout << ans << endl; 
  }
	return 0;
}

