#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

void yes() {
	cout <<"Yes" <<endl;
	exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);

    ll v[3], w, h;
	cin >>v[0] >>v[1] >>v[2] >>w >>h;
	sort(v, v+3);

    do {
		if(2*v[0] + 2*v[2] <= w and 2*v[0] + v[1] <= h) yes();
		if(2*v[0] + 2*v[2] <= h and 2*v[0] + v[1] <= w) yes();
		if(v[0]+v[1] <= w and 3*v[2] + v[0] + v[1] <= h) yes();
		if(v[0]+v[1] <= h and 3*v[2] + v[0] + v[1] <= w) yes();
	} while(next_permutation(v, v+3));
	
	cout <<"No" <<endl;
    return 0;
}

