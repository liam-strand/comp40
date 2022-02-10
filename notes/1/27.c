/* 
 * FUNCTION POINTERS
 * 
 * Just as we can have a pointer to the location of some variable in memory,
 * we can have a pointer to a function.
 * 
 * A function pointer is declared as such
 */

#include <stdio.h>
#include <stdlib.h>
#include <list.h>

/* declare a normal function */
int f(int x);

/* declare a function that returns a pointer */
int *g(int x);

/* declare a function pointer */
int (*h)(int x);

/* define f */
int f(int x) {
    return x + 1;
}

/* we can also make a function take a function pointer */
int func_app(int n, int f(int x)) {
    return f(n);
}

int cube(int n) {
    return n * n * n;
}

/* ok something useful now, mapping over a list */
void fun(void **x, void *cl) {
    int *elem = *x;
    int *accum_p = cl;
    *elem += 10;
    *accum_p += *elem;
}


int main()
{
    h = &f;                   /* the same thing as h = f */
    printf("%d\n", (*h)(4));  /* the same thing as h(4)  */

    int (*func_ptr)(int x);   /* parameters may be named */
    func_ptr = cube;
    printf("%d\n", cube(4));
    printf("%d\n", func_ptr(4));
    printf("%d\n", func_app(4, func_ptr));

    int *digits = malloc(3 * sizeof(*digits));
    int accum = 0;
    for (int i = 0; i < 3; i++) {
        *(digits + i) = i;
    }
    List_T list = List_list(digits, (void *)(digits + 1), 
                                    (void *)(digits + 2), NULL);

    List_map(list, fun, &accum);

    printf("%d\n", accum);

    return 0;
}