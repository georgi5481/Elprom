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
															savedInputs.push_back(input))	//reading every line and putting it into the helping string

			{

				std::getline(streamFileReader, input.positionPlace , separatingCharacter);
				std::getline(streamFileReader, input.positionNumber , separatingCharacter);
				std::getline(streamFileReader, input.draftNumerations , separatingCharacter);
				std::getline(streamFileReader, input.nameDetail , separatingCharacter);
				std::getline(streamFileReader, input.quantity , separatingCharacter);

				std::getline(streamFileReader, input.material , separatingCharacter);
				if(input.material.back() != '"' && input.material.back() != ' '){	//in case we have ';' symbol in the materials
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

double FileReader::turnIntoDouble(std::string& turnIntoDouble){
	if(turnIntoDouble.size() > 2){


		//converting string to double  with the next 3 lines
		turnIntoDouble = turnIntoDouble.substr(1, turnIntoDouble.size() - 2);

		std::replace(turnIntoDouble.begin(), turnIntoDouble.end(), ',', '.');

		double convertedDouble = atof(turnIntoDouble.c_str());	//change only if we have input string
		return convertedDouble;
	}
	return 0;
}



void FileReader::singleObjectSort(DataSaver& storedDataLine){

	if(storedDataLine.positionNumber != " "){

		double weightMaterial = turnIntoDouble(storedDataLine.weigthSingleDetail);	//set the weight to zero by dafault

		double quantity = turnIntoDouble(storedDataLine.quantity);


		if(storedDataLine.material.find("C2R") != std::string::npos || storedDataLine.material.find("P4R") != std::string::npos){

			std::cout << "Found wood on position " << storedDataLine.positionNumber << " with " << weightMaterial << " weight. "  << weightMaterial*quantity << std::endl;

		}
		else if(storedDataLine.material.find("Cu") != std::string::npos || storedDataLine.material.find("мед") != std::string::npos
				|| storedDataLine.material.find("отвод") != std::string::npos){
			std::cout << "Found Cu material at " << storedDataLine.positionNumber << " position with "<< weightMaterial << " weight " << weightMaterial*quantity <<  std::endl;
		}
		else if(storedDataLine.material.find("Etronit") != std::string::npos ){
			std::cout << "Found Etronit at " << storedDataLine.positionNumber << " position with "<< weightMaterial << " weight " << weightMaterial*quantity <<  std::endl;
		}
		else if(storedDataLine.material.find("Трафоборд") != std::string::npos ){
			std::cout << "Found Etronit at " << storedDataLine.positionNumber << " position with "<< weightMaterial << " weight " << weightMaterial*quantity << std::endl;
		}
		else{
			std::cout << "Unknown materialls at " << storedDataLine.positionNumber << " position with "<< weightMaterial << " weight " << weightMaterial*quantity << std::endl;
		}
	}
}


void FileReader::saveFilledFile(){
	for(auto& inputObject : savedInputs){
		singleObjectSort(inputObject);
	}
}




