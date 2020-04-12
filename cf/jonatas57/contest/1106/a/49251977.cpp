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
    vector<string> M(n);
    loop(n) {
      cin >> M[i];
    }
    int cross = 0;
    rep(1, n - 1, 1) {
      for (int j = 1;j < n - 1;j++) {
        if (M[i][j] == M[i - 1][j - 1] && M[i - 1][j - 1] == M[i - 1][j + 1] &&
            M[i - 1][j + 1] == M[i + 1][j - 1] && M[i + 1][j - 1] == M[i + 1][j + 1] &&
            M[i + 1][j + 1] == 'X') {
          cross++;
        }
      }
    }
    cout << cross << endl;
  return 0;
}
