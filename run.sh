#! /bin/sh

# Copyright (C) 2021 Quentin M. Kniep <hello@quentinkniep.com>
# Distributed under terms of the MIT license.

g++ -std=c++17 $1
./a.out < B-large-practice.in | colordiff -y /dev/stdin B-large-practice.out
