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
	sz.resize(x);
	loop(x) id[i] = i, sz[i] = 1;
}
int find(int x) {
	return (x == id[x] ? x : id[x] = find(id[x]));
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	return 0;
}
