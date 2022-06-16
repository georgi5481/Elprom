//Corresponding header
#include "FileReader.h"

//C system includes

//C++ system includes
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>

//3rd-party includes

//Own components includes
#include"DataSaver.h"

static std::vector<DataSaver> savedInputs;

FileReader::FileReader(std::string& path){
	std::ifstream streamFileReader(path);

	if (streamFileReader.is_open()) {


			for (DataSaver input;																//this is equal to  for(int i = 0; i<0: i++)
					std::getline(streamFileReader, input.drafting , ',');
															savedInputs.push_back(input)	)	//reading every line and putting it into the helping string
			{

				std::getline(streamFileReader, input.positionPlace , ',');
				std::getline(streamFileReader, input.positionNumber , ',');
				std::getline(streamFileReader, input.draftNumerations , ',');
				std::getline(streamFileReader, input.nameDetail , ',');
				std::getline(streamFileReader, input.quantity , ',');
				std::getline(streamFileReader, input.material , ',');
				std::getline(streamFileReader, input.weigthSingleDetail , ',');
				std::getline(streamFileReader, input.BTES);

				std::cout << savedInputs.size() << std::endl;

			}
	 }
	else{
		  std::cerr << "Could not open the file location : " << path << std::endl;
	}

	streamFileReader.close();

}

FileReader::~FileReader() {
}


void FileReader::saveFilledFile(){

}




