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

typedef tuple<int, int, int> nand;
vector<nand> ts;

int error(int s) {
	return s == -1 ? 0 : (s == 1 ? 1 : 3);
}

ll conterr(int x) {
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	int a, b, s;
	set<int> aux;
	loop(n + 1) aux.insert(i);
	loop(n) {
		cin >> a >> b >> s;
		ts.emplace(a - 1, b - 1, s);
		aux.erase(a, b);
	}
	return 0;
}

