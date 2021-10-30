// fastxp
// randomgen
bool check(ll n, ll a, ll d, ll r) {
  ll x = xp(a, d, n);
  if (x == 1 or x == n - 1) return false;;
  for (ll i = 0;i < r;i++) {
    x = xp(x, 2, n);
    if (x == n - 1) return false;
  }
  return true;
}
bool miller(ll n) {
  ll d = n - 1, r = 0;
  while (~d & 1) d >>= 1, r++;
  uniform_int_distribution<ll> rnd(2, n - 2);
  for (int i = 0;i < 50;i++) {
    ll a = rnd(gen);
    if (check(n, a, d, r)) return false;
  }
  return true;
}

