#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include<iostream>
#include<ctime>
using namespace std;
void create(int* a, const int size, int i)
{
	cout << "a[" << i << "] = ";
	cin >> a[i];
	cout << endl;
	if (i < size - 1)
		create(a, size, i + 1);
}
int product(int* a, const int size, int i, int d)
{
	if ((i % 2) == 0)
	{
		d *= a[i];
	}
	if (i < size - 1)
		product(a, size, i + 1, d);
	else

		return d;
	
}

int Number_i(int* a, const int size, int k)
{
	if (a[k] == 0)
		return k;

	if (k <= size - 1)
		Number_i(a, size, k + 1);
	else return -1;
}

int Number_j(int* a, const int size, int k)
{
	if (a[k] == 0)
		return k;

	if (k >= 0)
		Number_j(a, size, k - 1);
	else return -1;
}

int Sum_zero(int* a, int i, int j)
{
	if ((i == -1) || (j == -1) || (i == j) || (j - i == 1))
		return 0;
	if (i < j)
		return a[i + 1] + Sum_zero(a, i + 1, j);
	else return 0;

}

void PlusMinus(int* a, const int size, int k, bool t, int c)
{
	
	if (k < size - 1)
	{
		if (a[k] >= 0)
			PlusMinus(a, size, k + 1, t, 0);
		if ((a[k] < 0) && (a[k + 1]) < 0)
			PlusMinus(a, size, k + 1, t, 0);
		if ((a[k] < 0) && (a[k + 1] >= 0))
		{
			c = a[k];
			a[k] = a[k + 1];
			a[k + 1] = c;
			t = true;
		}

	}

	if (t)
		PlusMinus(a, size, 0, false, 0);
	
	
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}



int main()
{
	int i, j;
	int size = 100;
	int* arr = new int[size];
	cout << "enter array size = " ;
	cin >> size; cout<< endl;
	create(arr, size, 0);
	cout << "product = " << product(arr, size, 0, 1) << endl;
	i = Number_i(arr, size, 0);
	j = Number_j(arr, size, size - 1);

	cout << "suma = " << Sum_zero(arr, i, j) << endl;
	PlusMinus(arr, size, 0, false, 0);
	Print(arr, size, 0);
	delete[]arr;
	return 0;
}

