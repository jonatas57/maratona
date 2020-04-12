#include <iostream>
#include <map>
#include <cmath>
#define rep(a, b, c) for (int i = a;i < b;i += c)

using namespace std;

typedef map<int, int> mii;

int main() {
	int n, k;
	mii ut;
	int maxi = 0;
	cin >> n >> k;
	rep(0, n, 1) {
		int x;
		cin >> x;
		ut[x]++;
		if (maxi < ut[x]) maxi = ut[x];
	}
	int dish = ceil((double)maxi / k), qtd = 0;
	dish *= k;
	for (mii::iterator i = ut.begin();i != ut.end();i++) {
		qtd += dish - i->second;
	}
	cout << qtd << endl;
	return 0;
}
