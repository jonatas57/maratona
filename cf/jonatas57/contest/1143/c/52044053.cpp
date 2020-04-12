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
#define vloop(i, x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

struct node {
  int id, par, resp;
  bool c;
  vi chs;
  node() : resp(0) {}
  bool operator<(const node &n) const {
    if (c && !n.c) return false;
    if (c == n.c && resp < n.resp) return false;
    return !(c == n.c && resp == n.resp && id < n.id);
  }
};
vector<node> ns;
void newNode(int i, int p, int c) {
  ns[i].id = i + 1;
  ns[i].par = p;
  if (p >= 0) {
    ns[p].chs.push_back(i);
    if (!c) ns[p].resp++;
  }
  ns[i].c = c;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  ns.resize(n);
  int p, c;
  loop(n) cin >> p >> c, newNode(i, p - 1, c);
  priority_queue<node> pq(ns.begin(), ns.end());
  bool flag = false;
  while (!pq.empty()) {
    node x = pq.top();
    if (x.resp || !x.c) break;
    cout << x.id << " ";
    flag = true;
    pq.pop();
  }
  cout << (flag ? "\n" : "-1\n");
  return 0;
}
