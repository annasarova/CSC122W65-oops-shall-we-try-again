#include <string>
#include <iostream>
#include "oops.hpp"

// Implementation of validated integer input function
bool getValidatedInt(short lowerBound,
                     short upperBound,
                     const std::string& prompt,
                     const std::string& errorMsg,
                     short& result,
                     bool allowDefault,
                     short defaultValue,
                     bool allowAbort)
{
    std::string input;   // stores raw user input
    bool valid = false;  // becomes true when valid number entered
    bool aborted = false; // becomes true if user types exit

    // Loop until user enters valid value or aborts
    while (!valid && !aborted)
    {
        // Display prompt
        std::cout << prompt;

        // Show default hint if enabled
        if (allowDefault)
            std::cout << " (type \"default\" for " << defaultValue << ")";

        // Show abort hint if enabled
        if (allowAbort)
            std::cout << " (type \"exit\" to abort)";

        std::cout << "\n";

        // Read user input as string
        std::cin >> input;

        // Check abort keyword
        if (allowAbort && input == "exit")
        {
            aborted = true;
        }
        // Check default keyword
        else if (allowDefault && input == "default")
        {
            result = defaultValue;
            valid = true;
        }
        else
        {
            try
            {
                // Convert string to short
                short value = static_cast<short>(std::stoi(input));

                // Check range validity
                if (value >= lowerBound && value <= upperBound)
                {
                    result = value;
                    valid = true;
                }
                else
                {
                    // Out of range
                    std::cout << errorMsg << "\n";
                }
            }
            catch (...)
            {
                // Non-numeric input
                std::cout << errorMsg << "\n";
            }
        }
    }

    // Function returns true only if valid input entered
    return valid && !aborted;;
}

