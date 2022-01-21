/* rawness.c
 * 
 * By Erin Lovell, Liam Strand
 * On January 21, 2022
 * 
 * Contains functions that read a "plain" pnm and outputs the brightness of the image pixels.
 * To do this we used built-in C libraries.
 * 
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pnmrdr.h>

void readPicture(FILE *fp);

int main(int argc, char *argv[])
{
    /* checks if the corrent number of arguments are being entered by user */ 
    if (argc != 2) {
        fprintf(stderr, "Incorrect number of arguments, exiting\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    /* if file does not exist, print error message and exit program */
    if (fp == NULL) {
        fprintf(stderr, "%s: Could not open file %s for reading\n", argv[0], argv[1]);
        exit(1);
    }

    readPicture(fp);
    
    /* free memory allocated to file */
    fclose(fp);
    return 0;
}

void readPicture(FILE *fp)
{
    /* define pnm reader (pic) containing information such as mapdata and pointer to file */
    Pnmrdr_T pic = Pnmrdr_new(fp);
    /* retrieve data from pic */
    Pnmrdr_mapdata data = Pnmrdr_data(pic);

    /* print pnm information (magic, width, height, denominator) */
    printf("P2\n%d %d\n%d\n", data.width, data.height, data.denominator);

    FILE *outfile = fopen("output.pgm", "w");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file output.pgm for writing\n");
        exit(1);
    }

    fprintf(outfile, "P5\n%d %d\n%d\n", data.width, data.height, 255);
    
    int tmp = 0;

    /* print brightness of every pixel contained in pnm */
    for (unsigned i = 0; i < data.height; i++) {
        for (unsigned j = 0; j < data.width; j++) {
            /* store next read-in integer in tmp, then print integer to console */
            fscanf(fp, "%d", &tmp);
            
            float tmp_f = tmp;

            /* make sure all pixel brightnesses are in the range of 0-255 */
            int scaled_tmp = (int) ((tmp_f / data.denominator) * 255);
            
            printf("%d ", scaled_tmp);

            /* store the integer as a char and write it to the output file */
            fprintf(outfile, "%c", scaled_tmp);

        }

        printf("\n");
    }

    /* free memory allocated to outfile and pnm reader */
    fclose(outfile);
    Pnmrdr_free(&pic);
}