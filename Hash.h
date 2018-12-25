#pragma once
/*Реализация получения сокращенного хэша*/
#include"stdafx.h"
#include"sha256.h"

class HashProvider
{
private:
	const std::vector<uint8_t> _data;
	
public:
	HashProvider(std::vector<uint8_t> data): _data(data) {}
 
	int CountHash()
	{
		sha256_context context;
		sha256_starts(&context);

		uint8 hash[32];

		sha256_update(&context, const_cast<uint8_t*>(_data.data()), _data.size());
		sha256_finish(&context, hash);

		return hash[0] & 7;
	}
};