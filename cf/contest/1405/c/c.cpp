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
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool pos = true;
    for (int i = 0;pos and i < k;i++) {
      map<char, int> cnt;
      for (int j = i;j < n;j += k) {
        cnt[s[j]]++;
      }
      if (cnt['0'] and cnt['1']) pos = false;
      else if (cnt['0'] or cnt['1']) {
        char c = cnt['0'] ? '0' : '1';
        for (int j = i;j < n;j += k) s[j] = c;
      }
    }
    map<char, int> cnt;
    loop(k) cnt[s[i]]++;
    int hk = k >> 1;
    if (cnt['0'] > hk or cnt['1'] > hk) pos = false;
    cout << (pos ? "YES" : "NO") << endl;
  }
	return 0;
}

