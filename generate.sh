#!/bin/sh

#  generate.sh
#  GaussDistrib
#
#  Created by Pawel Paruzel on 04/12/2017.
#  Copyright © 2017 Pawel Paruzel. All rights reserved.

mkdir -p build
rm -f "Resources/graph.png"
g++ -std=c++14 main.cpp -o "build/main.x"
./build/main.x
gnuplot plothist.gnu
rm -Rf build
open "Resources/graph.png"
