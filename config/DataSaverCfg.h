#ifndef DATASAVER_H_
#define DATASAVER_H_
//Corresponding header

//C system includes

//C++ system includes
#include<string>
#include<vector>
//3rd-party includes

//own include
struct Weights{
	 double weightCu = 0;
	 double weightWood = 0;
	 double weightEtronit =0;
	 double weightTransformerboard = 0;
	 double	weightUnknown = 0;

};

struct DataSaver {

	std::string drafting;
	std::string positionPlace;
	std::string positionNumber;
	std::string draftNumerations;
	std::string nameDetail;
	std::string quantity;
	std::string material;
	std::string weigthSingleDetail;
	std::string BTES;


	double quantityDouble = 0;
	double weightSingleDetailDouble = 0;
};

#endif /* DATASAVER_H_ */
