#!/usr/bin/env julia

#  plotter.jl
#  GaussDistrib
#
#  Created by Pawel Paruzel on 06/12/2017.
#  Copyright © 2017 Pawel Paruzel. All rights reserved.

using Plots;
plotly()

gen = MersenneTwister(19937)

function gdist()
    x = rand(gen) * 8 - 4
    for i in 1:100
        x_ = rand(gen) * 8 - 4
        P = min(exp(x * x - x_ * x_), 1.)
        if (rand(gen) < P)
            x = x_
        end
    end
    return x
end

function gauss(filename)
    numbers = [gdist() for i in 1:1e6]
    writedlm(filename, numbers)
end

function generate()
    histogram([gdist() for i in 1:1e6], nbins=100)
end

function generate(filename)
    A = Array{Float64, 1}(0)
    A = readdlm(filename)
    histogram(A, nbins=100)
end

