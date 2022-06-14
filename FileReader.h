#ifndef FILEREADER_H_
#define FILEREADER_H_
//Corresponding header

//C system includes

//C++ system includes
#include<string>

//3rd-party includes

//own include


class FileReader {
public:
	FileReader();
	FileReader(std::string& path);
	~FileReader();

private:
	void saveDataIntoStorager();
	std::string line;

};


#endif /* FILEREADER_H_ */
