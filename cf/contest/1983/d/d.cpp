#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

ll merge(vi& a, int l, int m, int r) {
  vi a2;
  ll inv = 0;
  for (int i = l, j = m + 1;i <= m or j <= r;) {
    if (i > m) a2.push_back(a[j++]);
    else if (j > r) a2.push_back(a[i++]);
    else if (a[i] <= a[j]) a2.push_back(a[i++]);
    else {
      a2.push_back(a[j++]);
      inv += m + 1 - i;
    }
  }
  for (int i = 0, j = l;i < r - l + 1;i++, j++) a[j] = a2[i];
  return inv;
}

ll mergeSort(vi& a, int l, int r) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  ll ans = 0;
  ans += mergeSort(a, l, mid);
  ans += mergeSort(a, mid + 1, r);
  ans += merge(a, l, mid, r);
  return ans;
}

ll countInv(vi a) {
  return mergeSort(a, 0, a.size() - 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, int> cnt;
    loop(n) cin >> a[i], cnt[a[i]]++;
    loop(n) cin >> b[i], cnt[b[i]]--;
    bool ok = true;
    for (auto& [k, v] : cnt) if (v) ok = false;
    cout << (!ok or abs(countInv(a) - countInv(b)) % 2 ? "NO" : "YES") << endl;
  }
  return 0;
}

