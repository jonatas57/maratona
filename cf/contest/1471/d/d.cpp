#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);
const int N = 1000010;
ll prime[N], u[N];
int sz;

void pre() {
  u[1] = 0;
  for(ll i=2;i< N;++i) {
    if(!u[i]) u[i] = prime[sz++] = i;
    for(ll j=0;i*prime[j] < N ; ++j){
      u[i*prime[j]]=prime[j];
      if(i%prime[j]==0) break;
    }
  }
}

ll oddFact(ll x) {
  ll ans = 1;
  while (x > 1) {
    ll p = u[x];
    int cnt = 0;
    while (u[x] == p) cnt++, x /= p;
    if (cnt & 1) ans *= p;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  pre();
  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n);
    mii cnt;
    loop(n) cin >> a[i], cnt[oddFact(a[i])]++;
    int ans0 = 0, ans1 = 0;
    each(p, cnt) {
      ans0 = max(ans0, p.second);
      if (p.first != 1 and ~p.second & 1) cnt[1] += p.second, p.second = 0;
    }
    each(p, cnt) {
      ans1 = max(ans1, p.second);
    }
    int q;
    cin >> q;
    loop(q) {
      ll w;
      cin >> w;
      cout << (w ? ans1 : ans0) << endl;
    }
  }
  return 0;
}

