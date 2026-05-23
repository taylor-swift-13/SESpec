
/*@
  ensures \true;
  assigns \nothing;
*/
int foo76(int * args, int args_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant (\at(y,Pre) - 1 >= 0) ==> (i >= 0 && i <= r + 1);
      loop invariant !(\at(y,Pre) - 1 >= 0) ==> (k == -1 && r == \at(y,Pre) - 1 && i == 0 && y == \at(y,Pre) && x == \at(x,Pre) && args_len == \at(args_len,Pre) && args == \at(args,Pre));
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant \forall integer p; 0 <= p < args_len ==> args[p] == \at(args[p],Pre);
      loop assigns k, i, r;
    */
    while (i <= r) {
        int tmp = (i + r) / 2;
        if (args[tmp] == x) {
            k = tmp;
            i = tmp + 1;
        } else if (args[tmp] < x) {
            i = tmp + 1;
        } else {
            r = tmp - 1;
        }
    }

    return k;
}
