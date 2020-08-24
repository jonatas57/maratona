#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int h, w;
int dijkstra(vector<string>& g, int a, int b, int c, int d) {
  vector<vi> dist(h, vi(w, INF));
  vector<vb> visit(h, vb(w, false));
  priority_queue<tuple<int, int, int>> q;
  q.emplace(0, a, b);
  dist[a][b] = 0;
  while (!q.empty()) {
    auto [dis, x, y] = q.top();
    q.pop();
    if (visit[x][y]) continue;
    if (x == c and y == d) return abs(dis);
    visit[x][y] = true;
    for (int i = -2;i <= 2;i++) {
      for (int j = -2;j <= 2;j++) {
        int nx = x + i;
        int ny = y + j;
        if (nx < 0 or nx >= h or ny < 0 or ny >= w or visit[nx][ny] or g[nx][ny] == '#') continue;
        dist[nx][ny] = abs(dis) + (abs(i) + abs(j) != 1);
        q.emplace(-dist[nx][ny], nx, ny);
      }
    }
  }
  return -1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> h >> w;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--, b--, c--, d--;
  vector<string> m(h);
  loop(h) {
    cin >> m[i];
  }
  cout << dijkstra(m, a, b, c, d) << endl;
	return 0;
}

