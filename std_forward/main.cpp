#include <iostream>

void g(int& value)
{
    std::cout << "lvalue reference g" << std::endl;
}

void g(int&& value)
{
    std::cout << "rvalue reference g" << std::endl;
}

void f(int& value)
{
    std::cout << "lvalue reference f" << std::endl;
    g(value);
}

void f(int&& value)
{
    std::cout << "rvalue reference f" << std::endl;

    // IMPORTANT! g(int&) will be called!
    g(value);
}

void h(int& value)
{
    std::cout << "lvalue reference f" << std::endl;
    g(std::forward<int&>(value));
}

void h(int&& value)
{
    std::cout << "rvalue reference f" << std::endl;
    g(std::forward<int&&>(value));
}

int main()
{
    /////////////////// Example without std::forward ////////////////////

    // Calling f(x)
    // lvalue reference f
    // lvalue reference g
    // Calling f(4)
    // rvalue reference f
    // lvalue reference g <----- !!!

    int x=3;
    std::cout << "Calling f(x)" << std::endl;
    f(x);
    std::cout << "Calling f(4)" << std::endl;
    f(4);


    /////////////////// Example with std::forward ////////////////////

    // std::forward is used in perfect forwarding.
    //
    // If param is rvalue reference then std::forward does nothing.
    // std::forward<int&&>(5)
    //
    // If param is lvalue reference then std::forward behaves like std::move
    // int x;
    // int &y = x
    // std::forward<int&>(y)

    // Calling h(x)
    // lvalue reference f
    // lvalue reference g
    // Calling h(5)
    // rvalue reference f
    // rvalue reference g

    std::cout << "Calling h(x)" << std::endl;
    h(x);

    std::cout << "Calling h(5)" << std::endl;
    h(5);
}