#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int counter;

int foo25_helper1(int n);
void foo25(int n, int from, int to, int via);

void foo25(int n, int from, int to, int via) 
{
    if (n == 0) return;
    counter++;
    foo25(n - 1, from, via, to);
    foo25(n - 1, via, to, from);
}

void foo25(int n, int from, int to, int via) 
/*@

Require emp
Ensure emp
*/{
    if (n == 0) return;
    counter++;
    foo25(n - 1, from, via, to);
    foo25(n - 1, via, to, from);
}