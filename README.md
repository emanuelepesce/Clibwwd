Clibwwd
=======

##About
A C library for Working easily With Datasets. <br\>
It provides functions for getting data from a csv file and doing some useful operations such as print them, put them in a matrix. It's also possible working only on a part of data. <br\>
Version: 1.0 <br\>


It cointains: <br\>
- libwwd.c: source file that contains the main functions of the library <br\>
- libwwd.h: header file<br\>
- example.c: file containing a simple example of use <br\>
- dataset_iris.csv: famous iris dataset created by R.A. Fisher (more info - - - about:https://archive.ics.uci.edu/ml/datasets/Irs)

##Instructions
1. Compile it (i.e.: $ gcc -o driver example.c libwwd.c) <br\>
2. Execute it (i.e.: $ ./driver dataset_iris.csv) <br\>

---------------------------------------------
##Notes
For now it supports CSV files with only numerics values separated by comma. However the code can be easily extends for supporting others delimitators.  <br\>


=============================================
##Author
[Emanuele Pesce](https://github.com/emanuelepesce/) <br\>

For each suggestion or contribution don't hesitate to contact me.

