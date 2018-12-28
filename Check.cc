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
	int p = data.Field();
	Point Ha = data.PublicKey();/*Получение из класса данных открытого ключа*/
	Point G = data.State();

public:
	Check(int z, int r, int s) : z(z), r(r), s(s) {};

	//Data data;
	//int n = data.Level(); /*Получение из класса данных размерность поля*/
	//int p = data.Field();
	//Point Ha = data.PublicKey();/*Получение из класса данных открытого ключа*/
	//Point G = data.State();
    
	/*Нахождение элемента, обратного данному по модулю*/
	int Invert(int value)
	{
		int New = 1, old = 0, q = p, r, h;
		int pos = 0;
		while (value > 0)
		{
			r = q % value;
			q = q / value;
			h = q * New + old;
			old = New;
			New = h;
			q = value;
			value = r;
			pos = !pos;
		}
		return pos ? old : (p - old);
	}

	/*Нахождения модуля от числа в рамках модульной арифметики*/
	int FindOther(int a, int b)
	{

		int res = 1;
		res = (a % b + b) % b;
		/*if (b == 1)
		{
			res = 0;
		}
		else if (a < 0)
		{
			if (abs(a) > b)
			{
				res = abs(abs(((int)(a / b) - 1) * b) + a);
			}
			else
			{
				res = (abs(( (int)(a / b) - 1) * b) + a);
			}
		}
		else if (a > b)
		{
			if (a % b == 0)
				res = 0;
			else
			{
				res = a - ((int)(a / b)) * b;
			}
		}
		else
			res = a;*/
		return res;
	}

	/*Вычисление суммы двух точек*/
	Point Sum(Point P, Point Q)
	{
		int m = 0;
		int Xr = 0, Yr = 0;
		if (P.x < Q.x)
		{
			std::swap(P.x, Q.x);
			std::swap(P.y, Q.y);
		}
		m = (P.y - Q.y) * Invert(P.x - Q.x);
		m = FindOther(m, p);

		Xr = pow(m, 2) - P.x - Q.x;
		Xr = FindOther(Xr, p);

		Yr = P.y + m * (Xr - P.x);
		Yr = FindOther(Yr, p);
		Yr = p - Yr;

		Point rs = Point(Xr, Yr);

		return rs;


	}

	/*Вычисление скалярного умножения точки на число*/
	Point Function(int n, Point P)
	{
		int a = -1;
		int p = 37;
		int m, Xr = 0, Yr = 0;

		Point P_2 = Point(Xr, Yr);

		m = (3 * pow(P.x, 2) + a) * Invert(2 * P.y);
		m = FindOther(m, p);

		Xr = pow(m, 2) - P.x - P.x;
		Xr = FindOther(Xr, p);

		Yr = P.y + m * (Xr - P.x);
		Yr = FindOther(Yr, p);
		Yr = p - Yr;

		P_2 = Point(Xr, Yr);
		Point P_R = Point(0, 0);

		for (int i = 1; i < n - 1; i++)
		{
			P_R = Sum(P_2, P);
			P_2 = P_R;
		}
		return P_2;

	}

	/*Проверка корректности функции*/
	bool IsCorrect()
	{
		
		int u1 = Invert(s) * z;
		u1 = FindOther(u1, n);
		
		int u2 = Invert(s) * r;
		u2 = FindOther(u2, n);
		
		Point A;
		Point B;

		if (u1 > 1)
			A = Function(u1, G);
		else
			A = G;

		if (u2 > 1)
			B = Function(u2, Ha);
		else
			B = Ha;
		
		Point C;
		if (A.x == B.x && A.y == B.y)
			C = Function(1, A);
		else
			C = Sum(A, B);

		if (FindOther(C.x, n) == r || FindOther(C.x, n) == 0)
			return 1;
		else
			return 0;
	}


};