
/*@
  logic integer initial_a = \at(a, Pre);
*/

/*@
  requires a > 0;
  assigns \nothing;
  ensures \result == 0 <==> (\exists integer i; 2 <= i <= initial_a / 2 && initial_a % i == 0);
  ensures \result == 1 <==> (\forall integer i; 2 <= i <= initial_a / 2 ==> initial_a % i != 0);
*/
int foo78(int a) {

    int i = 2;
    int mid = a / 2;

    /*@
      loop invariant (2 <= initial_a / 2) ==> (2 <= i <= mid + 1);
      loop invariant (!(2 <= initial_a / 2)) ==> ((mid == initial_a / 2) && (i == 2) && (a == initial_a));
      loop invariant mid == initial_a / 2;
      loop invariant a == initial_a;
      loop assigns i;
      loop variant mid - i;
    */
    while (i <= mid) {
        if (a % i == 0)
            return 0;
        i++;
    }

    return 1;
}
