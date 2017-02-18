// mu is mean or expectation of the distribution
// sigma is standard deviation

#include <stdio.h>
#include <math.h>
#define PI 3.14

double* PDF_Normal_Distribution(int* x, int x_length, double mu, double sigma){
    double sigma_square = pow(sigma, 2); // variance
    double* fx = malloc(x_length * sizeof(double));
    
    for(int i=0; i<x_length; i++){
        fx[i] = exp(-0.5*pow((x[i]-mu), 2)/(2*sigma_square)) / sqrt(2*sigma_square*PI);
    }
    return fx;
}

double* CDF_Normal_Distribution(int* x, int x_length, double mu, double sigma){
    double* fx = malloc(x_length * sizeof(double));
    
    for(int i=0; i<x_length; i++){
        fx[i] = 0.5*(1+erf((x[i]-mu)/(sigma*sqrt(2))));
    }
    return fx;
}
