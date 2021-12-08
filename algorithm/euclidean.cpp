#include <iostream>
using namespace std;

int gcd(int m, int n)
{
	int p;
	while (n != 0)
	{
		p = m % n;
		m = n;
		n = p;
	}
	return m;
}

int main() {
    int testCase;

    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int m, n;
        cin >> m >> n;

        cout << gcd(m,n) << endl;
    }
}