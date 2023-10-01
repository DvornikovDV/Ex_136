//Дворников Даниил ИВТ-22
#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace math_and_files {
	/// Заполнение массива arr длины n случайными числами
	void fill_arr(vector <float>& arr);
	void fill_arr(float arr[], int n);

	/// Вывод массива arr длины n
	void output_arr(vector <float>& arr);
	void output_arr(float arr[], int n);

	/// Вычисление: синус( модуль суммы элементов массива arr длины n )
	float calc_sin(vector <float>& arr);
	float calc_sin(float arr[], int n);

	/// Чтение массива длины n из файла c именем file_name
	vector <float> f_read_arr(const string& file_name);
	float* f_read_arr(int& n, const string& file_name);

	/// Запись массива arr длины n в файл с именем file_name
	void f_save_arr(vector <float>& arr, const string& file_name);
	void f_save_arr(float arr[], int n, const string& file_name);
}