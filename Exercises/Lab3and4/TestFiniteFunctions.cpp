#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "FiniteFunctions.h"

std::vector<double> readData(std::string);
int printData(std::vector<double>);

int main(){
    // read in mystery data 
    std::string dataFile = "./Outputs/data/MysteryData03331.txt";
    std::vector<double> data; 
    data = readData(dataFile);
    // uncomment print to check that it works, but it's a long file 
    //printData(data);

    // working with the finitefunctions class
    std::string outFile = "fooBar";
    float rangeMin = -10; 
    float rangeMax = 10; 
    FiniteFunction myFiniteFunction(rangeMin, rangeMax, outFile);
    myFiniteFunction.plotFunction();

    // plot the data
    int Nbins = 20; // number of bins to turn data into histogram
    bool isData = true; // data points will be black 
    myFiniteFunction.plotData(data, Nbins, isData);

    return 0; 
}

// reads in the data from text file 
std::vector<double> readData(std::string fileName){
 // open the text file named input2D_float.txt 
    std::ifstream inputFile(fileName);

    // variable to store each line from the file   
    std::vector<double> data; 
    std::string str; 
    double num;

    // Read each line from the file and save it to the vector numbers
    while (getline(inputFile,str)) {
        num = stof(str);
        data.push_back(num);
    }

    // close the file when you're done 
    inputFile.close();

    return data; 
}

int printData(std::vector<double> data){

    for (int i = 0; i<data.size(); i++) { 
            std::cout << data[i] << std::endl;
        }
    return 0; 
}

