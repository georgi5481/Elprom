#ifndef FILEREADER_H_
#define FILEREADER_H_
//Corresponding header

//C system includes

//C++ system includes
#include<iostream>
#include<fstream>
#include<sstream>

//3rd-party includes

//own include
class FileReader {
public:
	FileReader();
	FileReader(std::string& path);
	virtual ~FileReader();

private:
	void saveDataIntoStorager();
	std::string line;

};


#endif /* FILEREADER_H_ */
