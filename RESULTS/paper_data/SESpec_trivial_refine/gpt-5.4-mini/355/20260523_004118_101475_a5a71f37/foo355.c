
/*@
  assigns \nothing;
  ensures \true;
*/
int foo355(int num) {

    int result = 0;
    int end = 0;
    int sum = num;

    /*@
      loop invariant 0 <= result;
      loop invariant sum > 0 ==> sum == (num >> result);
      loop assigns result, sum, end;
    */
    while (sum > 0) {
        if (result % 2 == 1) {
            end |= (1 << result);
        }
        result++;
        sum >>= 1;
    }

    return (num | end);
}
