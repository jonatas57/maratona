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

ll convert(string a) {
    ll ans = 0;
    for (char c : a) {
	if (c == '.') continue;
	ans *= 10;
	ans += c - '0';
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    int x = a.find('.'), y = b.find('.');
    if (x == string::npos) x = a.length(), a += '.';
    if (y == string::npos) y = b.length(), b += '.';
    x = a.length() - x;
    y = b.length() - y;
    if (x < y) a += string(y - x, '0');
    else b += string(x - y, '0');
    ll p = convert(a), q = convert(b);
    cout << p / q << endl;
    return 0;
}

