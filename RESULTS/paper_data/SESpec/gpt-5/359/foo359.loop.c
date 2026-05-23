
int foo359(int size) {

    int ret = 0;
    int total = 0;

    /*@
      loop invariant size == \at(size,Pre);
      loop invariant (c <= \at(size,Pre)) ==> (0 <= ret);
      loop invariant (c <= \at(size,Pre)) ==> (0 <= total <= c - 1);
      loop invariant (c <= \at(size,Pre)) ==> (\forall integer k; 1 <= k < c && k % 2 == 1 ==> 1 <= k && k < c);
      loop invariant (c <= \at(size,Pre)) ==> (ret >= total);
      loop invariant (c <= \at(size,Pre)) ==> (ret >= 0 && total >= 0);
      loop invariant (c <= \at(size,Pre)) ==> ((c % 2 == 0) ==> (ret == (c/2) * (c/2)));
      loop invariant (c <= \at(size,Pre)) ==> ((c % 2 == 1) ==> (ret == (c/2) * (c/2)));
      loop invariant (c <= \at(size,Pre)) ==> ((ret == 0) ==> (total == 0) ==> (c == 1));
      loop invariant (c <= \at(size,Pre)) ==> (1 <= c ==> ret >= (c >= 2 ? 1 : 0));
      loop invariant (c <= \at(size,Pre)) ==> (total <= size);
      loop invariant (c <= \at(size,Pre)) ==> (ret > 0 || total == 0);
      loop invariant (c <= \at(size,Pre)) ==> (total == 0 ==> c <= 1);
      loop invariant (c <= \at(size,Pre)) ==> (c >= 1);
      loop invariant (c <= \at(size,Pre)) ==> (total <= c - 1);
      loop assigns c, ret, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }

    return ret / total;
}
