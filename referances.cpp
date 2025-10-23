#include <iostream> 
using namespace std; 

/**
 * @file referances.cpp
 * @brief Demonstrates C++ references vs pointers
 */

int main(){
    // Original variable
    int num = 100; 
    // Pointer to num - stores address of num
    int* ptr = &num; 
    // Reference to num - an alias for num
    int& ref = num; 

    // All three ways access the same value
    cout << "Value via variable: " << num << "\n";
    cout << "Value via pointer:  " << *ptr << "\n";
    cout << "Value via reference:" << ref << "\n";
    
    // Addresses demonstrate that reference shares memory with original
    cout << "Address of variable: " << &num << "\n";
    cout << "Address in pointer:  " << ptr << "\n";
    cout << "Address of reference:" << &ref << "\n";

    return 0;
}

/**
 * REFERENCE NOTES:
 * --------------
 * 1. Must be initialized when declared - can't be null
 * 2. Can't be reassigned to refer to different variable
 * 3. No extra memory needed (unlike pointers)
 * 4. No dereferencing needed to access value
 * 5. No "reference arithmetic" (unlike pointer arithmetic)
 * 
 * REFERENCE vs POINTER:
 * ------------------
 * - Reference: alias that shares memory with original variable
 * - Pointer: variable that stores memory address of another variable
 * 
 * USE REFERENCES FOR:
 * ----------------
 * - Function parameters to avoid copies
 * - Function return values for chaining
 * - Avoiding null checks (references can't be null)
 * - When reassignment isn't needed
 */