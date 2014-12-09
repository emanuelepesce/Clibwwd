Clibwwd
=======

A C library for Working easily With Datasets <br\>
Version: 1.0
---------------------------------------------

It cointains: <br\>
libwwd.c: source file that contains the main functions of the library <br\>
libwwd.h: header file<br\>
example.c: file containing a simple example of use<br\>
dataset_iris: famous iris dataset created by R.A. Fisher (more info about:https://archive.ics.uci.edu/ml/datasets/Iris)

---------------------------------------------
Instructions <br\>
1. Compile it <br\>
    i.e.: $ gcc -o driver example.c libwwd.c <br\>
2. Execute
    i.e.: $ ./driver dataset_iris.csv <br\>

---------------------------------------------
Notes: for now it supports CSV files with only numerics values separated by comma. <br\>


