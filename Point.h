﻿#pragma once
/*Класс, реализующий точку*/
class Point
{
public:
	int x = 0, y = 0;
	Point() {}; /*Конструктор класса без параметров*/
	Point(int x, int y) : x(x), y(y) {};/*конструктор класса, который создает экземляр 
										данного класса с указанными параметрами*/
};