//Corresponding header3
#include "FileReader.h"

//C system includes

//C++ system includes
#include<iostream>
#include<sstream>
#include<fstream>
//3rd-party includes

//Own components includes
#include"DataSaver.h"


FileReader::FileReader(std::string& path){
	std::ifstream streamFileReader(path);

	if (streamFileReader.is_open()) {
			while (std::getline(streamFileReader, line , ','))	//reading every line and putting it into the helping string
		{
				std::cout << line << std::endl << std::endl;

		}
	 }
	else{
		  std::cerr << "Could not open the file location : " << path << std::endl;
	}

	streamFileReader.close();

}

FileReader::~FileReader() {
}
