//
//  main.cpp
//  GaussDistrib
//
//  Created by Pawel Paruzel on 02/12/2017.
//  Copyright © 2017 Pawel Paruzel. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Randomizer.hpp"

//Randomizer r{};     // global randomizer
Randomizer r{1995}; // fixed global randomizer

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
    constexpr int SIZE  = 20;
    constexpr int ITERS = 10000;
    int hist[SIZE+1];
    for (int i{0}; i<SIZE+1; ++i)
    {
        hist[i] = 0;
    }
    for (int i{0}; i<ITERS; ++i)
    {
        double val = gdist();
        int index = std::round(val*(SIZE/2));
//        std::cout << "approx: " << (val*SIZE/2) << " goes to " << index+SIZE/2 << std::endl;
        ++hist[index+SIZE/2];
    }
    for (int i{-SIZE/2}; i<SIZE/2+1; ++i)
    {
        if (i >= 0) { std::cout << " "; }
        int hash_num = hist[i+SIZE/2]/(1+2*(int)(ITERS/1000));
        std::cout << " " << i << ". \t" << std::string(hash_num, '#') << std::endl;
    }
}
