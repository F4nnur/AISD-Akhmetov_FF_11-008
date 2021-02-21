#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	double a, b, c, D, x, x1, x2;
	cin >> a >> b >> c;
	D = pow(b, 2) - 4 * a * c;
	if (D > 0) { x1 = (-b - sqrt(D)) / (2*a); x2 = (-b + sqrt(D)) / (2 * a); }
	if (D == 0) { x = -b / (2 * a); }
	if (D>0) {
		if (x1 > x2) { cout << x2 << endl << x1; } else { cout << x1 << endl << x2; }
	;}
	if (D == 0) { cout << x; }
	return 0;
}

