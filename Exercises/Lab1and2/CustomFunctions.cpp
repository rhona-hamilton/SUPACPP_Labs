#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>


// function implemetation 

// reads in the data from text file 
std::vector<std::string> readData(std::string fileName){
 // open the text file named input2D_float.txt 
    std::ifstream inputFile(fileName);

    // variable to store each line from the file   
    std::vector<std::string> data; 
    std::string str;

    // Read each line from the file and save it to the vector numbers
    while (getline(inputFile,str)) {
        data.push_back(str);
    }

    // close the file when you're done 
    inputFile.close();

    return data; 
}

// print N lines of data, input by user 
int printData(std::vector<std::string> numbers){
    int N;
    bool gotValidN = false;
    do {
    std::cout << "Enter the number of lines to print" << std::endl; 
    std::cin >> N;
        if (N>numbers.size()){
            std::cout << "Too long. Only printing first 5 lines" << std::endl;
            N = 5;
            gotValidN = true;
        }
        if (N<1){
            std::cout << " Too short. Enter an integer greater than or equal to 1 " << std::endl; //would be cool to print the bad n in that output

        }
        else{
            gotValidN = true;
        }
    } while(!gotValidN);

    for (int i = 0; i<N; i++) { 
    std::cout << numbers[i] << std::endl;
    }
    return 0;
}

int printData(std::vector<float> data){

    for (int i = 0; i<data.size(); i++) { 
            std::cout << data[i] << std::endl;
        }
    return 0; 
}

int printData(std::string data){
    std::cout << data << std::endl;

    return 0; 
}

std::vector<float> calcMag(std::vector<std::string> numbers){
 // calculates magnitude of (x,y) components - converts from a string to two floats 
    std::vector<float> norms;

    // convert string x,y to two separate floats 
    for (int i = 1; i < numbers.size(); i++){
    size_t commaPos = numbers[i].find(',');
    std::string first = numbers[i].substr(0,commaPos);
    std::string second = numbers[i].substr(commaPos + 1);
    float a = stof(first);
    float b = stof(second); 

    float norm = std::sqrt(a*a + b*b);
    norms.push_back(norm);
    }
    
    return norms;
}

std::string linFit(std::vector<std::string> numbers){
    // fit a line to the data in numbers and save y = mx + c to a string
    // print the result to the terminal and save it into a file too
    std::string fitParams;
    std::vector<float> xNums; 
    std::vector<float> yNums; 

    for (int i = 1; i < numbers.size(); i++){
    size_t commaPos = numbers[i].find(',');
    std::string first = numbers[i].substr(0,commaPos);
    std::string second = numbers[i].substr(commaPos + 1);
    float a = stof(first);
    float b = stof(second); 
    xNums.push_back(a);
    yNums.push_back(b);
    }
    
    float sumX = 0; 
    float sumY = 0; 
    float sumXY = 0; 
    float sumXX = 0; // assign variables to be summed over

    for (int i = 0; i < xNums.size(); i++){
        sumX = sumX + xNums[i];
        sumY = sumY + yNums[i];
        sumXY = sumXY + xNums[i]*yNums[i];
        sumXX = sumXX + xNums[i]*xNums[i]; 
    }

    float p ;
    float q ;
    float N = xNums.size(); 

    p = (N*sumXY - sumX*sumY)/(N*sumXX - sumX*sumX); 
    q = (sumXX*sumY - sumXY*sumX)/(N*sumXX - sumX*sumX);

    // calculate chi-squared for the data 

    // read in error2D_float.txt 
    std::string errorFile = "error2D_float.txt";
    std::vector<std::string> errorStrings = readData(errorFile);

    std::vector<float> xErr; 
    std::vector<float> yErr; 
    // convert to floats
    for (int i = 1; i < errorStrings.size(); i++){
    size_t commaPos = errorStrings[i].find(',');
    std::string first = errorStrings[i].substr(0,commaPos);
    std::string second = errorStrings[i].substr(commaPos + 1);
    float a = stof(first);
    float b = stof(second); 
    xErr.push_back(a);
    yErr.push_back(b);
    }

    std::vector<float> sigma; // calculate variance
    for (int i = 0; i < xErr.size(); i++){
        // variance calculated to include both x and y error
        float s = sqrt(yErr[i]*yErr[i] + p*xErr[i]*xErr[i]);
        sigma.push_back(s);
    }

    // calculate chi squared 
    float chiSq = 0;
    for (int i = 0; i < yNums.size(); i++){
        double chi = (yNums[i] - (p*xNums[i] + q))/sigma[i];
        chiSq = chiSq + chi*chi;
    }
    float m = 2; // number of fitted params 
    float n = yNums.size();
    chiSq = chiSq/(n-m);

    // write all the outputs 
    std::stringstream ss; //empty stringstream object 
    ss << "slope = " << p << ", intercept = " << q << " chi^2 = " << chiSq;
    
    //return the stringstream into a string 
    fitParams = ss.str(); 

    return fitParams;

}

// calculate x to the power of y through an itterative loop 
float recursivePower(float x, int y, float temp, float count){
    float xPowY; 
    if (count <= y){
        temp = temp * x;
        count = count + 1;
        return recursivePower(x,y,temp,count);
    }
    else{
    xPowY = temp;    
    return xPowY;
    }
}

std::vector<float> powData(std::vector<std::string> numbers){
     // convert to floats
     std::vector<float> xVals; 
     std::vector<float> yVals; 
     std::vector<float> xPowYs;

    for (int i = 1; i < numbers.size(); i++){
    size_t commaPos = numbers[i].find(',');
    std::string first = numbers[i].substr(0,commaPos);
    std::string second = numbers[i].substr(commaPos + 1);
    float a = stof(first);
    float b = stof(second); 
    xVals.push_back(a);
    yVals.push_back(b);
    }
    
    for (int i = 0; i < xVals.size(); i++){
        float x = xVals[i]; 
        float y = yVals[i];
        // ensure correct rounding - float to int just truncates 
        y = y+0.5; 
        float temp = 1; 
        float count = 1; 

        float xPowY = recursivePower( x, y, temp, count);
        xPowYs.push_back(xPowY); 
    }

    return xPowYs; 

}

int writeFile(std::vector<float> data, int nameNum){
    std::string fileName;
    if(nameNum == 2){
        fileName = "magnitudes.txt";
    }
    else if(nameNum == 4){
        fileName = "x_toThe_y.txt";
    }
    else {
        fileName = "you_stuffed_up.txt"; 
    }

   std::ofstream myfile; 
    myfile.open(fileName);

    for (int i; i < data.size(); i++) {
        myfile << data[i] << "\n";  
    }

    myfile.close();

    return 0; 
}

int writeFile(std::string data, int nameNum){
    std::string fileName;
    if(nameNum == 3){
        fileName = "linear_fit.txt";
    }
    else {
        fileName = "you_stuffed_up.txt";
    }
    std::ofstream myfile; 
    myfile.open(fileName);

    myfile << data;
    myfile.close();

    return 0; 
}