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

typedef tuple<int, int, int> tp;

bool cres(tp& a, tp& b) {
	return get<1>(a) < get<1>(b);
}
bool decr(tp& a, tp& b) {
	return get<1>(a) > get<1>(b);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<tp> men, maj;
	int x, y;
	loop(n) {
		cin >> x >> y;
		(x < y ? men : maj).emplace_back(x, y, i);
	}
	bool p = men.size() < maj.size();
	auto& v = p ? maj : men;
	sort(v.begin(), v.end(), p ? cres : decr);
	cout << v.size() << endl;
	int id;
	each(x, v) {
		tie(ignore, ignore, id) = x;
		cout << id + 1 << " ";
	}
	cout << endl;
	return 0;
}

