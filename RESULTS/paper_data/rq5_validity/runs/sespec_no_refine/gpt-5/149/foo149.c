
/*@
  assigns \nothing;
  ensures (\result == 0) ==> (\exists integer d; 2 <= d && d <= a/2 && a % d == 0);
*/
int foo149(int a) {

    int i = 2;
    int mid = a/2;

    /*@
      loop invariant i >= 2;
      loop invariant mid == a / 2;
      loop invariant a == \at(a,Pre);
      loop assigns i;
    */
    while (i <= mid) {
        if (a%i == 0)
            return 0;
        i++;
    }

    return 1;
}
