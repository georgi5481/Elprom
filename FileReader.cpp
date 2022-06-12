//Corresponding header3
#include "FileReader.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes

//Own components includes


FileReader::FileReader(){
	streamFileReader(path);

	if(streamFileReader){
		std::stringstream buffer;

		 buffer << streamFileReader.rdbuf();

	}
	else {
		std::cerr << "there has been a problem opening the file. prease try again." << std::endl;
	}


}

FileReader::~FileReader() {

}

void ReadLine(){
	std::string myText;
	while (std::getline(bufferReader, myText)) {

	  std::cout << myText;
	}
}
