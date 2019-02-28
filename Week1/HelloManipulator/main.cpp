#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x = 2000.0;

	cout << setprecision(2) << showpoint << fixed;

	for (int i = 0; i < 20; i++)
	{
		cout << setw(3) << i;
		cout << setw(12) << x * i << endl;
	}

	int i;
	cin >> i;
	
	return 0;
}