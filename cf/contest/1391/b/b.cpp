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

vi id, sz;
void init(int n) {
	id.resize(n);
	sz.resize(n);
	loop(n) {
		id[i] = i;
		sz[i] = 1;
	}
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
bool join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		init(n * m);
		loop(n) cin >> a[i];
		int g = n * m, ans = 0;
		loop(n) {
			vloop(j, m) {
				if (a[i][j] == 'R' and j == m - 1) a[i][j] = 'D', ans++;
				else if (a[i][j] == 'D' and i == n - 1) a[i][j] = 'R', ans++;
				if (a[i][j] == 'R' and join(i * m + j, i * m + j + 1)) g--; 
				if (a[i][j] == 'D' and join(i * m + j, (i + 1) * m + j)) g--;
			}
		}
		cout << ans + g - 1 << endl;
	}
	return 0;
}

