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
const ll lim = 10000000000000000ll;

struct bigint {
	int size;
	vector<ll> a;
	bigint(ll x = 0) : size(1), a(1, x) {}
	bigint operator+(bigint x) {
		bigint c;
		int l = max(size, x.size);
		int carry = 0;
		c.a.resize(l);
		loop(l) {
			ll m = i < size ? a[i] : 0;
			ll n = i < x.size ? x.a[i] : 0;
			c.a[i] = m + n + carry;
			carry = 0;
			if (c.a[i] >= lim) c.a[i] -= lim, carry = 1;
		}
		if (carry) c.a.push_back(1);
		c.size = c.a.size();
		return c;
	}
	void operator=(ll x) {
		a.clear();
		a.push_back(x);
	}
	bool operator==(ll x) {
		return size == 1 and x == a[0];
	}
};

ostream& operator<<(ostream& os, bigint x) {
	os.fill('0');
	loop(x.size) {
		os << setw(i ? 16 : 0) << x.a[x.size - i - 1];
	}
	return os;
}

vector<bigint> fib(5001, -1);
bigint fibo(int x) {
	if (fib[x] == -1) {
		if (x <= 1) fib[x] = x;
		else fib[x] = fibo(x - 1) + fibo(x - 2);
	}
	return fib[x];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int x;
	while (cin >> x) {
		cout << "The Fibonacci number for " << x << " is " << fibo(x) << endl;
	}
	return 0;
}

