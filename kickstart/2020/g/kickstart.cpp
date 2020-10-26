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
    string s;
    cin >> s;
    vi kick, start;
    size_t last = 0;
    while (true) {
      size_t x = s.find("KICK", last);
      if (x == string::npos) break;
      kick.push_back(x);
      last = x + 1;
    }
    last = 0;
    while (true) {
      size_t x = s.find("START", last);
      if (x == string::npos) break;
      start.push_back(x);
      last = x + 1;
    }
    int x = kick.size(), y = start.size();
    ll ans = 0;
    for (int i = 0, j = 0;y and i < x;) {
      if (kick[i] < start[j]) {
        ans += y;
        i++;
      }
      else j++, y--;
    }
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}

