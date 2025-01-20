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
		<< "Автор: Николаев Вячеслав Алексеевич, группа 4335, версия: 2.0\n"
		<< "Даты:\nНачало: 19.01.2025\nКонец: 19.01.2025\n";
	const unsigned int N = 1000;
	unsigned int i;
	double u[N], s[N], x, eps;
	i = 0;
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

	i = 0;
	u[i] = x; 
	s[i] = u[i];

	cout << "|" << setw(4) << "i" << setw(8) << "|"
		<< setw(15) << setprecision(6) << "u" << setw(15) << "|"
		<< setw(15) << setprecision(6) << "s" << setw(15) << "|"
		<< "\n";

	cout << "|" << string(71, '—') << "|" << "\n";
	cout << "|" << setw(4) << i << setw(8) << "|"
		<< setw(15) << setprecision(6) << u[i] << setw(15) << "|"
		<< setw(15) << setprecision(6) << s[i] << setw(15) << "|"
		<< "\n";

	while (i < N && (module(u[i])) > eps) {
		u[i+1] = (((-1) * x * x) / ((2 * i + 3) * (2 * i + 2))) * u[i];
		s[i+1] = s[i] + u[i+1];
		cout << "|" << setw(4) << i + 1 << setw(8) << "|"
			<< setw(15) << setprecision(6) << u[i+1] << setw(15) << "|"
			<< setw(15) << setprecision(6) << s[i+1] << setw(15) << "|"
			<< "\n";
		i++;
	}
	system("pause");
	return 0;
}
