#pragma once
#include <string>
#include <vector>

std::vector<std::string> readData(std::string);
int printData(std::vector<std::string>); 
int printData(std::vector<float>);
int printData(std::string);
std::vector<float> calcMag(std::vector<std::string>);
std::string linFit(std::vector<std::string>);
float recursivePower(float, int, float, float);
std::vector<float> powData(std::vector<std::string>);
int writeFile(std::vector<float>, int);
int writeFile(std::string, int);