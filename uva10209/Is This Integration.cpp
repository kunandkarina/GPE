#include <bits/stdc++.h>
#define pi M_PI
using namespace std;

int main()
{
	double a;
	while (cin >> a)
	{
		double squar = (a * a) - (a * a * pi) / 12 * 2 - (sqrt(3) / 4) * a * a;
		double dot = (a * a) - 2 * squar - (a * a * pi) / 4;
		double spline = (a * a) - 4 * squar - 4 * dot;
		// printf( "%.3lf %.3lf %.3lf\n", spline, 4*dot, 4*squar );
		cout << fixed << setprecision(3) << spline << " " << 4 * dot << " " << 4 * squar << "\n";
	}
}
