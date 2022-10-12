#include "Big.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (long long i = -10; i < 10; ++i)
	{
		for (long long j = -10; j < 10; ++j)
		{
			Big a(i), b(j);
			if ((a * b) != Big(i * j))
			{
				cout << i << "*" << j << "=" << i * j << endl << a << "*" << b << "=" << Big(a * b) << endl;
				return 0;
			}
			if ((a - b) != Big(i - j))
			{
				cout << i << "-" << j << "=" << i - j << endl << a << "-" << b << "=" << Big(a - b) << endl;
				return 0;
			}
			if ((a + b) != Big(i + j))
			{
				cout << i << "+" << j << "=" << i + j << endl << a << "+" << b << "=" << Big(a + b) << endl;
				return 0;
			}
			if (b != 0 && (a / b != Big(i / j)))
			{
				cout << i << "/" << j << "=" << i / j << endl << a << "/" << b << "=" << Big(a / b) << endl;
				return 0;
			}
			if (b != 0 && (a % b != Big(i % j)))
			{
				cout << i << "%" << j << "=" << i % j << endl << a << "%" << b << "=" << Big(a % b) << endl;
				return 0;
			}
		}
	}
	cout << "Корректно";
	return 0;
}
