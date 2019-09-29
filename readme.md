# PID COntroller
[![Build Status](https://travis-ci.org/abhi1625/pid-controller.svg?branch=master)](https://travis-ci.org/abhi1625/pid-controller)
[![Coverage Status](https://coveralls.io/repos/github/abhi1625/pid-controller/badge.svg?branch=master)](https://coveralls.io/github/abhi1625/pid-controller?branch=master)
---

## Authors

- Driver    : [abhi1625](https://github.com/abhi1625)
- Navigator : [namangupta98](https://github.com/namangupta8)

## Overview

Simple PID Controller for velocity control. The overview of the code implementation is explained in the [PID_UML_activity_diagram](https://github.com/abhi1625/pid-controller/blob/master/PID_UML_activity_diagram.pdf). More detailed explanation of the class implementation and required methods is available as [PID_UML_class_diagram](https://github.com/abhi1625/pid-controller/blob/master/PID_UML_class_diagram.pdf) and [computePID_UML_activity_diagram](https://github.com/abhi1625/pid-controller/blob/master/computePID_UML_activity_diagram.pdf).   

## Standard install via command-line
```
git clone --recursive https://github.com/abhi1625/pid-controller
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.
