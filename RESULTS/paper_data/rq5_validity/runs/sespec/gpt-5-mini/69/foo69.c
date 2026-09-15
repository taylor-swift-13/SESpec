
/*@
  logic integer div_floor(integer a, integer b) =
    b <= 0 ? 0 : a / b;
*/
        
void foo69(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    
            
        /*@
          loop invariant (0 < \at(n,Pre)) ==> (i + j + k == l);
          loop invariant (0 < \at(n,Pre)) ==> (j <= l);
          loop invariant (0 < \at(n,Pre)) ==> (i <= l);
          loop invariant (0 < \at(n,Pre)) ==> (k <= l);
          loop invariant (0 < \at(n,Pre)) ==> (
            i >= 0 && i <= l
          );
          loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns i, j, k, l;
        */
            while (l < n) {
       if ((l % 3) == 0) {
       i = i + 1;
      }
       else if((l % 2) == 0){
       j = j + 1;
      }
       else{
       k = k + 1;
      }
       l = l + 1;
      }
            

  }
