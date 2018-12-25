#pragma once
#include"Point.h"
/*�����, � ������� ���������� �������� ��������� ���������*/
class Data
{
private:
	int d = 3; /*�������� ����*/

public:
	int const p = 37; /*������ ��������� ����*/
	Point Ha = Point(21, 20);/*�������� ����*/
	int const n = 7; /*������� ���������*/

	Point const P = Point(23, 14);/*��������� ����� ������������� ������*/
	Point const G = Point(2, 34);

	int k = 5; /*��������� ����� �� ���������� �� 1 �� n-1*/

	int _hash = 0; /*���*//*���������� �������� �� ������, ������� ���������
						  �����������, �������������� ������� ���� n*/
	int r = 0; /*����� �������*/
	int s = 0; /*������ ����� �������*/

	Data() {};
	Data(int hash) : _hash(hash) {};
	
	/*����� , ������������ ��������� ����*/
	Point PublicKey()
	{
		return Ha;
	}
	
	/*�����, ������������ ������� ���������*/
	int Level()
	{
		return n;
	}

	/*�����, ������������ ������ ��������� ����*/
	int Field()
	{
		return p;
	}
	/*�����, ������������ ������� �����*/
	Point State()
	{
		return G;
	}
	
	/*����� ����������� �������, ������� �� ������� � ������ ��������� ����������*/
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

	/*�������� ��������� �������*/
	Point CountSomething()
	{
		r = FindOther(P.x, n);
		s = (Invert(k) * (_hash + r * d));
		s = FindOther(s, n);
		return Point(r, s);
	}

	/*�������� ���������� ��������� ����� �� ������*/
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