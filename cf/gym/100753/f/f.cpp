#include <bits/stdc++.h>
using namespace std;

#define pb    push_back
#define eb    emplace_back
#define mk    make_pair
#define fi    first
#define se    second
#define endl    '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e7+2;
bitset<T> crivo;
vector<ll> primes;

mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

__int128 xp(__int128 b, ll e, __int128 n) {
  if (e == 0) return 1;
  __int128 c = xp(b, e >> 1, n);
  c *= c;
  c %= n;
  if (e & 1) c = c * b % n;
  return c;
}

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

void init() {
  for(int i = 2; i < T; i++) {
    if(!crivo[i]) {
      primes.pb(i);
      for(int j = i+i; j < T; j += i) crivo[j] = 1;
    }
  }
}

ll decop(ll x) {
  ll ans = 1;

  for(int i = 0; i < (int)primes.size() and primes[i]*primes[i] <= x; i++) {
    ll tmp = 0;
    while(x % primes[i] == 0) tmp++, x /= primes[i];
    ans *= (tmp+1);
  }

  if (x > 1) {
    if (x < T) ans *= 2;
    else {
      ll y = sqrt(x);
      if (y * y == x or (y + 1) * (y + 1) == x) ans *= 3;
      else if (miller(x)) ans *= 2;
      else ans *= 4;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  ll n;
  cin >> n;
  cout << decop(n) << endl;
  return 0;
}
