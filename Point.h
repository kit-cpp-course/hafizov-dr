#pragma once
/*Класс, реализующий точку*/
class Point
{
public:
	int x = 0, y = 0;
	/**
	* Конструктор класса point
	*/
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};