#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "CustomFunctions.h" // header file for 

//int printData(std::vector<std::string>); // function prototype 
//std::vector<float> calcMag(std::vector<std::string>);

int main(){
    
    // read in the text file named input2D_float.txt 
    std::string fileName = "input2D_float.txt"; 
    std::vector<std::string> numbers = readData(fileName);

    // prompt the use to choose what they're going to do 
    
    int choice; 
    bool doSwitching = true; 
    bool gotValidChoice = false; // double check edge cases

    do{ 
    std::cout << "Enter the number what what you want to do: 1. print N lines, 2. caculate the magnitude, 3. fit a line, 4. x^Y all data" << std::endl; //clean up formatting here
    std::cin >> choice;
        if(choice < 1){
            std::cout << "Not a valid number" << std::endl;
        }
        else if(choice > 4){
            std::cout << "Not a valid number" << std::endl;
        }
        else{
            gotValidChoice = true;
        }
    }while(!gotValidChoice);

    if(choice == 1){
        // print the data
        printData(numbers);
    }

    if(choice == 2){
        // calculate magnitude of (x,y) vector 
        std::vector<float> norms = calcMag(numbers);
        printData(norms); 
        writeFile(norms,choice);
    }

    if(choice == 3){
        // fit a straight line 
        std::string fitParams = linFit(numbers); 
        printData(fitParams); 
        writeFile(fitParams,choice);
    }

    if(choice == 4){
        //test recursive power
        std::vector<float> xPowYs;
        xPowYs = powData(numbers);
        printData(xPowYs);
        writeFile(xPowYs,choice);
    }

    return 0;
    

}

