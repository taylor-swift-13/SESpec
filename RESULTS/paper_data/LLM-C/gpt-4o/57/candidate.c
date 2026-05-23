int unknown();

/*@
    requires \true;
    assigns octant, count, multFactor, temp, oddExp, evenExp, term;
    ensures \true;
*/
void foo241(int octant, int x) {

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

    /*@
        loop invariant count >= 2;
        loop invariant evenExp == \at(evenExp, Pre) + \sum(2, count - 1, (multFactor * term));
        loop invariant oddExp == \at(oddExp, Pre) + \sum(2, count - 1, (multFactor * term));
        loop assigns term, multFactor, evenExp, oddExp, count;
        loop variant unknown();
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
