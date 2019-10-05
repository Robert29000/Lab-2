//
//  main.cpp
//  LR2
//
//  Created by Роберт Артур Меликян on 03/10/2019.
//  Copyright © 2019 Роберт Артур Меликян. All rights reserved.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double VALUE = 4.46500721361612;

double func(double x){
    return pow(M_E,x)*(1+cos(x))/(1+sin(x));
}

void valueWithPrecision(double e){
    int b = 2,a = 0;
    int n = 1;
    int countItr=0;
    double currentValue = 0;
    while((VALUE-currentValue) >= e){
        currentValue = 0;
        double pas = double(b-a)/n;
        for(int i = 0;i < n;i++){
            double x0 = a + i * pas;
            double x1 = a + (i+1) * pas;
            double valX0 = func(x0);
            double valX1 = func(x1);
            currentValue = currentValue + (valX0+valX1)/2 * (x1-x0);
            countItr++;
        }
        n++;
    }
    cout <<" Значение " << currentValue << " Количество разбиений " << n << " Количество итераций "  << countItr << endl;
}

int main(int argc, const char * argv[]) {
    cout.setf(ios::fixed);
    cout << "Точность 1e-2 ";
    valueWithPrecision(1e-2);
    cout << "Точность 1e-3 ";
    valueWithPrecision(1e-3);
    cout << "Точность 1e-4 ";
    valueWithPrecision(1e-4);
    cout << "Точность 1e-5 ";
    valueWithPrecision(1e-5);
    cout << "Точность 1e-6 ";
    valueWithPrecision(1e-6);
    cout << "Точность 1e-7 ";
    valueWithPrecision(1e-7);
    cout << "Точность 1e-8 ";
    valueWithPrecision(1e-8);
    return 0;
}



