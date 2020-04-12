#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		long long int a, b, k;
		cin >> a >> b >> k;
		int x = k / 2;
		long long j = (k - x) * a - x * b;
		cout << j << endl;
	}
	return 0;
}
