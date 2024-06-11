
#ifndef PROJECT1_442_CALCULATION_H
#define PROJECT1_442_CALCULATION_H
#include "math.h"
#include <sys/types.h>

double findMean(int * numbers, u_int length){
    int * ip = numbers;
    double sum = 0;
    int i;
    for(i = 0; i < length; i++){
        sum += ip[i];
    }
    return sum / (double) length;
}
double findSquare(double num){
    return num * num;
}

double findVariance(int * numbers, u_int length){
    double variance;
    double mean = findMean(numbers, length);

    int i;
    double sum = 0;
    for (i = 0; i < length; i ++){
        sum += findSquare(( fabs (numbers[i] - mean)));
    }
    variance = sum / (length - 1);
    return variance;
}


#endif //PROJECT1_442_CALCULATION_H
