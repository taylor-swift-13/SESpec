
/*@ logic integer count_with_last{L}(int *a, integer m, integer last_index, integer p) =
      m <= 0 ? 0
      : count_with_last{L}(a, m-1, last_index, p)
        + ( a[m-1] + a[last_index] == p ? 1 : 0 );
*/

/*@
  requires array_len >= 0;
  requires num >= 0 && num <= array_len;
  requires \valid_read(array + (0..array_len-1));
  requires \forall integer k; 0 <= k < array_len ==> 0 <= array[k] <= 100;
  assigns \nothing;
*/
int foo244(int * array, int array_len, int num, int p) {

    int ret = 0;
    
    /*@
      loop invariant 0 <= index;
      loop invariant 0 <= ret;
      loop invariant p == \at(p,Pre);
      loop invariant num == \at(num,Pre);
      loop invariant array_len == \at(array_len,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant \forall integer k; 0 <= k < array_len ==> 0 <= array[k] <= 100;
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {
        
        /*@
          loop invariant 0 <= index && index < num;
          loop invariant index + 1 <= j && j <= num;
          loop invariant 0 <= ret;
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> 0 <= array[k] <= 100;
          loop assigns j, ret;
        */
        for (int j = index + 1; j < num; j++) {
            if (array[index] + array[j] == p) {
                ret++;
            }
        }
        
    }
    return ret;
}
