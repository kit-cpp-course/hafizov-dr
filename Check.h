#pragma once
/*Проверка подлиннойсти полученной ранее подписи*/
#include"Point.h"
#include"MainData.h"
#include"stdafx.h"

class Check
{
private:
	int z = 0;
	int r = 0;
	int s = 0;

	Data data;
	int n = data.Level(); /*Получение из класса данных размерность поля*/
	int p = data.Field();/*Получение размерности поля*/
	Point Ha = data.PublicKey();/*Получение из класса данных открытого ключа*/
	Point G = data.State(); /*Получение координаты опорной точки*/

public:
	Check(int z, int r, int s) : z(z), r(r), s(s) {}; /*Создание экзепояра класса
													  с определеннымии параметрами*/
    
	/*Нахождение элемента, обратного данному по модулю*/
	int Invert(int value);

	/*Нахождения модуля от числа в рамках модульной арифметики*/
	int FindOther(int a, int b);

	/*Вычисление суммы двух точек*/
	Point Sum(Point P, Point Q);

	/*Вычисление скалярного умножения точки на число*/
	Point Function(int n, Point P);

	/*Проверка корректности функции*/
	bool IsCorrect();
};