#ifndef DATASAVER_H_
#define DATASAVER_H_
//Corresponding header

//C system includes

//C++ system includes
#include<string>

//3rd-party includes

//own include

class DataSaver {
public:
	DataSaver();
	virtual ~DataSaver();
private:
	std::string drafting;
	std::string positionPlace;
	std::string positionNumber;
	std::string draftNumerations;
	std::string nameDetail;
	std::string quantity;
	std::string material;
	std::string weigthSingleDetail;
	std::string BTES;

};

#endif /* DATASAVER_H_ */
