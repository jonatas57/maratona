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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 1;
    vi a;
    for (int i = 1;i <= n;i++) {
      if (s[i] == s[i - 1]) cnt++;
      else a.push_back(cnt), cnt = 1;
    }
    int ans = 0;
    int m = a.size();
    for (int i = 0, j = 0;i < m;i++) {
      if (j < i) j = i;
      while (j < m and a[j] == 1) j++;
      if (j < m) a[j]--;
      else {
        ans += (m - i + 1) / 2;
        break;
      }
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

