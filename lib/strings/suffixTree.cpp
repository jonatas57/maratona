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
int n;
string s;
const int MAXN = 1e6;

struct node {
	int l, r, par, link;
	map<char,int> next;

	node (int l=0, int r=0, int par=-1)
		: l(l), r(r), par(par), link(-1) {}
	int len()  {  return r - l;  }
	int &get (char c) {
		if (!next.count(c))  next[c] = -1;
		return next[c];
	}
};
node t[MAXN];
int sz;

struct state {
	int v, pos;
	state (int v, int pos) : v(v), pos(pos)  {}
};
state ptr (0, 0);

state go (state st, int l, int r) {
	while (l < r)
		if (st.pos == t[st.v].len()) {
			st = state (t[st.v].get( s[l] ), 0);
			if (st.v == -1)  return st;
		}
		else {
			if (s[ t[st.v].l + st.pos ] != s[l])
				return state (-1, -1);
			if (r-l < t[st.v].len() - st.pos)
				return state (st.v, st.pos + r-l);
			l += t[st.v].len() - st.pos;
			st.pos = t[st.v].len();
		}
	return st;
}

int split (state st) {
	if (st.pos == t[st.v].len())
		return st.v;
	if (st.pos == 0)
		return t[st.v].par;
	node v = t[st.v];
	int id = sz++;
	t[id] = node (v.l, v.l+st.pos, v.par);
	t[v.par].get( s[v.l] ) = id;
	t[id].get( s[v.l+st.pos] ) = st.v;
	t[st.v].par = id;
	t[st.v].l += st.pos;
	return id;
}

int get_link (int v) {
	if (t[v].link != -1)  return t[v].link;
	if (t[v].par == -1)  return 0;
	int to = get_link (t[v].par);
	return t[v].link = split (go (state(to,t[to].len()), t[v].l + (t[v].par==0), t[v].r));
}

void tree_extend (int pos) {
	for(;;) {
		state nptr = go (ptr, pos, pos+1);
		if (nptr.v != -1) {
			ptr = nptr;
			return;
		}

		int mid = split (ptr);
		int leaf = sz++;
		t[leaf] = node (pos, n, mid);
		t[mid].get( s[pos] ) = leaf;

		ptr.v = get_link (mid);
		ptr.pos = t[ptr.v].len();
		if (!mid)  break;
	}
}

void build_tree() {
	sz = 1;
	for (int i=0; i<n; ++i)
		tree_extend (i);
}

int traverseEdge(string& p, int pos, int at) {
	int k = 0;
	for (k = t[at].l;k < t[at].r;k++, pos++) {
		if (!p[pos]) return 1;
		if (s[k] != p[pos]) return -1;
	}
	return 0;
}

bool hasSubstr(string& p, int at = 0, int pos = 0) {
	int res = -1;
	if (at) {
		res = traverseEdge(p, pos, at);
		if (res) return res == 1;
	}
	pos += t[at].len();
	int x = t[at].get(p[pos]);
	if (x != -1) return hasSubstr(p, x, pos) == 1;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> s;
	build_tree();/*@*/
	loop(sz) {cerr << setw(2) << i;
		cerr << setw(3) << t[i].l;
		cerr << setw(3) << t[i].r;
		cerr << setw(4) << t[i].par;
		cerr << setw(4) << t[i].link;
		for (auto [c, n] : t[i].next) cerr << " " << c << "->" << setw(3) << n;
		cerr << endl;
	}/*@*/
	return 0;
}

