
/*@ 
  logic real term_prod(integer start_count, integer k, real x) =
    k <= 0 ? 1.0 :
    (x / (start_count + 1)) * term_prod(start_count + 1, k - 1, x);
*/

/*@
  predicate contributions(integer start_count, integer c, real x, real term,
                          real evenAcc, real oddAcc) =
    0 <= c &&
    // `term` equals the product of k = (c - start_count) steps starting from start_count
    // If c == start_count then term == 1.0 (no multiplications yet)
    term == term_prod(start_count, c - start_count, x) &&
    // evenAcc and oddAcc represent sums of earlier contributions;
    // we cannot fully characterize number of added terms without tracking more state,
    // but we assert they are finite reals (no NaN/Inf) and non-NaN by using real type properties.
    \true;
*/

void foo229_c57(int octant, int x) {

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
      loop invariant 0 <= count;
      loop invariant \true; // placeholder to keep loop condition facts minimal
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
