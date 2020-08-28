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

struct graph {
  map<string, int> conv;
  vi par;
  int size;
  graph() : size(0) {}
  void addEdge(string c, string p) {
    int a = addNode(c);
    int b = addNode(p);
    par[a] = b;
  }
  int addNode(string s) {
    if (!conv.count(s)) {
      conv[s] = size++;
      par.push_back(-1);
    }
    return conv[s];
  }
  string query(string s, string t) {
    if (!conv.count(s) or !conv.count(t)) return "no relation";
    int a = conv[s];
    int b = conv[t];
    int l, da, db;
    tie(l, da, db) = lca(a, b);
    string ans = "";
    if (l == a) {
      loop(db - 2) ans += "great ";
      if (db - 1) ans += "grand ";
      ans += "parent";
    }
    else if (l == b) {
      loop(da - 2) ans += "great ";
      if (da - 1) ans += "grand ";
      ans += "child";
    }
    else if (da != -1 and db != -1) {
      int k = min(da, db) - 1;
      int r = abs(da - db);
      if (k | r) {
        ans = to_string(k) + " cousin";
        if (r) ans += " removed " + to_string(r);
      }
      else ans = "sibling";
    }
    else ans = "no relation";
    return ans;
  }
  tuple<int, int, int> lca(int a, int b) {
    vi dista(size, -1);
    dista[a] = 0;
    while (par[a] != -1) {
      dista[par[a]] = dista[a] + 1;
      a = par[a];
    }
    int db = 0;
    while (b != -1 and dista[b] == -1) {
      b = par[b];
      db++;
    }
    if (b == -1) return make_tuple(-1, -1, -1);
    return make_tuple(b, dista[b], db);
  }
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string a, b;
  graph g;
  while (cin >> a >> b and a != "no.child") {
    g.addEdge(a, b);
  }
  while (cin >> a >> b) {
    cout << g.query(a, b) << endl;
  }
	return 0;
}

