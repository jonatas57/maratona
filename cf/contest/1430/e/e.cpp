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

ll countinversion(vi& a, int l, int r) {
  if (l == r) return 0;
  int mid = avg(l, r);
  ll ans = countinversion(a, l, mid) + countinversion(a, mid + 1, r);
  vi aux;
  for (int i = l, j = mid + 1;i <= mid or j <= r;) {
    if (i > mid) aux.push_back(a[j++]);
    else if (j > r or a[i] <= a[j]) aux.push_back(a[i++]);
    else aux.push_back(a[j++]), ans += mid + 1 - i;
  }
  for (int i = l;i <= r;i++) a[i] = aux[i - l];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  string s;
  cin >> n >> s;
  int p = 0;
  map<char, queue<int>> pos;
  loop(n) pos[s[n - i - 1]].push(p++);
  vi a;
  each(c, s) {
    a.push_back(pos[c].front());
    pos[c].pop();
  }
  cout << countinversion(a, 0, n - 1) << endl;
  return 0;
}

