//��������� ������ ���-22
#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace math_and_files {
	/// ���������� ������� arr ����� n ���������� �������
	void fill_arr(vector <float>& arr);
	void fill_arr(float arr[], int n);

	/// ����� ������� arr ����� n
	void output_arr(vector <float>& arr);
	void output_arr(float arr[], int n);

	/// ����������: �����( ������ ����� ��������� ������� arr ����� n )
	float calc_sin(vector <float>& arr);
	float calc_sin(float arr[], int n);

	/// ������ ������� ����� n �� ����� c ������ file_name
	vector <float> f_read_arr(const string& file_name);
	float* f_read_arr(int& n, const string& file_name);

	/// ������ ������� arr ����� n � ���� � ������ file_name
	void f_save_arr(vector <float>& arr, const string& file_name);
	void f_save_arr(float arr[], int n, const string& file_name);
}