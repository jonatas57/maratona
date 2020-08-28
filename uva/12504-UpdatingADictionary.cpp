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

map<string, string> parse(string& s) {
  map<string, string> ans;
  bool v = false;
  string key = "", val = "";
  for (int i = 1;s[i];i++) {
    if (s[i] == ':') v = true;
    else if (s[i] == ',' or s[i] == '}') {
      if (key != "" and val != "") ans[key] = val;
      key = val = "";
      v = false;
    }
    else if (v) val += s[i];
    else key += s[i];
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  vloop(k, t) {
    string s, t;
    cin >> s >> t;
    map<string, string> old = parse(s), nw = parse(t);
    auto i = old.begin(), j = nw.begin();
    vector<string> add, rem, chn;
    while (i != old.end() or j != nw.end()) {
      if (i != old.end() and j != nw.end() and i->first == j->first) {
        if (i->second != j->second) chn.push_back(i->first);
        i++;
        j++;
      }
      else if (i == old.end() or (j != nw.end() and i->first > j->first)) {
        add.push_back(j->first);
        j++;
      }
      else if (j == nw.end() or (i != old.end() and i->first < j->first)) {
        rem.push_back(i->first);
        i++;
      }
    }
    bool c = true;
    if (!add.empty()) {
      c = false;
      bool f = true;
      each(s, add) cout << (f ? "+" : ",") << s, f = false;
      cout << endl;
    }
    if (!rem.empty()) {
      c = false;
      bool f = true;
      each(s, rem) cout << (f ? "-" : ",") << s, f = false;
      cout << endl;
    }
    if (!chn.empty()) {
      c = false;
      bool f = true;
      each(s, chn) cout << (f ? "*" : ",") << s, f = false;
      cout << endl;
    }
    if (c) cout << "No changes" << endl;
    cout << endl;
  }
	return 0;
}

