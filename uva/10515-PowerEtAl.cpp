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

int mod(string& s, int x) {
  int r = 0;
  each(c, s) {
    r *= 10;
    r += c - '0';
    r %= x;
  }
  return r;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string M, N;
  while (cin >> M >> N and M != "0" and N != "0") {
    int m = M.back() - '0';
    if (N == "0") {
      cout << 1 << endl;
      continue;
    }
    int x = m, p = 1;
    vi d(2);
    d[0] = 1;
    d[1] = m;
    for (int i = 2;;i++) {
      x = x * m % 10;
      d.push_back(x);
      if (x == m) {
        p = i - 1;
        break;
      }
    }
    int n = (mod(N, p) + p - 1) % p;
    cout << (m * d[n] % 10) << endl;
  }
	return 0;
}

