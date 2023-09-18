#include <unordered_map>
#include <string>
#include <iostream>

void UnorderedMapExample()
{
    std::unordered_map<std::string, int> myMap;

    myMap["Key1"] = 10;
    myMap["Key2"] = 20;

    auto interator = myMap.find("Key1");
    if(interator != myMap.end())
    {
        std::cout << "Key1 is found in unordered map, value=" << interator->second << std::endl;
    }

    std::cout << "Unordered map content: ";
    for (const auto& pair : myMap) 
    {
        std::cout << pair.first << ": " << pair.second << ", ";
    }
    std::cout << std::endl;
}