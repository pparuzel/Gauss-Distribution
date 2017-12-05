//
//  Randomizer.cpp
//  GaussDistrib
//
//  Created by Pawel Paruzel on 02/12/2017.
//  Copyright © 2017 Pawel Paruzel. All rights reserved.
//

#include <random>

class Randomizer
{
    std::mt19937 gen{std::random_device{}()};
public:
    Randomizer() = default;
    
    explicit Randomizer(std::mt19937::result_type seed) : gen(seed) {}
    
    int range(int min, int max)
    {
        return std::uniform_int_distribution<int>{min, max}(gen);
    }
    
    double range(double min, double max)
    {
        return std::uniform_real_distribution<double>{min, max}(gen);
    }
    
    double normal()
    {
        return std::normal_distribution<>{0., 1.}(gen);
    }
};
