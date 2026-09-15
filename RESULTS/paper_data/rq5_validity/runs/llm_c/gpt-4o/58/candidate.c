int unknown();

/*@
    requires x >= 0;
    assigns octant1, octant2, count, multFactor, term, oddExp, evenExp;
    ensures \true; // No specific postcondition as the function does not return a value or modify external state.
*/
void foo242(int octant1, int octant2, int x) {

    unsigned int count;
    int multFactor;
    int temp;
    double oddExp;
    double evenExp;
    double term;

    octant1 = 0;
    octant2 = 3.14159 / 8;
    oddExp = x;
    evenExp = 1.0;
    term = x;
    count = 2;
    multFactor = 0;

    /*@
        loop invariant count >= 2;
        loop invariant oddExp == \at(x, Pre) + \sum(2 <= i < count && i % 2 == 1, multFactor * term);
        loop invariant evenExp == 1.0 + \sum(2 <= i < count && i % 2 == 0, multFactor * term);
        loop assigns count, multFactor, term, oddExp, evenExp;
        loop variant unknown(); // The termination condition is unknown due to the external function.
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
