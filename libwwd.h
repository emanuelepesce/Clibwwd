/*
* libwwd.h
*/
#ifndef LIBWWD_H_
#define LIBWWD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int getNumberOfCols(char* line, char* del);
int getNumberOfRows(FILE *file);
char *str_replace (const char *string, const char *substr, const char *replacement );
double** loadData(FILE *file, int nCols, int nRows, char *del);
double** readCSVFile(char* filename);
int* getDatasetSize(char *filename);
void showData(int nRows, int nCols, double** data);

#endif /*libwwd.h*/

