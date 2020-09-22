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

struct node {
  int dist;
  bool visit, end;
  node* comp;
  vector<node*> next, adj;
  node() : dist(0), visit(false), end(false), comp(nullptr), next(26, nullptr) {}
  node* insert(string& s, int pos = 0) {
    if (!s[pos]) {
      end = true;
      return this;
    }
    int x = s[pos] - 'a';
    if (!next[x]) {
      next[x] = new node;
      next[x]->adj.push_back(this);
    }
    node* last = next[x]->insert(s, pos + 1);
    if (!comp and !end) adj.push_back(comp = last);
    return last;
  }
  int query(string& s, int pos = 0) {
    if (!s[pos]) return dist;
    if (next[s[pos] - 'a']) return next[s[pos] - 'a']->query(s, pos + 1);
    return dist + s.length() - pos;
  }
};

void bfs(node* n) {
  queue<node*> q;
  n->dist = 0;
  n->visit = true;
  q.push(n);
  while (!q.empty()) {
    node* u = q.front();
    q.pop();
    each(v, u->next) {
      if (!v or v->visit) continue;
      v->visit = true;
      v->dist = u->dist + 1;
      q.push(v);
    }
    each(v, u->adj) {
      if (!v or v->visit) continue;
      v->visit = true;
      v->dist = u->dist + 1;
      q.push(v);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  node *trie = new node;
  string s;
  loop(n) cin >> s, trie->insert(s);
  trie->adj.clear();
  bfs(trie);
  loop(m) {
    cin >> s;
    cout << trie->query(s) << endl;
  }
  return 0;
}

