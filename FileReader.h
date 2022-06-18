#ifndef FILEREADER_H_
#define FILEREADER_H_
//Corresponding header

//C system includes

//C++ system includes
#include<string>

//3rd-party includes

//own include

struct DataSaver;

class FileReader {
public:
	FileReader();
	FileReader(std::string& path);
	void saveFilledFile();
	~FileReader();

private:
	void singleObjectSort(DataSaver& storedDataLine);
	void saveDataIntoStorager();
	std::string line;

};


#endif /* FILEREADER_H_ */
