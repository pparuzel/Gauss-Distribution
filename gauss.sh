#!/bin/sh

#  generate.sh
#  GaussDistrib
#
#  Created by Pawel Paruzel on 04/12/2017.
#  Copyright © 2017 Pawel Paruzel. All rights reserved.

mkdir -p build
g++ -std=c++14 main.cpp -o "build/main.x"
./build/main.x "res/cxx_hist.dat"
