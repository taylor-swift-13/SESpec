/*@ requires (x + y) == k; */
void foo166(int k, int x, int y) {

    int j;
    int i;
    int n;
    int m;

    m = 0;
    j = 0;


    while(j < n){
       if(j == i){
       x = x + 1;
       y = y - 1;
       j = j + 1;
       if(unkown()){
       m = j;
      }
      }
       else if(j != i){
       x = x - 1;
       y = y + 1;
       j = j + 1;
       if(unkown()){
       m = j;
      }
      }

      }

    /*@ assert (j >= n) ==> ((x + y)); */

  }