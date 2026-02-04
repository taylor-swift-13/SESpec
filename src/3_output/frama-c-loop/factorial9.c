
/*@
  logic integer factorial(integer x) =
    x <= 1 ? 1 : x * factorial(x - 1);
*/

int factorial9(int n) {

  int i = 1;
  int f = 1;

  
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (1 <= \at(n,Pre)) ==> (1 <= i <= n + 1) ;
          loop invariant (1 <= \at(n,Pre)) ==> (f == factorial(i - 1)) ;
          loop invariant (!(1 <= \at(n,Pre))) ==> ((f == 1)&&(i == 1)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
            */
            while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
            
  return f;
}
