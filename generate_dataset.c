/**
 * Date: 15/07/2020
 */

#include <stdio.h>
#include <stdlib.h>

#define SEED 1
//RAND_MAX is 2147483647

float scale(int num_to_scale, int range_max);

int main(int argc, char* argv[])
{
	int num_pts, dim, range;

	char* input_file_name = argv[1];
	if (input_file_name == NULL){fprintf(stderr, "Invalid input file name"); return 1;}

	FILE *input_file;
	input_file = fopen(input_file_name, "r");
	if (input_file == NULL){fprintf(stderr, "Can't open file"); return 1;}

	if (fscanf(input_file, "%d %d %d", &num_pts, &dim, &range) != 3)
	{
		if (feof(input_file)){fprintf(stderr, "Premature EOF");}
		else if(ferror(input_file)){fprintf(stderr, "Read error");}
		else {fprintf(stderr, "Format error");}
		return 1;
	}

	srand(SEED);
	for (int i = 0; i < num_pts; ++i)
	{
		for (int j = 0; j < (dim - 1); ++j)
		{
			printf("%f ", scale(rand(), range));
		}
		printf("%f\n", scale(rand(), range));	
	}	

	fclose(input_file);
	return 0;
}

float scale(int num_to_scale, int range_max)
{
	num_to_scale -= (RAND_MAX-1)/2;//map the number from [0, 2147483647] to [-1073741823, 1073741824]
	double scaled_num = (double) num_to_scale/(((RAND_MAX-1)/2)+1);
	scaled_num *= range_max;
	return (float) scaled_num;
}