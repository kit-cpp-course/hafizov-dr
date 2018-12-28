#pragma once
#include <iterator>
#include <fstream>
#include "IMessageProvider.h"
/*Считывание данных из файла*/
class FileMessageProvider : public IMessageProvider
{
private:
	const std::string _filename;/*Имя файла из которого мы будем извлекать соответствующий
								текст*/
public:
	FileMessageProvider(const std::string filename)
		: _filename(filename) {}

	std::vector<uint8_t> GetMessage() const override
	{
		std::ifstream fileIn(_filename, std::ios_base::binary);
		
		std::vector<char> data(
			std::istreambuf_iterator<char>(fileIn), {}
		);

		return std::vector<uint8_t>( data.begin(), data.end() );
	}
};