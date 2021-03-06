#include"pch.h" 
#include<iostream> 
#include<iomanip> 
#include<cmath> 
using namespace std;
const int n = 1000;
void mas_input(double mas[n], int a);
void mas_rand_input(double mas[n], int a, double r, double l);
int count(double mas[n], int a);
double min_search(double mas[n], int a);
void mas_output(double mas[n], int a);
double ref(double mas[n], double x);
void sort(double mas[n], int a);
int main()
{
	setlocale(LC_ALL, "Rus");
	double mas[n] = { '\0' };
	int a;
	char choose;
	cout << "Доброго времени суток. Будьте добры, выберить один из предложенных вариантов: \n 1 - Ввод элементов массива вручную. \n 2 - Ввод элементов рандомно." << endl;
	do {
		cin >> choose;
		if (choose != '1' && choose != '2')
		{
			cout << "Проверьте введенные данные, пожалуйста." << endl;
		}
	} while (choose != '1' && choose != '2');

	switch (choose)
	{
	case '1':
	{
		do
		{
			cout << "Введите число заполняемых яйчеек массива: ";
			cin >> a;
			cout << endl;
			if (a < 1||a>1000)
			{
				cout << "Ошибка! Число должно быть больше единицы и меньше 1000." << endl;
			}
		} while (a < 1||a>1000);
		mas_input(&mas[n], a);
		break;
	}
	case '2':
	{
		do
		{
			cout << "Введите число заполняемых яйчеек массива: ";
			cin >> a;

			cout << endl;
			if (a < 1 || a >= 1000)
			{
				cout << "Ошибка!!! Число должно быть больше единицы и меньше тысячи" << endl;
			}
		} while (a < 1 || a >= 1000);
		double r, l;
		cout << " Введите левую границу генерации" << endl;
		cin >> l;
		cout << "Введите правую границу генерации" << endl;
		cin >> r;
		if (r < l) swap(r, l);
		mas_rand_input(&mas[n], a, r , l);
		break;
	}
	};

	mas_output(&mas[n], a);
	cout << "Количество различных элеменов массива = " << count(&mas[n], a) << endl;
	double b = min_search(&mas[n], a);
	if (a != 0 && b!=0)
	{
		cout << "Произведение элементов = " << ref(&mas[n], b) << endl;
	}
	else
	{
		cout << "Невозможно посчитать произведение." << endl;
	}
	sort(&mas[n], a);
	mas_output(&mas[n], a);
	system("pause");
	return 0;
}
void mas_input(double mas[n], int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << "mas[" << i << "] = ";
		cin >> mas[i];
		cout << endl;
	}
}
void mas_rand_input(double mas[n], int a, double r, double l)
{
	srand(time(NULL));
	for (int i = 0; i < a; i++)
	{
		mas[i] = (double)rand()*(r -l +1) + l;
	}
}
int count(double mas[n], int a)
{
	int count = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (mas[i] == mas[j] && i != j)
			{
				count++;
				break;
			}

		}
	}
	return a - count;
}
double min_search(double mas[n], int a)
{
	double min;
	int number;
	min = abs(mas[0]);
	number = 0;
	for (int i = 1; i < a; i++)
	{
		if (abs(mas[i]) < min)
		{
			min = abs(mas[i]);
			number = i;
		}
	}
	return number;
}
void sort(double mas[n], int a)
{
	double temp;
	for (int i = 0; i < a; i++)
	{
		if (mas[i] <= 0 && i != 0)
		{
			for (int j = i; j > 0; j--)
			{
				if (mas[j - 1] >= 0)
				{
					temp = mas[j - 1];
					mas[j - 1] = mas[j];
					mas[j] = temp;
				}
				else break;

			}
		}

	}
}
void mas_output(double mas[n], int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << endl;
}
double ref(double mas[n], double x)
{
	double ref = 1;
	for (int i = 0; i < x; i++)
	{
		ref *= mas[i];
	}
	return ref;
}