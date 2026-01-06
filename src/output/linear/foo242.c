
/*@
    requires x > octant1 && x < octant2;
    */
    
void foo242(int octant1, int octant2, int x) {
    double oddExp, evenExp, term;
    unsigned int count;
    int multFactor;
    int temp;

    octant1 = 0;
    octant2 = 3.14159 / 8;
    oddExp = x;
    evenExp = 1.0;
    term = x;
    count = 2;
    multFactor = 0;

    /*@
    loop invariant 2 <= count <= 1000;
    loop invariant term > 0.0;
    loop invariant multFactor == ((count/2) % 2 == 0) ? 1 : -1;
    loop invariant oddExp >= evenExp - term;
    loop invariant evenExp <= 1.0 + term;
    loop invariant oddExp <= x + term;
    loop invariant \abs(term * x/count) < \abs(term);
    loop assigns term, multFactor, evenExp, oddExp, count;
    */
    while(unknown()) {
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

    /*@ assert oddExp >= evenExp; */
}
