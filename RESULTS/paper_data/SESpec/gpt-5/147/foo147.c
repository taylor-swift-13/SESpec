
/*@
  assigns \nothing;
  ensures (\result == 0) || (\result == 1);
  ensures n == 0 ==> \result == 0;
  ensures n == 1 ==> \result == 1;
  ensures n != 0 && n % 3 != 0 ==> \result == (n == 1);
*/
int foo147(int n) {

    int temp = n;

    /*@
      loop invariant n == \at(n,Pre);
      loop invariant (!(\at(n,Pre) != 0 && \at(n,Pre) % 3 == 0)) ==> (temp == \at(n,Pre));
      loop invariant (\at(n,Pre) != 0 && \at(n,Pre) % 3 == 0) ==> (temp != 0);
      loop invariant (\at(n,Pre) != 0 && \at(n,Pre) % 3 == 0) ==> ( (temp != 0 && temp % 3 == 0) ==> (temp/3 == temp / 3) );
      loop invariant (\at(n,Pre) != 0 && \at(n,Pre) % 3 == 0) ==> ( (temp == 0 || temp % 3 != 0) ==> (temp == temp) );
      loop invariant (\at(n,Pre) != 0 && \at(n,Pre) % 3 == 0) ==> (temp == 0 || temp % 3 == 0 || temp % 3 != 0);
      loop assigns temp;
    */
    while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }

    return temp == 1;
}
