#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);


int ehPrimo(int n) {
    for(int i = 2; i*i <= n; i++) {
	if(n%i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >>n;
    if(n == 1) cout <<"YES" <<endl;
    if(n > 1 and n < 6) cout <<"NO" <<endl;
    if(n >= 6) cout <<(ehPrimo(n)?"NO":"YES") <<endl;

    return 0;
}

