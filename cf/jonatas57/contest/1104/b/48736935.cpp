#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)

#define pb                 push_back

int main() {
	ios_base::sync_with_stdio(false);

  int ps = 0;
  stack<char> s;
  char c = ' ';
  while ((c = getchar()) && c != '\n') {
    if (s.empty() || s.top() != c) {
      s.push(c);
    }
    else {
      ps++;
      s.pop();
    }
  }
  cout << (ps % 2 ? "Yes" : "No") << endl;
	return 0;
}
