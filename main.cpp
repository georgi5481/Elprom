//C system includes

//C++ system includes
#include <iostream>
#include <cstdint>

//3rd-party includes

//own include
//#include"FileReader.h"



int32_t main(){
	//FileReader openTheFile;
	printf("please enter the file name : \n");
	std::string enterFileName;
	std::cin >> enterFileName;
//	openTheFile.path = "./files/" + enterFileName;
std::string output;

	output = "./files/" + enterFileName;

	std::cout << output << std::endl;

	std::getline(std::cin,enterFileName);
	return  EXIT_SUCCESS;
}
