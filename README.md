Clibwwd
=======

A C library for Working easily With Datasets
Version: 1.0
---------------------------------------------

It cointains:
libwwd.c: source file that contains the main functions of the library
libwwd.h: header file
example.c: file containing a simple example of use
dataset_iris: famous iris dataset created by R.A. Fisher (more info about:https://archive.ics.uci.edu/ml/datasets/Iris)

---------------------------------------------
Instructions
1. Compile it
     i.e.: gcc -o driver example.c libwwd.c
2. Execute it
     i.e.: ./driver dataset_iris.csv

---------------------------------------------
Notes: for now it supports CSV files with only numerics values separated by comma.


