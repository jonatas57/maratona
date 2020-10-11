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

int getrank(char c) {
  if (isdigit(c)) return c - '0';
  if (c == 'T') return 10;
  if (c == 'A') return 14;
  if (c == 'J') return 11;
  if (c == 'Q') return 12;
  return 13;
}

int n, id = 0;
vector<vector<ii>> dp(52, vector<ii>(52, {-1, -1}));
vector<string> cs, os;
int lis(int i, int j) {
  if (i == -1 or j == -1) return 0;
  if (dp[i][j].first != id) {
    dp[i][j].first = id;
    if (cs[i] == os[j]) dp[i][j].second = lis(i - 1, j - 1) + 1;
    else dp[i][j].second = max(lis(i, j - 1), lis(i - 1, j));
  }
  return dp[i][j].second;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  string s;
  loop(n) {
    cin >> s;
    cs.push_back(s);
    os.push_back(s);
  }
  vi perm = {0, 1, 2, 3};
  map<char, int> suit = {{'c', 0}, {'d', 1}, {'h', 2}, {'s', 3}};
  int ans = INF;
  do {
    loop(1 << 4) {
      sort(iter(os), [&](string& s, string& t) {
        if (suit[s[1]] == suit[t[1]]) {
          int x = getrank(s[0]), y = getrank(t[0]), z = suit[s[1]];
          return i & (1 << z) ? x < y : x > y;
        }
        return perm[suit[s[1]]] < perm[suit[t[1]]];
      });
      ans = min(ans, n - lis(n - 1, n - 1));
      id++;
    }
  } while (next_permutation(iter(perm)));
  cout << ans << endl;
  return 0;
}

