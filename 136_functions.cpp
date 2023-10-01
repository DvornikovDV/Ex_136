//Дворников Даниил ИВТ-22
#include <iostream>
#include <fstream>
#include <cmath>
#include <numbers>
#include <vector>

using namespace std;
using std::numbers::pi;

namespace math_and_files {
	/// Заполнение массива arr длины n случайными числами
	void fill_arr(vector <float>& arr) {
		for (unsigned i = 0; i < arr.size(); i++) { // числа от -50 до 50 с 2 знаками после запятой
			arr[i] = (rand() % 101 - 50) + ((rand() % 201 - 100) / 100.0);
		}
	}
	void fill_arr(float arr[], int n) {
		for (unsigned i = 0; i < n; i++) { // числа от -50 до 50 с 2 знаками после запятой
			arr[i] = (rand() % 101 - 50) + ((rand() % 201 - 100) / 100.0);
		}
	}

	/// Вывод массива arr длины n
	void output_arr(vector <float>& arr) {
		for (unsigned i = 0; i < arr.size(); i++) {
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
	void output_arr(float arr[], int n) {
		for (unsigned i = 0; i < n; i++) {
			cout << arr[i] << "\t";
		}
		cout << endl;
	}

	/// Вычисление: синус( модуль суммы элементов массива arr длины n )
	float calc_sin(vector <float>& arr) {
		float sum_arr = 0.0;
		for (unsigned i = 0; i < arr.size(); i++) {
			sum_arr += arr[i];
		}              //преобразование градусов в радианы  
		return sin(abs(sum_arr) * pi / 180.0);
	}
	float calc_sin(float arr[], int n) {
		float sum_arr = 0.0;
		for (unsigned i = 0; i < n; i++) {
			sum_arr += arr[i];
		}              //преобразование градусов в радианы  
		return sin(abs(sum_arr) * pi / 180.0);
	}

	/// Чтение массива длины n из файла c именем file_name
	vector <float> f_read_arr(const string& file_name) {
		ifstream file_read(file_name);//
		vector <float> a;
		int n = 0;
		if (file_read.is_open()) {
			file_read >> n;

			a.resize(n); // Выделение памяти для массива

			for (unsigned i = 0; i < n; i++) {
				file_read >> a[i];
			}
		}
		else {
			throw invalid_argument("No such file in directory");
		}

		file_read.close();

		return a;
	}
	float* f_read_arr(int& n, const string& file_name) {
		ifstream file_read(file_name);//
		float* a;

		if (file_read.is_open()) {
			file_read >> n;

			a = new float[n]; // Выделение памяти для массива

			for (unsigned i = 0; i < n; i++) {
				file_read >> a[i];
			}
		}
		else {
			throw invalid_argument("No such file in directory");
		}

		file_read.close();

		return a;
	}

	/// Запись массива arr длины n в файл с именем file_name
	void f_save_arr(vector <float>& arr, const string& file_name) {
		ofstream file_write(file_name);

		if (file_write.is_open()) {
			file_write << arr.size() << endl;

			for (unsigned i = 0; i < arr.size(); i++) {
				file_write << arr[i] << " ";
			}
		}
		else {
			throw invalid_argument("Access error - unable to create file");
		}

		file_write.close();
	}
	void f_save_arr(float arr[], int n, const string& file_name) {
		ofstream file_write(file_name);

		if (file_write.is_open()) {
			file_write << n << endl;

			for (unsigned i = 0; i < n; i++) {
				file_write << arr[i] << " ";
			}
		}
		else {
			throw invalid_argument("Access error - unable to create file");
		}

		file_write.close();
	}
}