#include <iostream>
#include <iomanip>

using namespace std;

float Abs(float u) {
	return u > 0 ? u : -u;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "u(i) = (-1)^i * x^(2*i+1) / (2*i+1)!\nНайти: N, S\n"
		 << "Автор: Николаев Вячеслав Алексеевич, группа 4335, версия: 2.0\n"
		 << "Даты:\nНачало: 19.01.2025\nКонец: 19.01.2025\n";
	const unsigned int N = 1000;
	unsigned int i;
	float u, s, x, eps;
	i = 0;
	do {
		if (i != 0) {
			cout << "Ошибка! Эпсилон введен неверно!\n"
				<< "Попробуйте снова(Осталось " << 3 - i << "x)\n";
		}
		cout << "Введите eps: ";
		cin >> eps;
		i++;
	} while ((i < 3) && (eps >= 1e-15 || eps <= 0));

	if ((i == 3) && (eps >= 1e-15 || eps <= 0)) {
		cout << "Ошибка! Эпсилон введен неверно!\n";
		return 0;
	}

	i = 0; u = 1; s = 1;
	do {
		if (i != 0) {
			cout << "Ошибка! X введен неверно!\n"
				<< "Попробуйте снова(Осталось " << 3 - i << "x)\n";
		}
		cout << "Введите X[100,-100]: ";
		cin >> x;
		i++;
	} while ((i < 3) && (x <= -100 || x >= 100));

	if ((i < 3) && (x <= -100 || x >= 100)) {
		cout << "Ошибка! X введен неверно!\n";
		return 0;
	}

	cout << setw(2) << "|" << setw(6) << "i" << setw(6) << "|" << setw(6) << "u" << setw(6) << "|" << setw(6) << "s" << setw(6) << "|" << "\n";
	cout << setw(2) << string(36, '—') << "\n";
	while (i < N && (Abs(u)) > eps) {
		u = u;
		s += u;
		cout << setw(2) << "|" << setw(6) << i << setw(6) << "|" << setw(6) << u << setw(6) << "|" << setw(6) << s << setw(6) << "|" << "\n";
		i++;
	}
	system("pause");
	return 0;
}
