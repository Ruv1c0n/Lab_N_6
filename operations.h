#pragma once
#ifndef OPERATIONS_H
#define OPERATIONS_H

//�������� ����������� �������
void input_check_size(int& size_n, int& size_m);

//�������� �������� �������
void input_check_elem(double& x, int i, int j);

//�������, ������� ������ �������� �������
double** input_matrix(int size_n, int size_m);

//������� �������� �������
void zero_matrix(double** matrix, int size_n, int size_m);

//�������� ������� ��������� �� 0
double** create_matr(int size_n, int size_m);

//����������� �������
void copy_matr(double** src, double** dst, int size_n, int size_m);

//������� �������
void free_matr(double** matrix, int size_n, int size_m);

//������� ������� ��������� �������
double** unit_matrix(int size_n);

// ������� ���������� ���������� ���������� ������� ��� i-�� ������� � j-�� ������
double** matrix_minor(double** matrix, int size_n, int str_num, int column_num);

//���������� ������������
double determinant(double** matrix, int size_n);

//������ ����������������� ������� � trans_matrix
double** transpose(double** matrix, int size_n, int size_m);

//���������� �������� �������, ���� ��� ��������
bool inverse_matrix(double** matrix, int size_n);

//������� �������� ��� ������� � ���������� ����� � matr_1
void matrix_multip(double** matr_1, double** matr_2, int size_n);

//��������� ������� �� ����������� ��������
void matrix_const_multip(int constant, double** matrix, int size_n);

//������� ���������� �������  � ���������� ����� � matr_1
void matrix_add(double** matr_1, int size_n_1, int size_m_1, double** matr_2, int size_n_2, int size_m_2, bool operation);

//����� �������
void output_matr(double** matr, int size_n, int size_m);

//����������� �  ������� ����������� ��������
void matrix_const_add(int constant, double** matrix, int size_n, int size_m);

#endif // OPERATIONS_H
