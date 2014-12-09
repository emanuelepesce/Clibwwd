#include <stdio.h>
#include <stdlib.h>
#include "libwwd.h"

int main(int argc, char **argv){
	double** data;	
	int i,j, nCols, nRows;
	int* dim;
	
	printf("\nRunning..");
	
	/* Get the size of the size of the dataset  */
	dim=getDatasetSize(argv[1]);
	printf("\nRows: %d", dim[0]);
	printf("\nColumns: %d", dim[1]);
	nRows=dim[0];
	nCols=dim[1];

	/* Quick test print*/
	printf("\n \n Dataset: %s \n", argv[1]);
	data = readCSVFile(argv[1]);
	for (i=0; i<nRows; ++i){
		printf("\n");
		for (j=0; j<nCols; ++j){
			printf(" %f,", data[i][j]);
		}
	}
	
	
	printf("\nEnding..\n\n");
}
