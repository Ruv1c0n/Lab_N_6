#pragma once
#ifndef OPERATIONS_H
#define OPERATIONS_H

//Проверка размерности матрицы
void input_check_size(int& size_n, int& size_m);

//Проверка элемента матрицы
void input_check_elem(double& x, int i, int j);

//Функция, которая вводит элементы матрицы
double** input_matrix(int size_n, int size_m);

//Функция зануляет матрицу
void zero_matrix(double** matrix, int size_n, int size_m);

//Создание матрицы состоящей из 0
double** create_matr(int size_n, int size_m);

//Копирование матрицы
void copy_matr(double** src, double** dst, int size_n, int size_m);

//Очистка матрицы
void free_matr(double** matrix, int size_n, int size_m);

//Функция создает единичную матрицу
double** unit_matrix(int size_n);

// Функция возвращает подматрицу квадратной матрицы без i-го столбца и j-ой строки
double** matrix_minor(double** matrix, int size_n, int str_num, int column_num);

//Вычисление определителя
double determinant(double** matrix, int size_n);

//Запись транспонированной матрицы в trans_matrix
double** transpose(double** matrix, int size_n, int size_m);

//Нахождение обратной матрицы, если это возможно
bool inverse_matrix(double** matrix, int size_n);

//Функция умножает две матрицы и записывает ответ в matr_1
void matrix_multip(double** matr_1, double** matr_2, int size_n);

//Умножение матрицы на константное значение
void matrix_const_multip(int constant, double** matrix, int size_n);

//Функция складывает матрицы  и записывает ответ в matr_1
void matrix_add(double** matr_1, int size_n_1, int size_m_1, double** matr_2, int size_n_2, int size_m_2, bool operation);

//Вывод матрицы
void output_matr(double** matr, int size_n, int size_m);

//Прибавление к  матрице константное значение
void matrix_const_add(int constant, double** matrix, int size_n, int size_m);

#endif // OPERATIONS_H
