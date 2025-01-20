#include <iostream>
#include <iomanip>

using namespace std;

double static module(double u) {
	return u > 0 ? u : -u;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "u(i) = (-1)^i * x^(2*i+1) / (2*i+1)!\nНайти: u(i), s(i)\n"
		<< "Автор: Николаев Вячеслав Алексеевич, группа 4335, версия: 3.0\n"
		<< "Даты:\nНачало: 19.01.2025\nКонец: 19.01.2025\n";
	unsigned int N = 1000, i = 0;
	double *pu, *ps, x, eps, u;
	do {
		if (i == 3) {
			cout << "Ошибка! Число введено неверно!\n";
			return 0;
		}
		if (i != 0) {
			cout << "Ошибка! Эпсилон введен неверно!\n"
				<< "Попробуйте снова(Осталось " << 3 - i << "x)\n";
		}
		cout << "Введите eps[> 1e-15]: ";
		cin >> eps;
		i++;
	} while (eps >= 1e-15 || eps <= 0);

	i = 0;
	do {
		if (i == 3) {
			cout << "Ошибка! Число введено неверно!\n";
			return 0;
		}
		if (i != 0) {
			cout << "Ошибка! X введен неверно!\n"
				<< "Попробуйте снова(Осталось " << 3 - i << "x)\n";
		}
		cout << "Введите X[100,-100]: ";
		cin >> x;
		i++;
	} while (x < -100 || x > 100);

	i = 0; u = x;
	while (i < N && (module(u)) > eps) {
		u = (((-1) * x * x) / ((2 * i + 3) * (2 * i + 2))) * u;
		i++;
	}
	N = i;
	pu = new double[N + 1];
	ps = new double[N + 1];
	cout << "|" << setw(4) << "i" << setw(8) << "|"
		<< setw(15) << setprecision(6) << "u" << setw(15) << "|"
		<< setw(15) << setprecision(6) << "s" << setw(15) << "|"
		<< "\n";
	cout << "|" << string(71, '—') << "|" << "\n";

	*(pu) = x; *(ps) = *(pu);
	for (i = 0; i < N; i++) {
		*(pu + i + 1) = (((-1) * x * x) / ((2 * i + 3) * (2 * i + 2))) *  *(pu + i);
		*(ps + i + 1) = *(ps + i) + *(pu + i+ 1);
		cout << "|" << setw(4) << i << setw(8) << "|"
			<< setw(15) << setprecision(6) << *(pu + i) << setw(15) << "|"
			<< setw(15) << setprecision(6) << *(ps + i) << setw(15) << "|"
			<< "\n";
	}

	delete[] pu;
	delete[] ps;
	system("pause");
	return 0;
}
