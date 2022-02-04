/* 
 * Abstraction, Modularity, Interfaces, Pointers
 * 
 * Software structures model real world objects and concepts
 * 
 * Modularity
 *      - Each module "does one thing well"
 *      - Each module keeps its secrets secret
 * 
 * Abstranction
 *      - Unimportant details are hidden
 *      - Modules are as general and as useful as possible
 * 
 * Why do we care, why is this good?
 *      - it just makes everything easier
 * 
 * -----------
 * 
 * Abstract Data Types (courtesy of Hanson)
 * 
 * Collections!
 *      - list
 *      - stack
 *      - queue
 *      - blah
 *      - blah
 *      - blah
 * 
 * Example of an interface, Hanson's list.h 
 * 
 */


#ifndef LIST_INCLUDED
#define LIST_INCLUDED

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* We declare the type List_T to be a struct pointer (its #defined to T but  */
/* ignore that because its weird)                                            */
/* The type List_T and the struct List_T are two different things in two     */
/* different namespaces!                                                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* What's important is that the external type List_T is a pointer to an      */
/* internal struct also called List_T. But the client doesn't know how to    */
/* dereference the pointer, so it can't access the internals of the struct   */
/* without help from the implementation.                                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define T List_T
typedef struct T *T;

struct T {
	T rest;
	void *first;
};

/* * * * * * * * * * * * * * * * * * * * * */
/* Things you might want to do with a list */
/* just trust that it works.               */
/* * * * * * * * * * * * * * * * * * * * * */
extern T      List_append (T list, T tail);
extern T      List_copy   (T list);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* We are using void pointers because they let us point to AnYtHiNg  */
/* we call this UNIVERSAL POLYMORPHISM                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
extern T      List_list   (void *x, ...);
extern T      List_pop    (T list, void **x);
extern T      List_push   (T list, void *x);
extern T      List_reverse(T list);
extern int    List_length (T list);
extern void   List_free   (T *list);
extern void   List_map    (T list, void apply(void **x, void *cl), void *cl);
extern void **List_toArray(T list, void *end);

#undef T
#endif /* LIST_INCLUDED */