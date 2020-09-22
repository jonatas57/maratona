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

const ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  string rom = "IVXLCDM";
  vi num = {1, 5, 10, 50, 100, 500, 1000};
  map<char, int> rtoi;
  for (int i = 0;rom[i];i++) rtoi[rom[i]] = num[i];
  while (cin >> s) {
    string ans = "";
    if (isdigit(s[0])) {
      int l = s.length();
      for (int i = 0, j = (l - 1) * 2;i < l;i++, j -= 2) {
        int x = s[i] - '0';
        if (x == 9) ans += rom[j], ans += rom[j + 2];
        else if (x >= 5) ans += rom[j + 1], ans += string(x - 5, rom[j]);
        else if (x == 4) ans += rom[j], ans += rom[j + 1];
        else ans += string(x, rom[j]);
      }
    }
    else {
      vi vals(1, INF);
      each(c, s) {
        int x = rtoi[c];
        if (x > vals.back()) vals.back() = -vals.back();
        vals.push_back(x);
      }
      int sum = 0;
      for (int i = 1;s[i - 1];i++) {
        sum += vals[i];
      }
      ans = to_string(sum);
    }
    cout << ans << endl;
  }
	return 0;
}

