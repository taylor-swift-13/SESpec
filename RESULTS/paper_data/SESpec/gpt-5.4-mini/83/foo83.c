
/*@
  logic integer power(integer b, integer e) =
    e <= 0 ? 1 : b * power(b, e - 1);

  logic integer geom_sum(integer b, integer e) =
    e <= 0 ? 1 : geom_sum(b, e - 1) * b + 1;
*/

/*@
  requires k >= 1;
*/
void foo83(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    
            
        /*@
          loop invariant 1 <= c <= k;
          loop invariant y == power(z, c - 1);
          loop invariant c >= 1;
          loop invariant c <= k;
          loop invariant a == \at(a,Pre);
          loop invariant k == \at(k,Pre);
          loop invariant z == \at(z,Pre);
          loop assigns c, x, y;
            */
            while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }
            

  }
