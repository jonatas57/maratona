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

  int t;
  cin >> t;
  loop(t) {
    string s;
    int x, n;
    cin >> s >> x;
    n = s.length();
    string ans(n, '1');
    loop(n) {
      if (s[i] == '0') {
        if (i >= x) ans[i - x] = '0';
        if (i + x < n) ans [i + x] = '0';
      }
    }
    bool pos = true;
    loop(n) {
      if (s[i] == '1') {
        bool ok = false;
        if (i >= x and ans[i - x] == '1') ok = true;
        if (i + x < n and ans [i + x] == '1') ok = true;
        if (!ok) pos = false;
      }
    }
    cout << (pos ? ans : "-1") << endl;
  }
	return 0;
}

