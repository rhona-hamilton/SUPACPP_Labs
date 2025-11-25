#include <iostream> 
#include <cmath>

double customNorm(){
    float x;
    float y; 
    std::cout << "Enter length of x component: "; 
    std::cin >> x;
    std::cout << "Enter length of y component: ";
    std::cin >> y; 
    return std::sqrt(x*x + y*y);

}


int main(){
    double x = 7.5;
    double y = 3.4;
    double norm; 
    float fNorm; 

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    norm = std::sqrt(x*x + y*y);

    std::cout << "The Euclidian norm is " << norm << std::endl; 
    
    fNorm = customNorm();

    std::cout << "The custom norm function gives " << fNorm << std::endl; 

    return 0;
}