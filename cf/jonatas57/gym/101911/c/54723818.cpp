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

bool pot(ll m) {
	while (!(m & 1)) {
		m /= 2;
	}
	return m == 1;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> q;
	ll aux;
	for (int i = 0;i < n;i++) {
		cin >> aux;
		q.push(aux);
	}
	ll cnt = 0;
	while (n != 1 && cnt >= 0) {
		ll x = q.top();
		q.pop();
		ll y = q.top();
		if (x == y) {
			q.pop();
			q.push(2 * x);
			n--;
		}
		else if (y % x == 0) {
			ll m = y / x;
			if (!pot(m)) {
				cnt = -1;
			}
			else {
				cnt++;
				q.push(2 * x);
			}
		}
		else cnt = -1;
	}
	cout << cnt << endl;
	
	return 0;
}

