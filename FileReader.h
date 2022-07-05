#ifndef FILEREADER_H_
#define FILEREADER_H_
//Corresponding header

//C system includes

//C++ system includes
#include<string>
#include <vector>
//3rd-party includes

//own include

struct DataSaver;

class FileReader {
public:
	FileReader();
	FileReader(std::string& path);
	void saveFilledFile();
	void printSavedData(std::string& nameOfOutputFile);
	~FileReader();

private:
	void fillOutput(std::vector<DataSaver>& inputVector, std::ofstream& outFileStream);
	void singleObjectStore(DataSaver& storedDataLine);
	void saveDataIntoStorager();
	double turnIntoDouble(std::string& turnIntoDouble);
	std::string line;

};


#endif /* FILEREADER_H_ */
