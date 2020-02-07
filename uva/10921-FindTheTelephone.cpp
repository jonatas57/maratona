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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	map<char, char> conv = {{'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'}, {'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'}, {'M', '6'}, {'N', '6'}, {'O', '6'}, {'P', '7'}, {'Q', '7'}, {'R', '7'}, {'S', '7'}, {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'}, {'Z', '9'}};
	string s;
	while (cin >> s) {
		each(c, s) {
			if (isupper(c)) c = conv[c];
		}
		cout << s << endl;
	}
	return 0;
}

