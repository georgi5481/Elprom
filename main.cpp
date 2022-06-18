//C system includes

//C++ system includes
#include<iostream>
#include<cstdint>
#include<string>

#include <locale>
#include <codecvt>
#include <cassert>


//3rd-party includes

//own include
#include"FileReader.h"






int32_t main(){

	 std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
	 std::string u8str = converter.to_bytes(0x20ac);
	 assert(u8str == "\xe2\x82\xac");


	printf("please enter the file name : ");
	std::string enterFileName;
	std::string pathOfFile;
	std::cin >> enterFileName;
	pathOfFile = "./files/" + enterFileName;


	FileReader openTheFile(pathOfFile);
	openTheFile.saveFilledFile();

	return  EXIT_SUCCESS;
}
