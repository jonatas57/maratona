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

const ll mod = 998244353;

auto eucl(ll a, ll b) {
	if (b == 0) return make_pair(1ll, 0ll);
	ll x, y;
	tie(x, y) = eucl(b, a % b);
	return make_pair(y, x - a / b * y);
}

ll inv(ll x) {
	ll n;
	tie(n, ignore) = eucl(x, mod);
	return (n % mod + mod) % mod;
}

struct bits {
	ll z, o, a, A, d;
	bits(ll z = 1, ll o = 1, ll a = 1, ll A = 1, ll d = 4) : z(z % mod), o(o % mod), a(a % mod), A(a % mod), d(d % mod) {}

	bits operator&(bits& b) {
		bits c;
		c.z = (z * b.d + o * b.z + a * (b.z + b.A) + A * (b.z + b.a)) % mod;
		c.o =            o * b.o                                      % mod;
		c.a =           (o * b.a + a * (b.o + b.a))                   % mod;
		c.A =           (o * b.A +                   A * (b.o + b.A)) % mod;
		c.d = d * b.d % mod;
		return c;
	}
	bits operator|(bits& b) {
		bits c;
		c.z =  z * b.z                                                % mod;
		c.o = (z * b.o + o * b.d + a * (b.o + b.A) + A * (b.o + b.a)) % mod;
		c.a = (z * b.a +           a * (b.z + b.a))                   % mod;
		c.A = (z * b.A +                             A * (b.z + b.A)) % mod;
		c.d = d * b.d % mod;
		return c;
	}
	bits operator^(bits& b) {
		bits c;
		c.z = (z * b.z + o * b.o + a * b.a + A * b.A) % mod;
		c.o = (z * b.o + o * b.z + a * b.A + a * b.a) % mod;
		c.a = (z * b.a + o * b.A + a * b.z + A * b.o) % mod;
		c.A = (z * b.A + o * b.a + a * b.o + A * b.z) % mod;
		c.d = d * b.d % mod;
		return c;
	}
	void print(ostream& os = cout) {
		vector<ll> x = {z, o, a, A};
		ll y = inv(d);
		each(n, x) {
			os << n * y % mod << " ";
		}
		os << endl;
	}
};

void apply(bits& b, bits& c, char op) {
	switch (op) {
		case '&':
			b = b & c;
			break;
		case '|':
			b = b | c;
			break;
		case '^':
			b = b ^ c;
			break;
	}
}

stack<pair<bits, int>> q;
string ops;

void push(bits& b, int depth) {
	if (!q.empty() and q.top().second == depth) {
		apply(b, q.top().first, ops.back());
		ops.pop_back();
		q.pop();
		push(b, depth - 1);
	}
	else {
		q.emplace(b, depth);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		string s;
		cin >> s;
		ops = "";
		int depth = 0;
		for (int i = 0;s[i];i++) {
			if (s[i] == '(') depth++;
			else if (s[i] == ')') depth--;
			else if (s[i] == '#') {
				bits b;
				push(b, depth);
			}
			else ops += s[i];
		}
		q.top().first.print();
		q.pop();
	}
	return 0;
}

