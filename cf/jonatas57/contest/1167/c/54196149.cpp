#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

vi id, sz;
void makeset(int x) {
	id.resize(x), sz.resize(x, 1);
	loop(x) {
		id[i] = i;
	}
}
int find(int x) {
	if (x == id[x]) return x;
	return id[x] = find(id[x]);
}
void join(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	makeset(n);
	int x, y;
	loop(m) {
		cin >> x;
		int aux;
		loop(x) {
			cin >> y;
			if (i == 0) aux = y;
			else join(y - 1, aux - 1);
		}
	}
	loop(n) cout << sz[find(i)] << " ";
	cout << endl;
	return 0;
}

