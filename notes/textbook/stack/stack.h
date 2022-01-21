#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#define T Stack_T
typedef struct T *T;

/* Manufacture a new Stack_T */
extern T     Stack_new   (void);

/* Returns 1 if empty, 0 otherwise */
extern int   Stack_empty (T stk);

/* pushes a pointer onto a Stack_T */
extern void  Stack_push  (T stk, void *x);

/* removes and returns a pointer from the top of Stack_T */
extern void *Stack_pop   (T stk);

/* Takes a pointer to a Stack_T and deallocates it */
extern void  Stack_free  (T *stk);

#undef T
#endif /* STACK_INCLUDED */