//Дворников Даниил ИВТ-22
#include <iostream>
#include <time.h>
#include <cmath>
#include <exception>
#include <vector>

// Pаскомментировать строку ниже, чтобы отключить assert()
//#define NDEBUG
#include <cassert>
#include "136_headers.h"

using namespace std;
using namespace math_and_files;

// Погрешность вычислений для проверки работы программы
const float eps = 1e-6;

int main() {
	{ // Блок проверки работы calc_sin
		vector <float> a{ 12.44, -6.02 };

		assert(fabs(calc_sin(a) - 0.11181582) < eps);

		a[0] = 53.1; a[1] = -84.77;
		assert(fabs(calc_sin(a) - 0.5250261) < eps);

		a[0] = 53.1; a[1] = -53.1;
		assert(fabs(calc_sin(a)) < eps);

		a.clear();
	}
	srand(time(0)); // Ключ генерации чисел - текущее время


	char char_choice = ' '; // Символ для ветвления способа задания массива
	vector <float> a; // Определение массива

	int n = 0; // Количество элементов
	cout << "To create a new array, enter: 'c'" << endl << "To read an array from a file, enter: 'f'" << endl;
	cin >> char_choice;

	if (char_choice == 'f') {
		string file_name;
		cout << "Input filename (*.txt): ";
		cin >> file_name;

		try {
			a = f_read_arr(file_name);
		}
		catch (const invalid_argument& error) {
			cout << error.what();
		}
	}
	else {
		while (n <= 0) {
			cout << "Input length of array (n > 0): n = ";
			cin >> n;
		}

		a.resize(n);

		fill_arr(a);
	}

	output_arr(a);

	cout << "Result: " << calc_sin(a) << endl; // Вывод результата

	cout << "To save the array, enter: 's'" << endl << "To finish, enter any other key" << endl;
	cin >> char_choice;

	if (char_choice == 's') {
		string file_name;
		cout << "Input filename (*.txt): ";
		cin >> file_name;
		try {
			f_save_arr(a, file_name);
		}
		catch (const invalid_argument& error) {
			cout << error.what();
		}
	}

	a.clear(); // Освобождение памяти от массива a
}