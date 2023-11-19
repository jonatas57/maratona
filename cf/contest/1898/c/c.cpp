#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

vector<string> create(int n, int m) {
  vector<string> res(n);
  loop(n) vloop(j, m) {
    res[i][j] = (i + j) & 1 ? 'B' : 'R';
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m, k;
    cin >> n >> m >> k;
    int sh = n + m - 2;
    if (k < sh or (k xor sh) & 1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    vector<string> h = create(n, m - 1), v = create(n - 1, m);
    char x = 'R' xor 'B';
    v[0][1] ^= x;
    v[n - 2][m - 2] ^= x;
    h[n - 1][m - 2] ^= x;
    each(s, h) {
      loop(m - 1) cout << s[i] << ' ';
      cout << endl;
    }
    each(s, v) {
      loop(m) cout << s[i] << ' ';
      cout << endl;
    }
  }
  return 0;
}

