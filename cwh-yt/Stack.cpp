#include <iostream>
#include <stack> // C++ has a built in library implementation of a stack under the STL library
using namespace std;

int main()
{
    // Create a stack of strings called cars
    stack<string> cars;


    // The .empty() function returns 1 (true) if the stack is empty and 0 (false) otherwise:
    cout << cars.empty(); // Outputs 1 (The stack is empty)



    // Add elements to the stack
    cars.push("Volvo");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda");

    // Access the top element
    cout << cars.top(); // Outputs "Mazda"

    // Change the value of the top element
    cars.top() = "Tesla";

    // Access the top element
    cout << cars.top(); // Now outputs "Tesla" instead of "Mazda"

    // Remove the last added element (Tesla)
    cars.pop();

    // Access the top element (Now Ford)
    cout << cars.top();

    // return the count of no of elements in the stack
    cout << cars.size();

    return 0;
}