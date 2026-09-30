/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int myFunction(int x, int arr[]) {
    
}

int main()
{
    int myInteger = 5;
    cout << "The value of myInteger is: " << &myInteger << "\n"; 
    
    int* myPointer;
    myPointer = &myInteger;
    cout << "The value of myPointer is: " << myPointer << "\n";
    cout << "The address of myPointer is: " << &myPointer << "\n";
    
    // allocating memory is sort of unique to C/C++
    // -> great memory efficiency, because you have manual access to when memory is allocated
    
    // Allocate memory when you don't know how much memory something is going to use until the program is already running
    // and/or when the memory usage varies (because usually the compiler (?) sets aside an "expected" amount of memory)
    
    // array, but we don't know how much space is needed
    int size = -999;
    
    cout << "Please put in the size of the class: ";
    cin >> size;
    
    // int studentIDs[size]; // this is wrong, not C++, and MIGHT not work depending on what you're running it on
    
    // the correct way to do it
    int* studentIDs = new int[size]; // new: "reserve some space in ram for __"; without new, you have to know the size in advance BEFORE THE PROGRAM STARTS
    for (int i = 0; i < size; i++) {
        cout << "Please put in the studentID for the " << i << " index: ";
        cin >> studentIDs[i]; // even though studentIDs is a pointer, you can treat it with array syntax even if it's a pointer. an array is very similar and in many cases identical to a pointer of an array
        cout << "The memory address where that student ID will be stored is: " << &studentIDs[i] << endl; 
    }
    
    for (int i = 0; i < size; i ++) {
        cout << studentIDs[i] << "\n";
    }
    
    cout << "\nusing dereferencing syntax...\n";
    for (int i = 0; i < size; i ++) {
        // cout << *studentIDs << "\n"; // prints the first integer of the array
        cout << "Address:" << (studentIDs + i) << "\n"; // so this prints the ith integer in the array, the same as studentIDs[i]
        cout << "Value:" << *(studentIDs + i) << "\n";
    }
    
    
    return 0;
}