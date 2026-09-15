#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int counter;

int foo25_helper1_c4(int n);
void foo4(int n, int from, int to, int via);

void foo4(int n, int from, int to, int via) 
{
    if (n == 0) return;
    counter++;
    foo4(n - 1, from, via, to);
    foo4(n - 1, via, to, from);
}

void foo4(int n, int from, int to, int via) 
/*@

Require emp
Ensure emp
*/{
    if (n == 0) return;
    counter++;
    foo4(n - 1, from, via, to);
    foo4(n - 1, via, to, from);
}