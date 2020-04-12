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

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  int a = 0;
  cin >> s;
  each(x, s) {
    a += (x == 'A' ? 1 : 0);
  }
  int d = n - a, m = n / 2;
  cout << (a > m ? "Anton" : (d > m ? "Danik" : "Friendship")) << endl;
  return 0;
}
