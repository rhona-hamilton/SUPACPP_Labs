#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "FiniteFunctions.h"
#include "ExtraDistributions.h"

// header for custom functions 
std::vector<double> readData(std::string);
int printData(std::vector<double>);

// main function reads in mystery data, plots mystery data alongside finite functions
// then samples pseudo data from finite functions to using metropolis algorithm and plots this on same axes 
int main(){
    // read in mystery data 
    std::string dataFile = "./Outputs/data/MysteryData03331.txt";
    std::vector<double> data; 
    data = readData(dataFile);
    // uncomment print to check that it works, but it's a long file 
    //printData(data);

    // working with the finitefunctions class
    std::cout << "***** Function: 1/1+x^2 *****" << std::endl; 
    std::string outFile = "xSquaredPlot";
    double rangeMin = -15; 
    double rangeMax = 15; 
    std::cout << "Range Min: " << rangeMin << " Range Max: " << rangeMax << std::endl;
    FiniteFunction myFiniteFunction(rangeMin, rangeMax, outFile);
    myFiniteFunction.plotFunction();

    // plot the data
    int Nbins = 100; // number of bins to turn data into histogram
    bool isData = true; // data points will be black 
    bool isNot = false;  // for plotting sampled pseudo data 
    int pNbins = 1000; // number of bins for pseudo data 

    myFiniteFunction.plotData(data, Nbins, isData);

    // sample via metropolis algorithm and plot results 
    std::vector<double> x2_pseudoData;
    x2_pseudoData = myFiniteFunction.metroSample(); 
    myFiniteFunction.plotData(x2_pseudoData,pNbins,isNot); 

    // define parameters for testing normal distribution 
    std::cout << "***** Function: Normal Distribution *****" << std::endl; 
    std::string norm_outFile = "normPlot";
    double mean = 1; 
    double sigma = 2.5; 
    std::cout << "Range Min: " << rangeMin << " Range Max: " << rangeMax << std::endl;
    std::cout << "Mean: " << mean << " Standard Deviation: " << sigma << std::endl; 
    normalDist myNormalDist(rangeMin, rangeMax, mean, sigma, norm_outFile);

    // sample via metropolis algorithm and plot results
    std::vector<double> norm_pseudoData; 
    norm_pseudoData = myNormalDist.metroSample(); 
    myNormalDist.plotFunction(); 
    myNormalDist.plotData(data,Nbins,isData);
    myNormalDist.plotData(norm_pseudoData,pNbins,isNot);

    // define parameters for testing Cauchy-Lorentz distribution 
    std::cout << "***** Function: Cauchy-Lorentz Distribution *****" << std::endl; 
    std::string cl_outFile = "cauchyPlot";
    double x0 = 1;
    double gamma = 2.5; 
    double cl_rangeMin = -20; 
    double cl_rangeMax = 20;
    std::cout << "Range Min: " << cl_rangeMin << " Range Max: " << cl_rangeMax << std::endl;
    std::cout << "Location: " << x0 << " Width: " << gamma << std::endl;
    cauchyLor myCauchyLor(cl_rangeMin, cl_rangeMax, x0, gamma, cl_outFile);
    myCauchyLor.plotFunction();
    myCauchyLor.plotData(data,Nbins,isData);

    // sample via metropolis algorithm and plot results
    std::vector<double> cl_pseudoData; 
    cl_pseudoData = myCauchyLor.metroSample(); 
    myCauchyLor.plotData(cl_pseudoData,pNbins,isNot); 

    // define parameters for testing Cystal ball distribution 
    std::cout << "***** Function: Crystal Ball Distribution *****" << std::endl; 
    std::string cb_outFile = "crystalPlot";
    double cb_mean = 2;
    double cb_sigma = 1;
    double n = 3;
    double alpha = 1;
    double cb_rangeMin = -10; 
    double cb_rangeMax = 10; 
    std::cout << "Range Min: " << cb_rangeMin << " Range Max: " << cb_rangeMax << std::endl;
    std::cout << "mu: " << cb_mean << " sigma: " << cb_sigma << " n: " << n << " alpha: " << alpha << std::endl; 
    crystalBall myCrystalBall(cb_rangeMin, cb_rangeMax, cb_mean, cb_sigma, n, alpha, cb_outFile);
    
    // sample via metropolis algorithm and plot results
    std::vector<double> cb_pseudoData; 
    cb_pseudoData = myCrystalBall.metroSample(); 

    myCrystalBall.plotFunction();
    myCrystalBall.plotData(data,Nbins,isData);
    myCrystalBall.plotData(cb_pseudoData,pNbins,isNot);

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

