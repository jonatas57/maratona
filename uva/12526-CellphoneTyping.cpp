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

struct node {
  int ch;
  bool end;
  vector<node*> adj;
  node() : ch(0), end(false), adj(26, nullptr) {}
  void addString(string& s, int pos = 0) {
    if (!s[pos]) {
      end = true;
      return;
    }
    int x = s[pos] - 'a';
    if (!adj[x]) {
      ch++;
      adj[x] = new node;
    }
    adj[x]->addString(s, pos + 1);
  }
};

void del(node* n) {
  each(nd, n->adj) {
    if (nd) del(nd);
  }
  delete n;
}

int dfs(node* t, int press = 0) {
  int ans = t->end * press;
  int del = t->end or !press or t->ch > 1;
  each(c, t->adj) {
    if (!c) continue;
    ans += dfs(c, press + del);
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  while (cin >> n) {
    node* trie = new node;
    string s;
    loop(n) {
      cin >> s;
      trie->addString(s);
    }
    int p = dfs(trie);
    cout << fixed << setprecision(2) << (double)p / n << endl;
  }
	return 0;
}

