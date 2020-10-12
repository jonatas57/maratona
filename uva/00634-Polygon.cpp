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

  int n;
  while (cin >> n and n) {
    int x, y;
    vector<ii> ps;
    loop(n) {
      cin >> x >> y;
      ps.emplace_back(x, y);
    }
    cin >> x >> y;
    ps.push_back(ps[0]);
    int cnt = 0;
    loop(n) {
      if (ps[i].first == ps[i + 1].first and ps[i].first < x) {
        int a = ps[i].second, b = ps[i + 1].second;
        if (a > b) swap(a, b);
        if (a <= y and y <= b) cnt++;
      }
    }
    cout << (cnt & 1 ? 'T' : 'F') << endl;
  }
  return 0;
}

