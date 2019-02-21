//
//  Foo.h
//  Ex_iOS_CPP_Swift
//
//  Created by Augusto Sanson Cadini on 20/02/19.
//  Copyright © 2019 Augusto Sanson Cadini. All rights reserved.
//

#ifndef Foo_h
#define Foo_h

// 1. Callback simple way
void printFromCPP();

typedef void (*callback_sum_t) (double);             // Type definition called: callback_sum_t
void setCallbackSum(callback_sum_t _Nonnull f);      // Function to setup function's pointer
double sumSimple(double a, double b);                // Sum Function's header (Default call)
void sumCallback(double a, double b);                // Sum Function's header with callback return

// 2. Callback using Struct
struct StructCallback {                                               // Define a struct
    void (* _Nonnull deliveryToSwift)(const char * _Nonnull msg);     // Define a function's prototype
};
typedef struct StructCallback StructCallbacks;                        // Define a struct prototype
void SetupStructCallback(const StructCallbacks * _Nonnull callback);  // Function to setup function's pointer
void invokeSwiftFunctionFromCpp(void);                                // Define function prototype

#endif /* Foo_h */
