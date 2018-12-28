#pragma once
/*Интерфейс считывания информации*/
#include"stdafx.h"
#include <vector>

class IMessageProvider 
{
public:
	virtual std::vector<uint8_t> GetMessage() const = 0; /*Виртуальный
														 метод, возвращающий текст
														 из файла ( данном случае 
														 небольшое сообщение)*/
	virtual ~IMessageProvider() = default;/*Деструктор*/
};
