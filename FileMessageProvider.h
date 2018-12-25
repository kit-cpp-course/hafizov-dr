#pragma once
#include <iterator>
#include <fstream>
#include "IMessageProvider.h"
/*���������� ������ �� �����*/
class FileMessageProvider : public IMessageProvider
{
private:
	const std::string _filename;
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