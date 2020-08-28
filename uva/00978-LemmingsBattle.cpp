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

class comp {
  public:
  bool operator()(int a, int b) {
    return abs(a) < abs(b);
  }
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  loop(n) {
    if (i) cout << endl;
    int b, sg, sb;
    cin >> b >> sg >> sb;
    priority_queue<int, vi, comp> q[2];
    int x;
    loop(sg) cin >> x, q[0].push(x);
    loop(sb) cin >> x, q[1].push(-x);
    vi bs(b, 0);
    while (!q[0].empty() and !q[1].empty()) {
      int cnt = 0;
      loop(b) {
        if (!q[0].empty() and !q[1].empty()) {
          cnt++;
          bs[i] += q[0].top() + q[1].top();
          q[0].pop();
          q[1].pop();
        }
        else break;
      }
      loop(cnt) {
        if (bs[i]) {
          q[bs[i] < 0].push(bs[i]);
          bs[i] = 0;
        }
      }
    }
    if (!q[0].empty()) {
      cout << "green wins" << endl;
      while (!q[0].empty()) {
        cout << q[0].top() << endl;
        q[0].pop();
      }
    }
    else if (!q[1].empty()) {
      cout << "blue wins" << endl;
      while (!q[1].empty()) {
        cout << -q[1].top() << endl;
        q[1].pop();
      }
    }
    else cout << "green and blue died" << endl;
  }
	return 0;
}

