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

void init(int x) {
	id.resize(x);
	sz.resize(x, 1);
	loop(x) id[i] = i;
}
int find(int x) {
	return x == id[x] ? x : id[x] = find(id[x]);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) swap(a, b);
	id[b] = id[a];
	sz[a] += sz[b];
}

int x, y, z;
int coortoint(int a, int b, int c) {
	return c * x * y + b * x + a;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> x >> y >> z;
	init(x * y * z);
	vector<vector<string>> land(z, vector<string>(y));
	loop(z) {
		vloop(j, y) {
			cin >> land[i][j];
			vloop(k, x) {
				if (land[i][j][k] == 'x') {
					if (i and land[i - 1][j][k] == 'x') join(coortoint(k, j, i), coortoint(k, j, i - 1));
					if (j and land[i][j - 1][k] == 'x') join(coortoint(k, j, i), coortoint(k, j - 1, i));
					if (k and land[i][j][k - 1] == 'x') join(coortoint(k, j, i), coortoint(k - 1, j, i));
				}
			}
		}
	}
	vector<vector<set<int>>> gs(y, vector<set<int>>(x));
	int ans = 0;
	loop(z) {
		vloop(j, y) {
			vloop(k, x) {
				if (land[i][j][k] == 'x') gs[j][k].insert(find(coortoint(k, j, i)));
				if (i == z - 1) {
					int aux = 0;
					each(q, gs[j][k]) {
						aux += sz[q];
					}
					ans = max(ans, aux);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

