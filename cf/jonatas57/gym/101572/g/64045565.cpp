#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 5;

struct node {
	int qtd;
	int pen;
	int id;

	node (int qtd, int pen, int id) :
	 qtd(qtd), pen(pen), id(id) {}

	bool operator < (const node &x) const {
		if(qtd != x.qtd) return qtd > x.qtd;
		else if(pen != x.pen) return pen < x.pen;
		return id < x.id;
	}
};

typedef tree<node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> pqp;
pqp bag;

int a[T];
int b[T];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) bag.insert(node(0,0,i));

	while(m--) {
		int x,y;
		cin >> x >> y;
		bag.erase(node(a[x],b[x],x));
		a[x]++;
		b[x] += y;
		bag.insert(node(a[x],b[x],x));
		cout << bag.order_of_key(node(a[1],b[1],1))+1 << endl;
	}

	return 0;
}

