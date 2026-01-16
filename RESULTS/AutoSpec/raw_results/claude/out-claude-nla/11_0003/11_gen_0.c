/*@
requires z>=0 && z<=10 && k>0 && k<=10;
*/
int main11(int z,int k,int a){
  

    int x=a;
    int y=1;
    int c=1;
  
    /*@
    /*@ 
      loop invariant 1 <= c <= k;
      loop invariant x == a * (z^(c - 1)) + a * (z^(c - 2)) + ... + a * (z^0)  (expressed via recurrence);
      loop invariant y == z^c;
      loop assigns c, x, y;
    */
    */
    while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }
  
  // @ assert z*x-x+a-a*z*y == 0;
  }
  