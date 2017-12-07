#!/usr/bin/env julia

#  gauss.jl
#  GaussDistrib
#
#  Created by Pawel Paruzel on 06/12/2017.
#  Copyright © 2017 Pawel Paruzel. All rights reserved.

using Plots;
plotly()

gen = MersenneTwister(19937)

x = 0

function gdist()
    global x
    δ = 0.2
    for i in 1:100
        x_ = x + δ * (2 * rand(gen) - 1)
        d = x*x - x_*x_;
        if (d > 0 || rand(gen) < exp(d))
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

