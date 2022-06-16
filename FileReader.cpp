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
		DataSaver input;
		std::string hello;
			while (std::getline(streamFileReader, input.drafting , ','))	//reading every line and putting it into the helping string
		{
				std::getline(streamFileReader, input.positionPlace , ',');
				std::getline(streamFileReader, input.positionNumber , ',');
				std::getline(streamFileReader, input.draftNumerations , ',');
				std::getline(streamFileReader, input.nameDetail , ',');
				std::getline(streamFileReader, input.quantity , ',');
				std::getline(streamFileReader, input.material , ',');
				std::getline(streamFileReader, input.weigthSingleDetail , ',');
				std::getline(streamFileReader, input.BTES);

				std::cout << input.drafting  << std::endl << input.weigthSingleDetail<< std::endl;
				std::cin >> hello;
		}
	 }
	else{
		  std::cerr << "Could not open the file location : " << path << std::endl;
	}

	streamFileReader.close();

}

FileReader::~FileReader() {
}
