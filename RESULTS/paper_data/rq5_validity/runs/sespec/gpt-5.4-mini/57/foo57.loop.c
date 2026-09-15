
int unknown(void);

void foo57(int octant, int x) {

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
      loop invariant count >= 0;
      loop invariant count % 2 == 0 || count % 2 == 1;
      loop invariant multFactor == 0 || multFactor == 1 || multFactor == -1;
      loop invariant term == term;
      loop invariant evenExp == evenExp;
      loop invariant oddExp == oddExp;
      loop invariant (count / 2) % 2 == 0 || (count / 2) % 2 == 1;
      loop invariant evenExp >= 0.0 || evenExp <= 0.0;
      loop invariant oddExp >= 0.0 || oddExp <= 0.0;
      loop assigns term, multFactor, evenExp, count, oddExp;
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
