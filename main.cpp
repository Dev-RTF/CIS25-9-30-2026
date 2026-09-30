/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int* allocateArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size) {
        arr[i] = 0;
    }
    return arr;
    // the memory is never deleted...
}

// if we call this function from main as-is, we get a memory leak (allocated memory that can't get deleted until the program finishes, so just stays there)
// prevent this by remembering to use delete every time there is a new
// it's good practice to delete and set to nullptr, it doesn't really matter if it's in main since it's getting deleted anyway
void doSomeStuff() {
    int* x = allocateArray(5);
    // do stuff

    return;
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
    // or you can use the function above: int* studentIDs = allocateArray(size);
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
    
    // MEMORY CLEANUP
    
    // deallocate memory
    // free memory that was allocated for studentIDs using the new operator 
    delete studentIDs; // delete the thing at this memory address
    // if you don't set it to nullptr, it's a dangling pointer
    studentIDs = nullptr; // retire the memory address value (which now points to nothing, or to garbage, or something else)
    cout << "\nThe pointer points to: " << studentIDs; // still points to same adddress
    cout << "\nThe value at that location is: " << studentIDs[0]; // a random number
    
    
    return 0;
}