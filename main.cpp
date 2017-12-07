//
//  main.cpp
//  GaussDistrib
//
//  Created by Pawel Paruzel on 02/12/2017.
//  Copyright © 2017 Pawel Paruzel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Randomizer.hpp"

Randomizer r{};         // global randomizer
//Randomizer r{1995};   // fixed global randomizer

double gdist()
{
    double min=-1., max=1.;
    double delta = 0.2;
    static double x = 0;
    double x_;
    for (int i{0}; i<100; ++i)
    {
        x_ = x + delta * r.range(min, max);
        auto d = x*x - x_*x_;
        if (d > 0 || r.range(0., 1.) < exp(d))
        {
            // accept
            x = x_;
        }
        // else reject
    }
    return x;
}

int main(int argc, char* argv[])
{
    std::string path = __FILE__;
    if (argc > 1)
    {
        path.replace(path.end()-8, path.end(), argv[1]);
    }
    else
    {
        std::cerr << "No arguments passed!" << std::endl;
        return 1;
    }
    std::ofstream file{path, std::ofstream::out};

    constexpr int ITERS = 1e6;
    for (int i{0}; i<ITERS; ++i)
    {
        file << gdist() << "\n";
    }
    file.close();
}
