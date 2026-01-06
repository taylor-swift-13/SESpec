
/*@
    requires k == x + y;
    */
    
void foo197(int k, int x, int y) {

    int i;
    int j;
    int m;
    int n;

    m = 0;
    j = 0;


    
            /*@
          loop invariant (0 < n) ==> (j >= 0 && j <= n);
          loop invariant (0 < n) ==> (((m == 0)&&(j == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(k == \at(k,Pre))) || (m >= 0 && m <= j));
          loop invariant (!(0 < n)) ==> ((m == 0)&&(j == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns j, m, x, y;
            */
            while(j < n){
       if(unknown()){
       m = j;
      }
       if(j == i){
       x = x + 1;
       y = y - 1;
      }
       else{
       x = x - 1;
       y = y + 1;
      }
       j = j + 1;
      }
            

    /*@ assert (n > 0) ==> (m >= 0); */

  }
