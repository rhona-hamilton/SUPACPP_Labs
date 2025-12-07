#include "FiniteFunctions.h"
#include "ExtraDistributions.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

/*
Normal distribution 
*/

// overloaded constructor 
normalDist::normalDist(double range_min, double range_max, double mean, double sigma, std::string outfile) : 
FiniteFunction(range_min,range_max,outfile)
{
    //FiniteFunction(range_min,range_max,outfile); // call parent's initialised constructor
    m_Mean = mean; 
    m_Sigma = sigma; 
}

/*
############
//Setters 
############
*/
void normalDist::setMean(double mean) {m_Mean = mean;};
void normalDist::setSigma(double sigma) {m_Sigma = sigma;};

/*
############
//Function eval  
############
*/
double normalDist::normFunct(double x) {
    double pi = M_PI;
    double exponent = (x - m_Mean)/m_Sigma; 
    double y = 1/(m_Sigma*std::sqrt(2*pi))*std::exp(-0.5*exponent*exponent);
    return y;
 }
double normalDist::callFunction(double x) {return this->normFunct(x);};

/*
Cauchy-Lorentz distribution 
*/

// constructor
cauchyLor::cauchyLor(double range_min, double range_max, double x0, double gamma, std::string outfile) : 
FiniteFunction(range_min,range_max,outfile)
{
    //FiniteFunction(range_min,range_max,outfile); // call parent's initialised constructor
    m_x0 = x0; 
    m_gamma = fabs(gamma); 
}

// setter
void cauchyLor::setX0(double x0) {m_x0 = x0;};
void cauchyLor::setGamma(double gamma) {m_gamma = fabs(gamma);};

// function eval 
double cauchyLor::cauchyFunct(double x) {
    double pi = M_PI;
    double frac = (x - m_x0)/m_gamma;
    double denom = pi*m_gamma*(1+frac*frac); 
    double y = 1/denom;
    return y;
 }
double cauchyLor::callFunction(double x) {return this->cauchyFunct(x);};
