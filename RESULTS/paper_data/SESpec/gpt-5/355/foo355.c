
/*@
  assigns \nothing;
*/
int foo355(int num) {

    int result = 0;
    int end = 0;
    int sum = num;
        
    /*@
      loop invariant 0 <= result;
      loop invariant num == \at(num,Pre);
      loop invariant (\at(num,Pre) > 0) ==> (0 <= result);
      loop invariant (\at(num,Pre) > 0) ==> (sum > 0 ==> result >= 0);
      loop invariant (\at(num,Pre) > 0) ==> (sum > 0 ==> (result == 0 || result > 0));
      loop invariant (\at(num,Pre) > 0) ==> (sum == 0 ==> result >= 0);
      loop assigns end, sum, result;
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
