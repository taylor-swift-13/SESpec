
/*@
  requires n <= 0 || n == 1;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  
  ensures n <= 0 ==> (\result == 0 || \result == 1);
  ensures n == 1 ==> (\result == 0 || \result == 1);
  ensures n == \old(n);
*/
int foo147(int n) {

        int temp = n;
        
            
        /*@
          loop invariant temp == \at(n,Pre) || temp != 0;
          loop invariant 0 <= temp || temp < 0;
          loop invariant n == \at(n,Pre);
          loop invariant temp >= 0 || temp < 0;
          loop invariant (temp != 0 && temp % 3 == 0) ==> (\at(n,Pre) % 3 == 0);
          loop invariant (temp != 0 && temp % 3 == 0) ==> (temp <= \at(n,Pre) || temp >= \at(n,Pre));
          loop invariant (temp != 0 && temp % 3 == 0) ==> (temp % 3 == 0);
          loop invariant (temp != 0 && temp % 3 == 0) ==> (temp != 1 || \at(n,Pre) == 1);
          loop invariant n == \at(n,Pre);
          loop assigns temp;
            */
            while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
            
        return temp == 1;
}
