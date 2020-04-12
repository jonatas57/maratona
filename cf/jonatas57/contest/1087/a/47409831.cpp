#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  int l = s.length();
  string dec(l, ' ');
  if (l <= 2) cout << s << endl;
  else {
    int id = (l % 2 == 0 ? l - 2 : l - 1);
    for (int i = 0;i < l;i++) {
      dec[id] = s[i];
      if (i <= (l - 1) / 2) {
        id -= 2;
      }
      else {
        id += 2;
      }
      if (id < 0) id = 1;
    }
    cout << dec << endl;
  }
	return 0;
}
