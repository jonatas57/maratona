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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

vi id, sz, ant;

void init(int n) {
	id.resize(n);
	sz.resize(n, 1);
	ant.resize(n, -1);
	loop(n) id[i] = i;
}

int find(int x) {
	return x == id[x] ? x : id[x] = find(id[x]);
}

int findAnt(int x) {
	x = find(x);
	return ant[x] == -1 ? ant[x] : ant[x] = find(ant[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
}

bool isantonymy(int a, int b) {
	return find(a) == findAnt(b);
}

bool issynonymy(int a, int b) {
	return find(a) == find(b);
}

void addSynonymy(int a, int b) {
	int x = findAnt(a);
	int y = findAnt(b);
	join(a, b);
	ant[find(a)] = max(x, y);
	if (x != -1 and y != -1) {
		join(x, y);
	}
}

void addAntonymy(int a, int b) {
	a = find(a);
	b = find(b);
	int x = findAnt(a);
	int y = findAnt(b);
	if (x != -1) addSynonymy(b, x);
	else if (y != -1) addSynonymy(a, y);
	a = find(a), b = find(b);
	ant[a] = b;
	ant[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;
	map<string, int> conv;
	string s, t;
	int type, a, b;
	init(n);
	loop(n) {
		cin >> s;
		conv[s] = i;
	}
	loop(m) {
		cin >> type >> s >> t;
		a = conv[s], b = conv[t];
		if (type == 1 and not isantonymy(a, b)) {
			cout << "YES" << endl;
			addSynonymy(a, b);
		}
		else if (type == 2 and not issynonymy(a, b)) {
			cout << "YES" << endl;
			addAntonymy(a, b);
		}
		else cout << "NO" << endl;
	}
	loop(q) {
		cin >> s >> t;
		a = conv[s], b = conv[t];
		if (issynonymy(a, b)) cout << 1 << endl;
		else if (isantonymy(a, b)) cout << 2 << endl;
		else cout << 3 << endl;
	}
	return 0;
}

