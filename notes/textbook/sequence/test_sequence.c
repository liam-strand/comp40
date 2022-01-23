#include <seq.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    Seq_T names = Seq_new(10);

    for (int i = 0; i < 15; i++) {

        int *r_p = malloc(sizeof(int));
        *r_p = rand();
        void *r_vp = r_p;

        Seq_addlo(names, r_vp);
    }

    for (int i = 0; i < Seq_length(names); i++) {
        int *item = Seq_get(names, i);
        
        printf("%d ", *item);
    }
    printf("\n");

    return(EXIT_SUCCESS);
}