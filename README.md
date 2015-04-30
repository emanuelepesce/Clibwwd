libwwd
=======

##About
A C library for Working easily With Datasets. <br\>
It provides functions in order to extract data from a csv file and to performs some useful operations such as print data or put data into a matrix. It also makes possible to work only on a part of data. <br\>
Version: 1.0 <br\>


It cointains: <br\>
- libwwd.c: source file that contains the main functions of the library <br\>
- libwwd.h: header file<br\>
- example.c: file which contain a simple example of use <br\>
- dataset_iris.csv: famous iris dataset created by R.A. Fisher (more info - - - about:https://archive.ics.uci.edu/ml/datasets/Irs)

##Instructions
1. Compile it (i.e.: $ gcc -o driver example.c libwwd.c) <br\>
2. Execute it (i.e.: $ ./driver dataset_iris.csv) <br\>

---------------------------------------------
##Notes
It supports CSV files with only numerics values separated by comma, but the code can be easily extends in order to support other delimitators.  <br\>


=============================================
##Author
[Emanuele Pesce](https://github.com/emanuelepesce/) <br\>

For each suggestion or contribution don't hesitate to contact me.

