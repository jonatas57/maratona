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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

bool mono(int x, int y, int z) {
  return x == y or y == z or (x < y) == (y < z);
}

void add(list<ii>& q, int x) {
  if (q.empty()) q.emplace_back(x, x);
  else if (mono(q.back().first, q.back().second, x)) q.back().second = x;
  else q.emplace_back(q.back().second, x);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vi a(n), next(n + 1, 0);
  loop(n) {
    cin >> a[i];
    if (i) next[a[i - 1]] = a[i];
  }
  list<ii> q, q2;
  each(x, a) {
    add(q, x);
  }
  int ans = 0;
  while (q.size() > 1 or q.front().first > q.front().second) {
    ans++;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop_front();
      if (x < y) {
        add(q2, x);
        add(q2, y);
      }
      else if (x > y) {
        if (next[y]) {
          add(q2, x);
          add(q2, next[y]);
          q.front().first = next[y];
          next[x] = next[y];
        }
        else {
          next[x] = 0;
        }
      }
    }
    q2.swap(q);
    if (q.empty()) break;
  }
  cout << ans << endl;
  return 0;
}

