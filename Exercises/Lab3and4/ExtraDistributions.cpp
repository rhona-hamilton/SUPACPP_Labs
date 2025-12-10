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

/*
Crystal ball distribution 
*/

// constructor
crystalBall::crystalBall(double range_min, double range_max, double mean, double sigma, double n, double alpha, std::string outfile) : 
FiniteFunction(range_min,range_max,outfile)
{
    //FiniteFunction(range_min,range_max,outfile); // call parent's initialised constructor
    m_mean = mean; 
    m_sigma = fabs(sigma); //I think sigma should be positive... 
    m_n = n; //need to do some kind of protection here - if n less than 1 set as default 
    m_alpha = fabs(alpha);
}

// setter
void crystalBall::setMean(double mean) {m_mean = mean;};
void crystalBall::setSigma(double sigma) {m_sigma = fabs(sigma);};
void crystalBall::setN(double n) {m_n = n;};
void crystalBall::setAlpha(double alpha) {m_alpha = fabs(alpha);};

// function eval 
double crystalBall::crystalFunct(double x) {
    double pi = M_PI;
    double A = std::pow((m_n/m_alpha),m_n)*std::exp(-1*(m_alpha*m_alpha)/2);
    double B = (m_n/m_alpha) - m_alpha ;
    double C = (m_n/m_alpha)*(1/(m_n-1))*std::exp(-1*m_alpha*m_alpha/2);
    double D = std::sqrt(pi/2)*(1+std::erf(m_alpha/std::sqrt(2)));
    double N = 1/(m_sigma*(C+D));
    double y;
    if(((x-m_mean)/m_sigma) > -1*m_alpha){
        y = N*std::exp((-1*(x-m_mean)*(x-m_mean))/(2*m_sigma*m_sigma));
    } else {
         y = A*std::pow(B-(x-m_mean)/m_sigma,-1*m_n);
    }

    return y; 
 }
double crystalBall::callFunction(double x) {return this->crystalFunct(x);};

