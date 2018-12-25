#pragma once
#include"Point.h"
/*Класс, в котором содержатся основные параметры алгоритма*/
class Data
{
private:
	int d = 3; /*Закрытый ключ*/

public:
	int const p = 37; /*размер конечного поля*/
	Point Ha = Point(21, 20);/*Открытый ключ*/
	int const n = 7; /*порядок подгруппы*/

	Point const P = Point(23, 14);/*Случайная точка эллиптической кривой*/
	Point const G = Point(2, 34);

	int k = 5; /*случайное число из промежутка от 1 до n-1*/

	int _hash = 0; /*Хэш*//*Необходимо получить из класса, который выполняет
						  хэширование, предварительно передав туда n*/
	int r = 0; /*Часть подписи*/
	int s = 0; /*Вторая часть подписи*/

	Data() {};
	Data(int hash) : _hash(hash) {};
	
	/*метод , возвращающий публичный ключ*/
	Point PublicKey()
	{
		return Ha;
	}
	
	/*метод, возвращающий порядок подгруппы*/
	int Level()
	{
		return n;
	}

	/*метод, возвращающий размер конечного поля*/
	int Field()
	{
		return p;
	}
	/*метод, возвращающий опорную точку*/
	Point State()
	{
		return G;
	}
	
	/*метод вычисляющий элемент, остаток от деления в рамках модульной арифметики*/
	int FindOther(int aa, int bb)
	{

		int res = 1;
		if (bb == 1)
		{
			res = 0;
		}
		else if (aa < 0)
		{
			if (abs(aa) > bb)
			{
				res = abs(abs(((int)(aa / bb) - 1) * bb) + aa);
			}
			else
			{
				res = (abs(((int)(aa / bb) - 1) * bb) + aa);
			}
		}
		else if (aa > bb)
		{
			if (aa % bb == 0)
				res = 0;
			else
			{
				res = aa - ((int)(aa / bb)) * bb;
			}
		}
		else
			res = aa;
		return res;
	}

	/*Алгоритм получения подписи*/
	Point CountSomething()
	{
		r = FindOther(P.x, n);
		s = (Invert(k) * (_hash + r * d));
		s = FindOther(s, n);
		return Point(r, s);
	}

	/*Алгоритм вычисления обратного числа по модулю*/
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
};