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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  const int N = 40000;
  vi prime;
  vb isprime(N + 1, true);
  for (int i = 2;i <= N;i++) {
    if (isprime[i]) {
      prime.push_back(i);
      for (int j = i + i;j <= N;j += i) isprime[j] = false;
    }
  }

  int t;
  cin >> t;
  loop(t) {
    int d;
    cin >> d;
    int x = *lower_bound(iter(prime), d + 1);
    int y = *lower_bound(iter(prime), x + d);
    cout << x * y << endl;
  }
  return 0;
}

