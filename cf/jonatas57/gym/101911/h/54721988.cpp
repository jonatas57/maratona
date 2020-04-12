#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	int x1, y1, x2, y2;
	cin >>x1 >>y1 >>x2 >>y2;
	
	int cont = 0;
	for(int i = 1; i <= n; i++) {
		if(i >= x1 and i <= x2) {
			cont += ((y1-1)%2);
			cont += ((m-y2)%2);
		} else {
			cont += (m%2);
		}
	}

	cout <<((cont/2)+(cont%2)) <<endl;
	return 0;
}

