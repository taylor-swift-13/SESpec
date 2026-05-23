#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo57(int octant, int x) 
/*@

Require emp
Ensure emp
*/{

    unsigned int count;
    int multFactor;
    int temp;
    double oddExp;
    double evenExp;
    double term;

    octant = 3.14159 / 3;
    oddExp = x;
    evenExp = 1.0;
    term = x;
    count = 2;
    multFactor = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (count >= 0) &&
    (count % 2 == 0 || count % 2 == 1) &&
    (multFactor == 0 || multFactor == 1 || multFactor == -1) &&
    (term == term) &&
    (evenExp == evenExp) &&
    (oddExp == oddExp) &&
    ((count / 2) % 2 == 0 || (count / 2) % 2 == 1) &&
    (evenExp >= 0.0 || evenExp <= 0.0) &&
    (oddExp >= 0.0 || oddExp <= 0.0)
    */
    
    while(unknown()){
       term = term * (x / count);

       if((count / 2) % 2 == 0)
       multFactor = 1;
       else
       multFactor = -1;

       evenExp = evenExp + multFactor * term;

       count = count + 1;

       term = term * (x / count);

       oddExp = oddExp + multFactor * term;

       count = count + 1;
      }

  }