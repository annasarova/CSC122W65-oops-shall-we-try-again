#include <iostream>

#include "src/oops.hpp"

int main()
{
    short value; // variable to store user selection

    // Call validated input function
    bool success = getValidatedInt(
        0,                      // lower bound
        100,                    // upper bound
        "Please enter a value between 0 and 100:",
        "Your value is invalid.",
        value,                  // output variable
        true,                   // allow default option
        50,                     // default value
        true                    // allow abort option
    );

    // Display result depending on user choice
    if (success)
        std::cout << "The value chosen by the user is " << value << "\n";

    return 0;
}