
/*@
  requires p != \null ==> p_len >= 0;
  requires \valid(p + (0 .. p_len - 1));
  requires \forall integer i; 0 <= i < p_len ==> 0 <= p[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \forall integer i; 0 <= i < p_len ==> p[i] == \at(p[i],Pre);
  ensures \result == 0 ==> (\forall integer i; 0 <= i < p_len ==> p[i] == \at(p[i],Pre));
*/
int foo231(int * p, int p_len, int array) {

    int count = 0;
    int total = p_len;

    /*@ 
      loop invariant 0 <= index;
      loop invariant total == \at(p_len,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant p_len == \at(p_len,Pre);
      loop invariant p == \at(p,Pre);
      loop invariant 0 <= count;
      loop invariant \valid(p + (0 .. total - 1));
      loop invariant \forall integer i; 0 <= i < total ==> p[i] == \at(p[i],Pre);
      loop invariant (index < \at(p_len,Pre) - 1) ==> (count >= 0);
      loop assigns index, count;
    */
    for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant 0 <= c;
          loop invariant 0 <= count;
          loop invariant c <= total;
          loop invariant \valid(p + (0 .. total - 1));
          loop invariant \forall integer k; 0 <= k < total ==> p[k] == \at(p[k],Pre);
          loop assigns c, count;
        */
        for (int c = index + 1; c < total; c++) {
            if (p[index] != p[c]) {
                count++;
            }
        }

    }

    return count;
}
