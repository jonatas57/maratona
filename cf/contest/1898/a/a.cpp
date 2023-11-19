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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int b = 0;
    each(c, s) b += c == 'B';
    vector<pair<int, char>> ans; 
    if (b == k) cout << 0 << endl;
    else if (b < k) {
      int at = 0;
      for (;b < k and s[at];at++) {
        b += s[at] == 'A';
      }
      cout << 1 << endl << at << " B" << endl;
    }
    else {
      int at = 0;
      for (;b > k and s[at];at++) {
        b -= s[at] == 'B';
      }
      cout << 1 << endl << at << " A" << endl;
    }
  }
  return 0;
}

