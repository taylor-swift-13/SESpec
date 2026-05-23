
        
        

void foo58(int octant1, int octant2, int x) {

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
          loop invariant octant1 == 0;
          loop invariant term == term;
          loop invariant evenExp == evenExp;
          loop invariant oddExp == oddExp;
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
