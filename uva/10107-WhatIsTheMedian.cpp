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

template<class Compare>
struct set2 {
	set<ii, Compare> s;
	int qtd = 0;

	void insert(ii x) {
		s.insert(x);
		qtd++;
	}
	ii remove() {
		ii x = *s.begin();
		s.erase(s.begin());
		qtd--;
		return x;
	}
	int top() {
		return s.begin()->first;
	}
};

set2<less<ii>> maior;
set2<greater<ii>> menor;
ll med = 0, qtd = 0;

void insert(int x) {
	if (x <= med) menor.insert({x, qtd++});
	else maior.insert({x, qtd++});
	if (maior.qtd > menor.qtd) {
		menor.insert(maior.remove());
	}
	else if (menor.qtd > maior.qtd + 1) {
		maior.insert(menor.remove());
	}
	med = menor.top();
	if (!(qtd & 1)) {
		med += (ll)maior.top();
		med >>= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll x;
	while (cin >> x) {
		insert(x);
		cout << med << endl;
	}
	return 0;
}

