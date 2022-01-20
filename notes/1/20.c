/* 
 * 
 * 
 * 
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char world[] = "world";
    printf("Hello %s\n", world);

    char name[] = "NOAH";

    for (size_t i = 0; i < strlen(name); i++)
    {
        printf("The number for %c is %u\n", name[i], name[i]);
    }
    
    printf("The string %s os %lu bytes long\n", name, strlen(name));
    
    printf("\nBegin Exercise One:\n");
    printf("Hello %s\n", world);
    world[1] = '\0';
    printf("Hello %s your string is %lu bytes long!\n", world, strlen(world));
    world[3] = 'm';
    printf("Hello %s your string is %lu bytes long!\n", world, strlen(world));
    world[1] = 'o';
    printf("Hello %s your string is %lu bytes long!\n", world, strlen(world));
    world[4] = '\0';
    printf("Hello %s your string is %lu bytes long!\n", world, strlen(world));
    printf("End Exercise One\n");

    (void)argc;
    (void)argv;

    /* VOID POINTERS */

    int   x     = 77;
    int  *x_ptr = &x;
    void *v_ptr = x_ptr;      /* A void pointer cannot be dereferenced */
    char *c_ptr = v_ptr;      /* so we must copy it to a typed pointer */
    char  c     = *c_ptr;     /* before dereferencing                  */

    printf("%c\n", c);

    return 0;
}

