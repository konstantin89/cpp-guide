#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

void StringsExample()
{
    std::vector<std::string> input = {"hello", "world", "transform", "example"};
    std::vector<std::string> result;

    std::transform(input.begin(), input.end(), std::back_inserter(result),
                   [](const std::string& str) 
                   {
                       std::string upper;
                       for (char c : str) {
                           upper += std::toupper(c);
                       }
                       return upper;
                   });

    for (const auto& str : result) 
    {
        std::cout << str << " ";
    }

    std::cout << std::endl;
}

void VectorsExample()
{
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {5, 6, 7, 8};
    std::vector<int> result;

    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(result),
                   [](int a, int b) { return a + b; });

    for (const auto& value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    StringsExample();

    VectorsExample();

    return 0;
}