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
#include "config/DataSaverCfg.h"

static char separatingCharacter = ';';
static Weights storageWeights;

namespace savings{
static std::vector<DataSaver> savedAllInputs; //from the read line of the stream/file

static std::vector<DataSaver> savedCu;
static std::vector<DataSaver> savedWood;
static std::vector<DataSaver> savedEtronit;
static std::vector<DataSaver> savedTransformerboard;
static std::vector<DataSaver> savedUnknownData;
}


FileReader::FileReader(std::string& path){
	std::ifstream streamFileReader(path);

	if (streamFileReader.is_open()) {


			for (DataSaver input;																//this is equal to  	for(int i = 0; i<0: i++)
					std::getline(streamFileReader, input.drafting , separatingCharacter);
															savings::savedAllInputs.push_back(input))	//reading every line and putting it into the helping string

			{

				std::getline(streamFileReader, input.positionPlace , separatingCharacter);
				std::getline(streamFileReader, input.positionNumber , separatingCharacter);
				std::getline(streamFileReader, input.draftNumerations , separatingCharacter);
				std::getline(streamFileReader, input.nameDetail , separatingCharacter);
				std::getline(streamFileReader, input.quantity , separatingCharacter);

				std::getline(streamFileReader, input.material , separatingCharacter);
				if(input.material.back() != '"' && input.material.back() != ' '){	//in case we didn't end the line
					std::string otherHalf;
					std::getline(streamFileReader,otherHalf, separatingCharacter);
					input.material += otherHalf;
				}
				std::getline(streamFileReader, input.weigthSingleDetail , separatingCharacter);

				std::getline(streamFileReader, input.BTES);



				std::cout  << input.drafting << " , " << input.positionPlace <<  " , " << input.positionNumber << " , " <<
						input.draftNumerations << " , " << input.nameDetail << " , " << input.quantity << " , " <<
						input.material << " , " << input.weigthSingleDetail << " , " << input.BTES << std::endl << savings::savedAllInputs.size() << std::endl;

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

		double convertedDouble = atof(turnIntoDouble.c_str());

		return convertedDouble;
	}
	return 0;
}



void FileReader::singleObjectSort(DataSaver& storedDataLine){

	if(storedDataLine.positionNumber != " "){

		double weightMaterial = turnIntoDouble(storedDataLine.weigthSingleDetail);	//set the weight to zero by dafault

		double quantity = turnIntoDouble(storedDataLine.quantity);

		storedDataLine.quantityDouble = quantity;
		storedDataLine.weightSingleDetailDouble = weightMaterial;

		if(storedDataLine.material.find("C2R") != std::string::npos || storedDataLine.material.find("P4R") != std::string::npos){
			savings::savedWood.push_back(storedDataLine);

		}
		else if(storedDataLine.material.find("Cu") != std::string::npos || storedDataLine.material.find("мед") != std::string::npos
				|| storedDataLine.nameDetail.find("отвод") != std::string::npos){
			savings::savedCu.push_back(storedDataLine);
		}
		else if(storedDataLine.material.find("Etronit") != std::string::npos ){
			savings::savedEtronit.push_back(storedDataLine);
				}
		else if(storedDataLine.material.find("Трафоборд") != std::string::npos ){
			savings::savedTransformerboard.push_back(storedDataLine);
		}
		else{
			savings::savedUnknownData.push_back(storedDataLine);
		}
	}
}


void FileReader::saveFilledFile(){
	for(auto& inputObject : savings::savedAllInputs){
		singleObjectSort(inputObject);
	}
}

void FileReader::fillOutput(std::vector<DataSaver>& inputVector, std::ofstream& outFileStream){
	for(auto& outputObject : inputVector){
		outFileStream << outputObject.positionNumber << " with " << outputObject.weightSingleDetailDouble << " weight. \t"
					 << outputObject.weightSingleDetailDouble * outputObject.quantityDouble << std::endl;
			 }
}


void FileReader::printSavedData(std::string& nameOfOutputFile){
	 std::ofstream outputStream;
	 std::string pathOutput = "./Mass/" + nameOfOutputFile;

	 outputStream.open(pathOutput);

	 if(savings::savedWood.size() != 0){
		 outputStream << "Found wood on position:\n";
		 fillOutput(savings::savedWood, outputStream);
		 outputStream << std::endl;
	 }

	 if(savings::savedCu.size() != 0){
		 outputStream << "Found Cu on position:\n";
		 fillOutput(savings::savedCu, outputStream);
		 outputStream << std::endl;
	 }

	 if(savings::savedTransformerboard.size() != 0){
		 outputStream << "Found Transformerboard on position:\n";
		 fillOutput(savings::savedTransformerboard, outputStream);
		 outputStream << std::endl;
	 }


	 if(savings::savedEtronit.size() != 0){
		 outputStream << "Found Etronit on position:\n";
		 fillOutput(savings::savedEtronit, outputStream);
		 outputStream << std::endl;
	 }


	 if(savings::savedUnknownData.size() != 0){
		 outputStream << "Unknown material on position:\n";
		 fillOutput(savings::savedUnknownData, outputStream);
		 outputStream << std::endl;
	 }


 	 outputStream.close();


}














