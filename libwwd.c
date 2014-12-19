/*
 *	A collection of useful functions for working with datasets
 *  
 	Author: Emanuele Pesce
 *
 *  	Last Update: 5 December 2014
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libwwd.h"
#include <errno.h>

double** readCSVFile(char* filename){
/*
	Load in a matrix of double a CSV dataset.
	It works if csv file has only numerics values.
	
	returns
	matrix: double**, matrix of double that cointains dataset values
	
	arguments
	filename: char*, string that cointains name of the dataset file
*/
	double** matrix;
	char line[BUFSIZ];
	int nCols, nRows;
	FILE *fp;
	int *dim;
	
	/*	Open the file	*/
	fp = fopen(filename, "r");
	if (fp != NULL){
		/*	Get the number of columns and rows of the dataset	*/
		dim=getDatasetSize(filename);
		nRows=dim[0];
		nCols=dim[1];

		/*	Load dataset in a matrix of double	*/
		matrix = loadData(fp, nRows, nCols, ",");
	}
	/*error with the file opening */
	else{ 
		perror(filename);
	}
	return matrix;
}



double** loadData(FILE *file, int nRows, int nCols, char *del){
/*	
	Put the dataset values in a matrix.
	It assumes that dataset cointains only numerics values.	
	
	returns
	matrix: double**, a matrix that cointains the dataset values
	
	arguments
	file: FILE, file pointer of the dataset
	nCols: int, number of columns of the dataset
	nRows: number of rows of the dataset
*/
	int i,j; 
	char line[BUFSIZ], *stmp;
	double** matrix = malloc(nRows*sizeof(double*) );
	
	/*	Allocate matrix */
	for (i = 0; i < nRows; i++){
		matrix[i] = malloc(nCols*sizeof(double));
    }
	/*
	  	For each line, remove the separators and put elements in a matrix as
	 	double
	 */
	rewind(file);
	for ( i = 0; fgets(line, sizeof line, file); ++i ){
	     stmp = line;
	     stmp=str_replace(stmp, del, " ");
	     for ( j = 0; j<nCols; j++)
	     {		     
	        matrix[i][j] = strtold(stmp, &stmp);
	     }
	  }
	fclose(file);
	return matrix;
}



int getNumberOfCols(char* line, char* del){
/*
	Count the number of columns of a row.
	
	returns
	nCols: number of columns of a row
	
	arguments
	line: string, row of a dataset
	del: string, separator of the string values of line
*/
	char* col;
	int nCols = 0;
	
	for (col = strtok(line,del); col != NULL; col = strtok(NULL, del)){
		nCols++;
	}
	
	return nCols;
}


int getNumberOfRows(FILE *file){
/*
	Count the number of rows of a file
	It assumes that the last line does not cointan "\n"
	
	returns
	nRows: number of rows of a file
	
	arguments
	file: FILE, file pointer
*/
	int cur, nRows=0;
	
	while ( (cur=fgetc(file)) != EOF ) {
        if ( cur == '\n' )
            nRows++;
    }
	return nRows;
}



char *str_replace (const char *string, const char *substr, const char *replacement ){
/*
	implements a str_replace PHP like function	
	
	returns
	newstring: string, string modified
	
	arguments
	string: string, string to modify
	substring: string, substring to change in string
	replacement: string, string to substitute in string at place of substring
*/
  char *tok = NULL;
  char *newstr = NULL;
  char *oldstr = NULL;
  char *head = NULL;
 
  /* if either substr or replacement is NULL, duplicate string a let caller handle it */
  if ( substr == NULL || replacement == NULL ) return strdup (string);
  newstr = strdup (string);
  head = newstr;
  while ( (tok = strstr ( head, substr ))){
    oldstr = newstr;
    newstr = malloc ( strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) + 1 );
    /*failed to alloc mem, free old string and return NULL */
    if ( newstr == NULL ){
      free (oldstr);
      return NULL;
    }
    memcpy ( newstr, oldstr, tok - oldstr );
    memcpy ( newstr + (tok - oldstr), replacement, strlen ( replacement ) );
    memcpy ( newstr + (tok - oldstr) + strlen( replacement ), tok + strlen ( substr ), strlen ( oldstr ) - strlen ( substr ) - ( tok - oldstr ) );
    memset ( newstr + strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) , 0, 1 );
    /* move back head right after the last replacement */
    head = newstr + (tok - oldstr) + strlen( replacement );
    free (oldstr);
  }
  return newstr;
}


int* getDatasetSize(char *filename){
/*
	Counts the number of columns and rows of a dataset file
	
	returns
	dim: int*, dim[1]:number of rows, dim[2]: number of columns
	
	arguments
	filename: char*, string containing the name of the file
*/
	int *dim;
	char line[BUFSIZ];
	FILE *fp;
	
	dim = malloc(2*sizeof(int));
	
	/* Open the file	*/
	fp = fopen(filename, "r");
	if (fp != NULL){
		/*	Get the number of columns and rows of the dataset	*/
		dim[0]=getNumberOfRows(fp);
		rewind(fp);
		fgets(line, sizeof line, fp);
		dim[1]=getNumberOfCols(line, ",");
		
	}
	/*error with the file opening */
	else{ 
		perror(filename);
	}
	fclose(fp);
	return dim;
}


void showData(int nRows, int nCols, double** data){
/*
	Print the data matrix
	
	arguments
	nrows: int number of rows
	ncols: int, number of columns
	data: double **, matrix of data
*/
	int i, j;	
	printf("\n=========== Data =============\n");
  	for (j = 0; j < nCols; j++) 
  		printf("\tCol %d", j);
  	printf ("\n");
  	for (i = 0; i < nRows; i++){
  	   	printf("Row %d:", i);
    	for (j = 0; j < nCols; j++){ 
    	  	printf("\t%f",data[i][j]);
    	}
    printf("\n");
  }
  printf("\n");
  return;
}

