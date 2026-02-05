
/*@
    requires a>=n && n==0;
    */
    
int main1(int a,int n){
 
  int x,y,z;
  
  x=0;
  y=1;
  z=6;
  

  
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant (\at(n,Pre)<=\at(a,Pre)) ==> (n >= \at(n,Pre) && n <= a + 1);
              loop invariant (\at(n,Pre)<=\at(a,Pre)) ==> (x == (n * n * n));
              loop invariant (\at(n,Pre)<=\at(a,Pre)) ==> (y == (3 * n * n + 3 * n + 1));
              loop invariant (\at(n,Pre)<=\at(a,Pre)) ==> (z == (6 * n + 6));
              loop invariant (!(\at(n,Pre)<=\at(a,Pre))) ==> ((z == 6)&&(y == 1)&&(x == 0)&&(n == \at(n,Pre))&&(a == \at(a,Pre)));
              loop invariant a == \at(a,Pre);
              loop assigns n, x, y, z;
            */
            while(n<=a){
       n=n+1;
       x=x+y;
       y=y+z;
       z=z+6;
  }
            
  /*@ assert (n==a+1) && (y == 3*n*n + 3*n + 1) && (x == n*n*n) && (z == 6*n + 6);*/
}
