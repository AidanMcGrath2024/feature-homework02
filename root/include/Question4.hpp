#include <cmath>
#include <vector>
#include <matplot/matplot.h> //**** make sure pathing works in include ****
#include <fstream>
#include <iostream>
using namespace matplot;


class Part1 {
private:
	std::vector<double> x = linspace(0, 4 * pi); // setting from 0 to 4pi
	std::vector<double> y = transform(x, [](double x)
		{ return 7 * cos(x); }); // setting y vector to 7cosx because cosine is underapprciated and I like the number 7

public:
	void plot1() { // function to make plot 1


		plot(x, y); //make plot 
		title("7cos(x)"); // title plot
		xlabel("x"); //label x axis  
		ylabel("y"); // label y axis 
		show(); // show plot  
	}
};

class Part2 {
public:
	void plot2() {
		std::string line = ""; // initialize string, later to be used to extract csv line 
		std::ifstream iFile; // creat ifstream object 

		iFile.open("Q4data.csv"); //****** need to figure out how to actually open when configured***** // open file into iFile
		std::vector<double>xval; // initilize x vector
		std::vector<double>yval; // initialize y vecter 

		std::getline(iFile, line); // get first line (headers) of csv 
		//std::cout << line << std::endl; 

		int cLocation = line.find(","); // find comma location 
		std::string labelX = line.substr(0, cLocation); // extract data up to comma 
		std::string labelY = line.substr(cLocation + 1, line.length()); // extract data after comma 


		while (std::getline(iFile, line)) { // loop to get all other lines 
			cLocation = line.find(","); // find comma 
			xval.push_back(std::stod(line.substr(0, cLocation))); //***** NEED TO VALIDATE WRITE TO VECTOR***** // extract data up to comma, turn string into double using stod and store in vector 
			yval.push_back(std::stod(line.substr(cLocation + 1, line.length())));// extract data after to comma, turn string into double using stod and store in vector

		};

		iFile.close(); // close file

		matplot::plot(xval, yval); // make plot 
		matplot::title("extracted data"); // title plot 
		matplot::xlabel(labelX); // us extracted header from csv to label x 
		matplot::ylabel(labelY); // us extracted header from csv to label y
		matplot::show(); //show plot 


	}
};

