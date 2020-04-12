#include <bits/stdc++.h>

using namespace std;

typedef long long 				ll;
typedef unsigned long long 		unll;
typedef vector<int>				vi;
typedef vector<bool>			vb;
typedef map<int, int> 			mii;
typedef pair<int, int>			ii;

#define INF 					0x3f3f3f3f
#define each(x, s) 				for(auto const& x : s)
#define rep(x, y, z)			for(int i = x;i < y;i+=z)
#define loop(x)					for(int i = 0;i < x;i++)

set<int> divisores(int n) {
	set<int> div;
	int aux = n;
	for (int i = 1;i <= aux;i++) {
		if (n % i == 0) {
			aux = n / i;
			div.insert(i);
			div.insert(aux);
		}
	}
	return div;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<long long> fun;
	
	set<int> div = divisores(n);
	each(x, div) {
		long long m = n / x;
		long long sn = ((1 + (1 + n - x)) * m) / 2;
		fun.push_back(sn);
	}


	sort(fun.begin(), fun.end());
	each(x, fun) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
