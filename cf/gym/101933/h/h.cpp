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

  int l, m;
  cin >> l >> m;
  vector<string> ans;
  string s;
  getline(cin, s);
  int price = INF;
  loop(m) {
    getline(cin, s);
    string name = "";
    array<ll, 4> a = {0};
    int idx = -1;
    bool b = true;
    each(c, s) {
      if (c == ',') {
        idx++;
        b = false;
      }
      else if (b) {
        name += c;
      }
      else {
        a[idx] *= 10;
        a[idx] += c - '0';
      }
    }

    auto& [p, c, t, r] = a;

    ll x = 10080ll * c * t;
    ll y = x / (t + r);
    if (y >= l) {
      if (p < price) price = p, ans.clear();
      if (p <= price) ans.push_back(name);
    }
  }
  if (ans.empty()) cout << "no such mower" << endl;
  else each(s, ans) cout << s << endl;
  return 0;
}

