
/*@ predicate recurrence_upto(int *w, int *C, integer b) =
      (\forall integer k; 2 <= k < b ==>
          w[k] == w[k-2] + 2 * C[k-1] &&
          C[k] == w[k-1] + C[k-2]); */

/*@ logic integer Cseq_logic(integer n); */

/*@ logic integer W_logic(integer n) =
      n <= 0 ? 1 :
      n == 1 ? 0 :
      W_logic(n-2) + 2 * Cseq_logic(n-1); */

/*@
  requires count >= 1;
  ensures count == \old(count);
*/
int foo50_c192(int count) {

    int *w = (int *)malloc(sizeof(int) * (count + 1));
    int w_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    w[0] = 1;
    w[1] = 0;
    C[0] = 0;
    C[1] = 1;
		
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 2 <= index <= count + 1;
      loop invariant w_len == count + 1 && C_len == count + 1;
      loop invariant (\forall integer k; 2 <= k < index ==> k <= count);
      loop invariant (\forall integer k; 2 <= k < index ==> 0 <= k-2 && 0 <= k-1 < index);
      loop invariant w[0] == w[0] && w[1] == w[1] && C[0] == C[0] && C[1] == C[1];
      loop assigns index, w[0 .. w_len-1], C[0 .. C_len-1];
    */
    for (int index = 2; index <= count; index++) {
        w[index] = w[index - 2]
                + 2 * C[index - 1];
        C[index] = w[index - 1] + C[index - 2];
    }
            
    return w[count];
}
