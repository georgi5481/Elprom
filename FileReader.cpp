//Corresponding header
#include "FileReader.h"

//C system includes

//C++ system includes
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include <stdlib.h>
//3rd-party includes

//Own components includes
#include"config/DataSaver.h"

static 	Weights storageWeights;
static std::vector<DataSaver> savedInputs;
static char separatingCharacter = ';';


FileReader::FileReader(std::string& path){
	std::ifstream streamFileReader(path);

	if (streamFileReader.is_open()) {


			for (DataSaver input;																//this is equal to  	for(int i = 0; i<0: i++)
					std::getline(streamFileReader, input.drafting , separatingCharacter);
															savedInputs.push_back(input)	)	//reading every line and putting it into the helping string
			{

				std::getline(streamFileReader, input.positionPlace , separatingCharacter);
				std::getline(streamFileReader, input.positionNumber , separatingCharacter);
				std::getline(streamFileReader, input.draftNumerations , separatingCharacter);
				std::getline(streamFileReader, input.nameDetail , separatingCharacter);
				std::getline(streamFileReader, input.quantity , separatingCharacter);

				std::getline(streamFileReader, input.material , separatingCharacter);
				if(input.material.back() != '"'  && input.material.back() != ' '){	//in case we have ';' symbol in the materials
					std::string otherHalf;
					std::getline(streamFileReader,otherHalf, separatingCharacter);
					input.material += otherHalf;
				}
				std::getline(streamFileReader, input.weigthSingleDetail , separatingCharacter);

				std::getline(streamFileReader, input.BTES);


				std::cout  << input.drafting << " , " << input.positionPlace <<  " , " << input.positionNumber << " , " <<
						input.draftNumerations << " , " << input.nameDetail << " , " << input.quantity << " , " <<
						input.material << " , " << input.weigthSingleDetail << " , " << input.BTES << std::endl << savedInputs.size() << std::endl;

			}
	 }
	else{
		  std::cerr << "Could not open the file location : " << path << std::endl;
	}

	streamFileReader.close();

}

FileReader::~FileReader() {

}

void FileReader::singleObjectSort(DataSaver& storedDataLine){

	if(storedDataLine.weigthSingleDetail.size() > 2){

		//converting string to double  with the next 3 lines
		storedDataLine.weigthSingleDetail = storedDataLine.weigthSingleDetail.substr(1, storedDataLine.weigthSingleDetail.size() - 2);
		std::replace(storedDataLine.weigthSingleDetail.begin(), storedDataLine.weigthSingleDetail.end(), ',', '.');
		double weghtMaterial = atof(storedDataLine.weigthSingleDetail.c_str());

		if(storedDataLine.material.find("C2R") != std::string::npos){
			std::cout << "Found wood on position" << storedDataLine.positionNumber << " with " << weghtMaterial << "     "
					<< storedDataLine.weigthSingleDetail.size()  << std::endl;

		}
		else if(storedDataLine.material.find("Cu" != std::string::npos)){
			std::cout << "found Cu material" << storedDataLine.positionNumber << " with "<< weghtMaterial << std::endl;
		}


	}
}


void FileReader::saveFilledFile(){
	for(auto& inputObject : savedInputs){
		singleObjectSort(inputObject);
	}
}




