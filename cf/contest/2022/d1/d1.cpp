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

int ask(int i, int j) {
  cout << "? " << i + 1 << " " << j + 1 << endl;
  cout.flush();
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    int imp = -1;
    int m = n & 1 ? n : n - 2;
    for (int i = 0;i + 1 < m;i += 2) {
      int a = ask(i, i + 1);
      int b = ask(i + 1, i);
      if (a != b) {
        int j = i == 0 ? 2 : i - 1;
        int c = ask(i, j);
        int d = ask(j, i);
        if (c != d) imp = i;
        else imp = i + 1;
        break;
      }
    }
    if (imp == -1) {
      if (n & 1) imp = n - 1;
      else {
        int i = n - 2;
        int j = n - 3;
        int c = ask(i, j);
        int d = ask(j, i);
        if (c != d) imp = i;
        else imp = i + 1;
      }
    }
    cout << "! " << imp + 1 << endl;
    cout.flush();
  }
  return 0;
}

