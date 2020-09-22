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

  int n, k;
  cin >> n >> k;
  vi dist(1 << k, INF), used(1 << k, 0);
  vb visit(1 << k, false);
  queue<int> q;
  string s;
  int x;
  loop(n) {
    x = 0;
    cin >> s;
    each(c, s) {
      x <<= 1;
      x += c - '0';
    }
    q.push(x);
    dist[x] = 0;
    visit[x] = true;
  }
  int ans = x;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    loop(k) {
      int v = u ^ (1 << i);
      if (visit[v]) continue;
      visit[v] = true;
      q.push(v);
      dist[v] = dist[u] + 1;
      if (dist[v] > dist[ans]) ans = v;
    }
  }
  s = string(k, ' ');
  loop(k) {
    s[i] = '0' + ((ans & (1 << (k - i - 1))) > 0);
  }
  cout << s << endl;
  return 0;
}

