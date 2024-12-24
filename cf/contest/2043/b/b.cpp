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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n, d;
    cin >> n >> d;
    vi a = {1};
    if (d % 3 == 0 or n > 2) a.push_back(3);
    if (d == 5) a.push_back(5);
    if (n > 2) a.push_back(7);
    else {
      int f = n;
      if (n == 3) f *= 3;
      int x = stoi(string(f, d + '0'));
      if (x % 7 == 0) a.push_back(7);
    }
    if ((d % 3 == 0 and n > 2) or d == 9 or n > 5) a.push_back(9);
    each(x, a) cout << x << " ";
    cout << endl;
  }
  return 0;
}

