#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout <<#x <<" = " <<x <<endl;
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;

	while(tc--) {
		int n;
		cin >>n;
		ll maior;
		cin >>maior;
		ll sum = maior;
		for(int i = 1; i < n; i++) {
			ll a; cin >>a;
			sum += a;
			maior = __gcd(maior, a);
		}
		cout <<sum <<' ' <<maior <<endl;
	}
	
	return 0;
}

