#ifndef FILEREADER_H_
#define FILEREADER_H_
//Corresponding header

//C system includes

//C++ system includes
#include<iostream>
//#include <fstream>

//3rd-party includes

//own include
class FileReader {
public:
	FileReader();
	virtual ~FileReader();
	void ReadLine();
	std::string path;
private:
	std::istream streamFileReader;
	std::stringstream buffer;
};


#endif /* FILEREADER_H_ */
