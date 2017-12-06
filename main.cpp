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
    double min=-4., max=4.;
    double x = r.range(min, max);
    double x_;
    double P;
    for (int i{0}; i<100; ++i)
    {
        x_ = r.range(min, max);
        P = std::min(exp(x*x-x_*x_), 1.);
        if (r.range(0., 1.) < P)
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
        path.replace(path.end()-8, path.end(), "Resources/histogram.dat");
    }
    std::ofstream file{path, std::ofstream::out};

    constexpr int ITERS = 1e6;
    for (int i{0}; i<ITERS; ++i)
    {
        file << gdist() << "\n";
    }
    file.close();
}
