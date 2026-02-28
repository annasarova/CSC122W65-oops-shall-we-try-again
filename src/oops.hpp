#pragma once

#include <string>
/*
When designing the validated input function, I chose to have the function
return a boolean value indicating whether the user successfully entered a
valid number or chose to abort. This avoids returning a special numeric value
to represent aborting, which could be confused with legitimate data if the
valid range changes. It also avoids throwing exceptions for normal user
behavior. By returning true for successful input and false for abort, while
passing the chosen number through an output parameter, the function clearly
communicates both outcomes. This makes the function reusable, prevents
ambiguity, and keeps the responsibility for handling abort logic in the
calling code.
*/

/*
Function: getValidatedInt
Purpose:
    Prompts the user for an integer within a specified range.
    Supports optional default value and optional abort keyword.

Parameters:
    lowerBound   -> minimum allowed value
    upperBound   -> maximum allowed value
    prompt       -> message shown to user
    errorMsg     -> message shown for invalid input
    result       -> reference where valid value is stored
    allowDefault -> enables "default" keyword
    defaultValue -> value returned if "default" entered
    allowAbort   -> enables "exit" keyword

Returns:
    true  -> valid value entered
    false -> user chose to abort
*/
bool getValidatedInt(short lowerBound,
                     short upperBound,
                     const std::string& prompt,
                     const std::string& errorMsg,
                     short& result,
                     bool allowDefault = false,
                     short defaultValue = 0,
                     bool allowAbort = false);
