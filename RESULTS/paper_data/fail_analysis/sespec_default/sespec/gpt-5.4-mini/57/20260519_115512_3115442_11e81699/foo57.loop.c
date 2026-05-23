
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@ 
  predicate even(integer n) = n % 2 == 0;
*/

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

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant multFactor == 1 || multFactor == -1 || multFactor == 0;
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
