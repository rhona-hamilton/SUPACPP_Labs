#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "CustomFunctions.h" // header file  

int main(){
    int choice; 
    bool go = true; 
    
     // read in the text file named input2D_float.txt 
    std::string fileName = "input2D_float.txt"; 
    std::vector<std::string> numbers = readData(fileName);

     // prompt the use to choose what they're going to do 
   
    while(go){
    std::cout << "Enter the number for what you want to do: 1. print N lines, 2. caculate the magnitude, 3. fit a line, 4. x^Y all data, 5. quit the program" << std::endl; 
    std::cin >> choice;
    
    switch(choice) {
        case 1:{
            // print the data
        printData(numbers);
        break;
        }
        
        case 2: {
           // calculate magnitude of (x,y) vector 
        std::vector<float> norms = calcMag(numbers);
        printData(norms); 
        writeFile(norms,choice); 
        break;
        }

        case 3: {
           // fit a straight line 
        std::string fitParams = linFit(numbers); 
        printData(fitParams); 
        writeFile(fitParams,choice); 
        break;
        }

        case 4: {
          //test recursive power
        std::vector<float> xPowYs;
        xPowYs = powData(numbers);
        printData(xPowYs);
        writeFile(xPowYs,choice);  
        break;
        }

        case 5: {
            // finish 
            std::cout << "all done :)" << std::endl; 
            go = false;
            break;
        }

        default:{
            std::cout << "you didn't enter a valid integer :(" << std::endl;
            break;
        }
    } //switch 
    } //while 
    return 0; 
}