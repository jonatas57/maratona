#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

bool isvowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  ios_base::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  if (s.size() != t.size()) {
    cout << "No" << endl;
  }
  else {
    int n = s.size();
    loop(n) {
      if (isvowel(s[i]) != isvowel(t[i])) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
  return 0;
}
