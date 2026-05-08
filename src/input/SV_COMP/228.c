int unknown();

void foo228(int x) {

    unsigned int count;
    int exp;
    int term;
    int result;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));

    while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
      }

  }
