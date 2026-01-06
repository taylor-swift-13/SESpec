/*@ requires i < n; */
void foo192(int i, int n) {

    int b;

    i = 0;


    while(i < n && b != 0){
       i = i + 1;
      }

    /*@ assert (i >= n) ==> (i == n && b != 0); */

  }