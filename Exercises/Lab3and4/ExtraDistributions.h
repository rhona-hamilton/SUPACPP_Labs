#include <string>
#include <vector>
#include "FiniteFunctions.h"
#pragma once

class normalDist : public FiniteFunction {

    public:
        normalDist();
        normalDist(double range_min, double range_max, double mean, double sigma, std::string outfile);

        void setMean(double mean);
        void setSigma(double sigma);
        double callFunction(double x); // this is an overwrite 
    protected:
        double m_Mean; 
        double m_Sigma; 

    private:
        double normFunct(double x); 
};

class cauchyLor : public FiniteFunction {

    public:
        cauchyLor();
        cauchyLor(double range_min, double range_max, double x0, double gamma, std::string outfile);
        void setX0(double x0);
        void setGamma(double gamma);
        double callFunction(double x); // this is an overwrite 
    protected: 
        double m_x0; 
        double m_gamma; 
    private: 
        double cauchyFunct(double x);

};

class crystalBall : public FiniteFunction {
    public:
        crystalBall();
        crystalBall(double range_min, double range_max, double mean, double sigma, double n, double alpha, std::string outfile);
        void setMean(double mean);
        void setSigma(double sigma);
        void setN(double n);
        void setAlpha(double alpha);
        double callFunction(double x);

    protected:
        double m_mean;
        double m_sigma;
        double m_n; 
        double m_alpha; 
        
    private:
        double crystalFunct(double x);

};

