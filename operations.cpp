#include<iostream>
#include<cstdio>
#include"operations.h"
using namespace std;
const double EPS = 0.0000000001;

//�������� ����������� ������� 
void input_check_size(int& size_n, int& size_m) {
	cin >> size_n >> size_m;
	while (cin.fail() || size_n > 1000 || size_n <= 1 || size_m > 1000 || size_m <= 1) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Try again. \n";
		cin >> size_n >> size_m;
	}
}

//�������� �������� �������
void input_check_elem(double& x, int i, int j) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Try again. \n elem[" << i + 1 << "][" << j + 1 << "]=";
		cin >> x;
	}
}

//�������, ������� ������ �������� �������
double** input_matrix(int size_n, int size_m) {
	double elem;
	double** matrix = create_matr(size_n, size_m);
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_m; j++) {
			cout << "matrix_elem[" << i + 1 << "][" << j + 1 << "]=";
			cin >> elem;
			input_check_elem(elem, i, j);
			matrix[i][j] = elem;
			/*	if (size_n == 1 && size_m == 1)
					break;*/
		}
	return matrix;
}

//������� �������� �������
void zero_matrix(double** matrix, int size_n, int size_m) {
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_n; j++)
			matrix[i][j] = 0;
}

//�������� ������� ��������� �� 0
double** create_matr(int size_n, int size_m) {
	double** res_matr = new double* [size_n];
	for (int i = 0; i < size_n; i++)
		res_matr[i] = new double[size_m];
	zero_matrix(res_matr, size_n, size_m);
	return res_matr;
}


//����������� �������
void copy_matr(double** src, double** dst, int size_n, int size_m) {
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_m; j++)
			src[i][j] = dst[i][j];
}

//������� ������
void free_matr(double** matrix, int size_n, int size_m) {
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < 0; j++)
			matrix[i][j] = 0;
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
}

//������� ������� ��������� �������
double** unit_matrix(int size_n) {
	double** u_matrix = create_matr(size_n, size_n);
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_n; j++)
			if (i == j)
				u_matrix[i][j] = 1;
			else
				u_matrix[i][j] = 0;
	return u_matrix;
}

// ������� ���������� ���������� ���������� ������� ��� i-�� ������� � j-�� ������
double** matrix_minor(double** matrix, int size_n, int str_num, int column_num) {
	double** minor = create_matr(size_n, size_n);
	int minor_string = 0, minor_column = 0;
	for (int i = 0; i < size_n; i++) {
		if (i == str_num)
			continue;
		for (int j = 0; j < size_n; j++) {
			if (j == column_num)
				continue;
			minor[minor_string][minor_column++] = matrix[i][j];
			if (minor_column == size_n - 1) {
				minor_string++;
				minor_column = 0;
			}
		}
	}
	return minor;
}

//���������� ������������
double determinant(double** matrix, int size_n) {
	double answer = 0.0;
	if (size_n == 1)
		return matrix[0][0];
	if (size_n == 2) {
		answer = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		return answer;
	}
	// ������������ ���������� �� ������ ������ �������.
	for (int i = 0; i < size_n; i++) {
		double** minor = matrix_minor(matrix, size_n, 0, i);
		answer += ((i % 2 == 1) ? -1 : 1) * matrix[0][i] * determinant(minor, size_n - 1);
		free_matr(minor, size_n - 1, size_n - 1);
	}
	return answer;
}

//������ ����������������� ������� � trans_matrix
double** transpose(double** matrix, int size_n, int size_m) {
	double** trans_matrix = create_matr(size_n, size_m);
	for (int i = 0; i < size_m; i++)
		for (int j = 0; j < size_n; j++)
			trans_matrix[j][i] = matrix[i][j];
	return trans_matrix;
}

//���������� �������� �������, ���� ��� ��������
bool inverse_matrix(double** matrix, int size_n) {
	double det = determinant(matrix, size_n);
	int temp;
	//���� ������������ ����� 0, �� ����� �������� ������� �� ��������
	if (det == 0)
		return false;
	double** minors_matrix = create_matr(size_n, size_n);
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_n; j++) {
			temp = ((i + j) % 2 == 0) ? 1 : -1;
			double** minor = matrix_minor(matrix, size_n, i, j);
			minors_matrix[i][j] = temp * determinant(minor, size_n - 1) / det;
			if (abs(minors_matrix[i][j]) < EPS)
				minors_matrix[i][j] = 0;
			free_matr(minor, size_n, size_n);
		}
	}
	copy_matr(matrix, minors_matrix, size_n, size_n);
	free_matr(minors_matrix, size_n, size_n);
	return true;
}

//������� �������� ��� ������� � ���������� ����� � matr_1
void matrix_multip(double** matr_1, double** matr_2, int size_n) {
	double** res_matr = create_matr(size_n, size_n);

	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_n; j++) {
			double elem = 0;
			for (int k = 0; k < size_n; k++)
				elem += matr_1[i][k] * matr_2[k][j];
			res_matr[i][j] = elem;
		}
	}
	copy_matr(matr_1, res_matr, size_n, size_n);
	free_matr(res_matr, size_n, size_n);
}

//��������� ������� �� ����������� ��������
void matrix_const_multip(int constant, double** matrix, int size_n) {
	double** res_matr = create_matr(size_n, size_n);

	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_n; j++) {
			res_matr[i][j] = matrix[i][j] * constant;
		}
	}

	copy_matr(matrix, res_matr, size_n, size_n);
	free_matr(res_matr, size_n, size_n);
}

//������� ���������� �������  � ���������� ����� � matr_1 
void matrix_add(double** matr_1, int size_n_1, int size_m_1, double** matr_2, int size_n_2, int size_m_2, bool operation) {
	double** res_matr = create_matr(size_n_1, size_m_2);

	int temp = (operation) ? 1 : -1;
	for (int i = 0; i < size_n_1; i++)
		for (int j = 0; j < size_m_1; j++)
			res_matr[i][j] = matr_1[i][j] + temp * matr_2[i][j];

	copy_matr(matr_1, res_matr, size_n_1, size_m_1);
	free_matr(res_matr, size_n_1, size_m_2);
}

//����� �������
void output_matr(double** matr, int size_n, int size_m) {
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_m; j++)
			cout << matr[i][j] << '\t';
		cout << '\n';
	}
}

//����������� �  ������� ����������� ��������
void matrix_const_add(int constant, double** matrix, int size_n, int size_m) {
	double** res_matr = create_matr(size_n, size_m);

	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_m; j++) {
			res_matr[i][j] = matrix[i][j] + constant;
		}
	}

	copy_matr(matrix, res_matr, size_n, size_m);
	free_matr(res_matr, size_n, size_m);
}