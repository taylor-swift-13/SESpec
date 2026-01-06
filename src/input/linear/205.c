void foo205() {

    int x;
    int y;

    y = x;


    while(x < 1024){
       x = x + 1;
       y = y + 1;
      }

    /*@ assert x == y; */

  }