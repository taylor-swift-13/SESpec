
/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
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
