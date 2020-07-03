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

struct poly {
	int deg;
	vi cs;
	poly(vi& c) : deg(c.size() - 1), cs(c) {}
	poly(int x) : deg(0), cs(1, x) {};
	void up(int a = 1) {
		if (a == -1) loop(deg) cs[i] = -cs[i];
		cs.push_back(0);
		deg++;
	}
	void operator+=(poly& p) {
		loop(p.deg + 1) {
			cs[deg - i] = (cs[deg - i] + p.cs[p.deg - i]) & 1;
		}
	}
	void print(ostream& os = cout) {
		os << deg << endl;
		loop(deg + 1) os << cs[deg - i] << " ";
		os << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	poly a(1), b(1);
	a.up(1);
	loop(n - 1) {
		poly c = a;
		a.up(1);
		a += b;
		b = c;
	}
	a.print();
	b.print();
	return 0;
}

