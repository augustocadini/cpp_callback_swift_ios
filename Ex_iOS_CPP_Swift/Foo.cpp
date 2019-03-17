//
//  Foo.cpp
//  Ex_iOS_CPP_Swift
//
//  Created by Augusto Sanson Cadini on 20/02/19.
//  Copyright © 2019 Augusto Sanson Cadini. All rights reserved.
//
 
#include <iostream>
#include <unistd.h>
#include "Ex_iOS_CPP_Swift-Bridging-Header.h"

using namespace std;

// * 1

// Type's definition
callback_sum_t callback_sum;

// Referencing function pointer
void setCallbackSum(callback_sum_t f) {
    callback_sum = f;
}

// Sum's function
double sumSimple(double a, double b) {
    return a + b;
}

void sumCallback(double a, double b) {
    double result = a + b;
    callback_sum(result);
}

// HelloWorld
void printFromCPP() {
    cout << "C++: Hello World from CPP" << endl;
}

// * 2

// Declare callback like variable
static StructCallback sCallback;

// Implement setup callback function to reference the function's pointer
void SetupStructCallback(const StructCallback *callback) {
    sCallback = *callback;
}

// Function to call and invoke callback to the Swift code
void invokeSwiftFunctionFromCpp(void) {
    sCallback.deliveryToSwift("Hello Swift! I'am C++!");
}
