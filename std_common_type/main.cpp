#include <iostream>
#include <type_traits>
#include <vector>
#include <variant>
#include <numeric>

template<class T>
struct Number 
{ 
    T n; 
};
 
template<class T, class U>
constexpr Number<std::common_type_t<T, U>>
    operator+(const Number<T>& lhs, const Number<U>& rhs)
{
    return {lhs.n + rhs.n};
}
 
void describe(const char* expr, const Number<int>& x)
{
    std::cout << expr << "  is  Number<int>{" << x.n << "}\n";
}
 
void describe(const char* expr, const Number<double>& x)
{
    std::cout << expr << "  is  Number<double>{" << x.n << "}\n";
}
 
int main()
{
    Number<int> i1 = {1}, i2 = {2};
    Number<double> d1 = {2.3}, d2 = {3.5};
    describe("i1 + i2", i1 + i2);
    describe("i1 + d2", i1 + d2);
    describe("d1 + i2", d1 + i2);
    describe("d1 + d2", d1 + d2);

    return 0;
}