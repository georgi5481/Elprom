//C system includes

//C++ system includes
#include<iostream>
#include<cstdint>
#include<string>
//3rd-party includes

//own include
#include"FileReader.h"



int32_t main(){
	printf("please enter the file name : ");
	std::string enterFileName;
	std::string pathOfFile;
	std::cin >> enterFileName;
	pathOfFile = "./files/" + enterFileName;


	FileReader openTheFile(pathOfFile);

	return  EXIT_SUCCESS;
}
