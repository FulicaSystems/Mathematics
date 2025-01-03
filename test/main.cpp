#include <iostream>

#define CHKLK_OVERRIDE_NEW_OP

#include "mathematics.hpp"
#include "mathstream.hpp"

int main()
{

    // TODO : find a better way for rng (https://stackoverflow.com/a/322995)
    srand(static_cast<unsigned>(time(0)));

    std::cout << "mathematics testing ====================" << std::endl;
    // mathematics
    {
        std::cout << "Hello world !" << std::endl;

        vec<mat4, 2> v = {mat4::id, mat4::zo};

        std::cout << v << std::endl;

        vec<double, 4> d = {1.f, 2, 3.f, 4.f};

        std::cout << d << std::endl;
    }

    return 0;
}
