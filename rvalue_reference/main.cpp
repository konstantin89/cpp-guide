#include <iostream>
#include <string>
#include <utility>

auto str_to_lower(std::string&& s) -> std::string
{
    std::cout << "By rvalue reference called" << std::endl;

    for(char& c: s)
    {
        c = std::tolower(c);
    }

    return s;
}

auto str_to_lower(const std::string& s) -> std::string
{
    std::cout << "By const lvalue reference called" << std::endl;

    std::string clone = s;

    for(char& c: clone)
    {
        c = std::tolower(c);
    }

    return clone;
}

std::string GetString()
{
    return std::string("String");
}

int main()
{
    std::string str1 = {"ConTent"};

    auto str2 = str_to_lower(str1); // lvalue reference
    std::cout << "ConTent->" << str2 << std::endl;

    auto str3 = str_to_lower("HelloTHere"); // rvalue reference
    std::cout << "HelloTHere->" << str3 << std::endl;

    auto str4 = str_to_lower(GetString()); // rvalue reference
    std::cout << GetString() << "->" << str4 << std::endl;

    return 0;
}