#include <iostream>
#include <optional>

int main() 
{
    std::optional<int> maybeValue;

    if (maybeValue.has_value()) 
    {
        std::cout << "The optional contains a value: " << maybeValue.value() << std::endl;
    } 
    else 
    {
        std::cout << "The optional is empty." << std::endl;
    }

    maybeValue = 42;

    if (maybeValue.has_value()) 
    {
        std::cout << "The optional now contains a value: " << maybeValue.value() << std::endl;
    } 
    else 
    {
        std::cout << "The optional is empty." << std::endl;
    }

    int value = maybeValue.value_or(0); // Default value 0 if empty

    std::cout << "The value (or default) is: " << value << std::endl;

    return 0;
}