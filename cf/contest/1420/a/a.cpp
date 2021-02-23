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

ll mergesort(vector<ll>& v, int l, int r) {
  if (l == r) return 0;
  int mid = avg(l, r);
  ll ans = mergesort(v, l, mid) + mergesort(v, mid + 1, r);
  vi aux;
  for (int i = l, j = mid + 1;i <= mid or j <= r;) {
    if ((i <= mid and j <= r and v[i] <= v[j]) or j > r) aux.push_back(v[i++]);
    else aux.push_back(v[j++]), ans += mid - i + 1;
  }
  for (int i = 0;i <= r - l;i++) {
    v[i + l] = aux[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    ll n;
    cin >> n;
    vector<ll> vs(n);
    loop(n) cin >> vs[i];
    ll x = mergesort(vs, 0, n - 1);
    cout << (x <= (n * (n - 1)) / 2 - 1 ? "YES" : "NO") << endl;
  }
  return 0;
}

