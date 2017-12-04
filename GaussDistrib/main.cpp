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
        else
        {
            // reject
        }
    }
    return x;
}

int main()
{
    std::string path = __FILE__;
    path.replace(path.end()-8, path.end(), "Resources/histogram.dat");
    std::ofstream file{path, std::ofstream::out};

    constexpr int SIZE  = 21;
    constexpr int ITERS = 1000000;
    int hist[SIZE];
    for (int i{0}; i<SIZE; ++i)
    {
        hist[i] = 0;
    }
    constexpr int HALF_SIZE = SIZE/2;
    for (int i{0}; i<ITERS; ++i)
    {
        double val = gdist();
        int index = std::round(val*(HALF_SIZE));
        ++hist[index+HALF_SIZE];
    }
    int ii = 0;
    for (int i{-SIZE/2}; i<=SIZE/2; ++i)
    {
        file << std::fixed << std::setprecision(4);
        file << static_cast<double>(i)/SIZE*2 << "\t" << hist[ii] << std::endl;
        ++ii;
    }
    file.close();

    for (int i{-SIZE/2}; i<SIZE/2+1; ++i)
    {
        if (i >= 0) { std::cout << " "; }
        int hash_num = hist[i+SIZE/2]/(1+2*(int)(ITERS/1000));
        std::cout << " " << i << ". \t" << std::string(hash_num, '#') << std::endl;
    }
}
