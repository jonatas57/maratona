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

vi id, sz;
void makeset(int x) {
	id.resize(x + 1);
	sz.assign(x + 1, 1);
	loop(x + 1) id[i] = i;
}

int find(int x) {
	return id[x] == x ? x : id[x] = find(id[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	id[a] = b;
	sz[b] += sz[a];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int q;
	cin >> q;
	loop(q) {
		int n;
		cin >> n;
		int p;
		makeset(n);
		for (int i = 1;i <= n;i++) {
			cin >> p;
			join(p, i);
		}
		for (int i = 1;i <= n;i++) {
			cout << sz[find(i)] << " ";
		}
		cout << endl;
	}
	return 0;
}

