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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a;
	stack<int> s;
	for (int next = 1;next <= 11;next++) {
		cin >> a;
		s.push(a);
	}
	for (int next = 1;next <= 11;next++) {
		int var = s.top();
		s.pop();
		double resa = sqrt(abs(var));
		double resb = pow(var, 3) * 5;
		double res = resa + resb;

		if (res <= 400) {
			printf("f(%d) = %.2f\n", var, res);
		}
		else {
			printf("f(%d) = MAGNA NIMIS!\n", var);
		}
	}
	return 0;
}

