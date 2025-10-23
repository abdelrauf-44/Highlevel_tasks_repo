#include <iostream> 
using namespace std; 

/**
 * @file pointers.cpp
 * @brief Demonstrates basic pointer operations and concepts in C++
 * 
 * This program shows how to work with pointers, including pointer arithmetic,
 * array access using pointers, and address manipulation.
 */

int main(){
    // Array initialization with 4 integer elements
    int num[]{10, 20, 30, 40}; 
    
    // Pointer initialization - points to the first element of the array
    // Note: When array name is used alone, it decays to a pointer to its first element
    int *ptr = num; // equivalent to int *ptr = &num[0];

    cout << "--- Demonstrating array access using both array notation and pointer arithmetic ---\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Element " << i << ":\n";
        cout << "Value using array notation: " << num[i] << "\n";
        // ptr+i calculates the address of the i-th element from the base address
        cout << "Address using pointer arithmetic: " << (ptr+i) << "\n";
        // &num[i] directly gets the address of the i-th element
        cout << "Address using array notation: " << &num[i] << "\n"; 
        // *(ptr+i) dereferences the address to get the value (equivalent to num[i])
        cout << "Value using pointer dereferencing: " << *(ptr+i) << "\n";
        cout << "-------------------\n";
    }

    cout << "\n--- Demonstrating pointer increment operation ---\n";
    // Increment pointer to point to the next element (num[1])
    ptr++; 
    cout << "After ptr++:\n";
    cout << "Value at new position: " << *(ptr) << "\n"; // Should be 20 (second element)
    cout << "New address: " << (ptr) << "\n";

    cout << "\n--- Demonstrating pointer addition ---\n";
    // Move pointer 2 elements forward (from num[1] to num[3])
    ptr+=2; 
    cout << "After ptr+=2:\n";
    cout << "Value at new position: " << *(ptr) << "\n"; // Should be 40 (fourth element)
    cout << "New address: " << (ptr) << "\n";

    cout << "\n--- Demonstrating pointer decrement operation ---\n";
    // Decrement pointer to point to previous element (num[2])
    ptr--; 
    cout << "After ptr--:\n";
    cout << "Value at new position: " << *(ptr) << "\n"; // Should be 30 (third element)
    cout << "New address: " << (ptr) << "\n";

    return 0; // Added explicit return statement for good practice
}

/**
 * IMPORTANT NOTES ON POINTERS
 * ==========================
 * 
 * BASIC POINTER CONCEPTS:
 * ----------------------
 * 1. A pointer is a variable that stores the memory address of another variable
 * 2. Declaration syntax: data_type* ptr; or data_type *ptr;
 * 3. & operator: Gets the address of a variable (e.g., &variable)
 * 4. * operator: Dereferences a pointer (accesses the value at the address)
 * 
 * POINTER INITIALIZATION:
 * ----------------------
 * - data_type* ptr = &variable;  // Points to a variable
 * - data_type* ptr = nullptr;    // Null pointer (C++11 and later)
 * - data_type* ptr = NULL;       // Null pointer (C style)
 * - data_type* ptr = 0;          // Null pointer (old style)
 * 
 * POINTER ARITHMETIC:
 * -----------------
 * - ptr++    : Moves pointer to the next element (adds sizeof(data_type) bytes)
 * - ptr--    : Moves pointer to the previous element
 * - ptr += n : Moves pointer forward n elements
 * - ptr -= n : Moves pointer backward n elements
 * - ptr1 - ptr2 : Returns number of elements between two pointers (same type)
 * 
 * COMMON POINTER MISTAKES:
 * ----------------------
 * - Dereferencing uninitialized pointers
 * - Dereferencing null pointers
 * - Memory leaks (not freeing dynamically allocated memory)
 * - Dangling pointers (pointing to freed memory)
 * - Buffer overflows (accessing beyond allocated memory)
 * 
 * ARRAYS AND POINTERS:
 * ------------------
 * - Array name decays to a pointer to its first element
 * - arr[i] is equivalent to *(arr + i)
 * - &arr[i] is equivalent to (arr + i)
 * 
 * VOID POINTERS:
 * ------------
 * - A void pointer (void*) can point to any data type
 * - Used when the type is not known at compile time
 * - Requires explicit casting before dereferencing: *(data_type*)void_ptr
 * - Cannot perform pointer arithmetic directly on void pointers
 * 
 * KEY BENEFITS OF VOID POINTERS:
 * ----------------------------
 * 1. Type Flexibility: Can store addresses of any data type, enabling generic 
 *    functions and data structures
 * 
 * 2. Type Agnostic Memory Operations: Essential for memory allocation functions
 *    like malloc(), calloc(), realloc() which return void*
 * 
 * 3. Interface Unification: Creates interfaces that work with multiple data types
 * 
 * 4. Runtime Type Determination: Allows for polymorphic behavior when the actual
 *    type is determined at runtime
 * 
 * VOID POINTER EXAMPLE:
 * ------------------
 * void* ptr = &someVariable;  // Can point to any data type
 * int* intPtr = static_cast<int*>(ptr);  // C++ style casting (preferred)
 * int* intPtr2 = (int*)ptr;  // C style casting
 * 
 * SMART POINTERS (C++11 AND LATER):
 * -------------------------------
 * - std::unique_ptr: Exclusive ownership model
 * - std::shared_ptr: Shared ownership model with reference counting
 * - std::weak_ptr: Non-owning reference to shared_ptr
 * 
 * FUNCTION POINTERS:
 * ----------------
 * - Store address of functions
 * - Allow for callbacks and runtime function selection
 * - Syntax: return_type (*ptr_name)(parameter_types)
 */