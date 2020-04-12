#include <bits/stdc++.h>

using namespace std;

#define loop(x)					for(int i = 0;i < x;i++)

bool palin(string s) {
  int l = s.length();
  int hl = l / 2;
  bool p = true;
  for (int i = 0;i < hl && p;i++) {
    p = p && (s[i] == s[l - i - 1]);
  }
  return p;
}

int main() {
	ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  string s;
  loop(t) {
    cin >> s;
    if (palin(s)) {
      sort(s.begin(), s.end());
    }
    cout << (palin(s) ? "-1" : s) << endl;
  }
	return 0;
}
