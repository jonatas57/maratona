#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

int lsb(int x) {
  return x & -x;
}

bool powerTwo(int x) {
  return x == 1 or !(x & (x - 1));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    loop(n) {
      cin >> a[i];
      s += a[i];
    }
    bool ok = false;
    if (s % n == 0) {
      ok = true;
      map<int, queue<ii>> qs;
      int avg = s / n;
      int qtd = 0;
      loop(n) {
        int del = abs(a[i] - avg);
        if (!del) continue;
        int x = lsb(del);
        int y = del + x;
        if (!powerTwo(x) or !powerTwo(y)) {
          ok = false;
          break;
        }
        if (a[i] > avg) swap(x, y);
        qs[y].emplace(x, i);
        qtd++;
      }
      if (ok and !qs.empty()) {
        int st = qs.begin()->first;
        int at = st;
        while (true) {
          auto [x, id] = qs[at].front();
          qs[at].pop();
          qtd--;
          if (qs[at].empty()) qs.erase(at);
          if (st == x) {
            if (qtd) {
              st = at = qs.begin()->first;
            }
            else break;
          }
          else if (qs.count(x)) {
            at = x;
          }
          else {
            ok = false;
            break; 
          }
        }
      }
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}

