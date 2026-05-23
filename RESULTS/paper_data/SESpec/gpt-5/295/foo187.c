
/*@ logic integer fib(integer n) =
      n <= 0 ? 2 :
      n == 1 ? 1 :
      fib(n-1) + fib(n-2);
*/

/*@
  requires num >= 2;
  ensures \result == fib(num);
*/
int foo187(int num) {

    int *result = (int *)malloc(sizeof(int) * (num + 1));
    int result_len = num + 1;
    result[0] = 2;
    result[1] = 1;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 2 <= l;
      loop invariant l < num ==> l + 1 <= num;
      loop invariant result_len == num + 1;
      loop invariant result[0] == 2;
      loop invariant result[1] == 1;
      loop invariant result[0] == fib(0);
      loop invariant result[1] == fib(1);
      loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2];
      loop invariant \forall integer k; 0 <= k < l ==> result[k] == fib(k);
      loop assigns l, result[0 .. result_len-1];
      loop variant num - l;
    */
    for (int l = 2; l <= num; l++) {
        result[l] = result[l - 1]
                    + result[l - 2];
    }
        
    return result[num];
}
