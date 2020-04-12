#include <bits/stdc++.h>

using namespace std;

#define loop(x)					for(int i = 0;i < x;i++)

int main() {
	ios_base::sync_with_stdio(false);

  int t, n;
  cin >> t;
  loop(t) {
    cin >> n;
    int x = n / 7;
    x += (n % 7 ? 1 : 0);
    cout << x << endl;
  }
	return 0;
}
