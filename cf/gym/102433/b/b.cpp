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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vi cnt(k + 1, 0), a(n);
  loop(n) cin >> a[i], cnt[a[i]]++;
  vi ans;
  vb used(k + 1, false);
  each(x, a) {
    if (!used[x]) {
      if (ans.empty()) ans.push_back(x);
      else {
        while (!ans.empty() and ans.back() > x and cnt[ans.back()]) used[ans.back()] = false, ans.pop_back();
        ans.push_back(x);
      }
      used[x] = true;
    }
    cnt[x]--;
  }
  each(x, ans) cout << x << " ";
  cout << endl;
  return 0;
}

