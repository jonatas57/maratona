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
  double sq = sqrt(3);
  loop(t) {
    int n;
    cin >> n;
    vi ls(1, 0);
    double sum = 0;
    char c;
    int k;
    loop(n) {
      cin >> c >> k;
      ls.back() += k;
      if (c == 'C') ls.push_back(k);
      sum += c == 'T' ? k * k * sq / 4 : k * k;
    }
    cout << fixed << setprecision(4) << ls[1] * ls[2] - sum << endl;
  }
  return 0;
}

