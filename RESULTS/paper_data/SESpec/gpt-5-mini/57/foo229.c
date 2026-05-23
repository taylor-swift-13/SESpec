
/*@ predicate valid_counts(unsigned int count) = count >= 0; */

/*@
  requires \true;
*/
void foo229(int octant, int x) {

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
      loop invariant valid_counts(count);
      loop invariant multFactor == -1 || multFactor == 0 || multFactor == 1;
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
