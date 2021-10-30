struct bit {
	ll base[MAX], size;
	vector<ll> v;

	bit(vector<ll>& v) : size(v.size()), v(v) {
		memset(base, 0, sizeof base);
		loop(size) {
			update(i + 1, v[i], false);
		}
	}
	void update(ll a, ll val, bool p = true) {
		if (p) {
			val -= v[a - 1];
			v[a - 1] += val;
		}
		while (a <= size) {
			base[a] += val;
			a += a & (-a);
		}
	}
	ll query(ll x) {
		int ans = 0;
		while (x) {
			ans += base[x];
			x -= x & (-x);
		}
		return ans;
	}
	ll inter(ll l, ll r) {
		return query(r) - query(l - 1);
	}
};

