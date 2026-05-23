
int foo325(int num) {

    int first = 1;

    /*@
      loop invariant num == \at(num,Pre);
      loop invariant 2 <= j;
      loop invariant (j <= \at(num,Pre)) ==> (j <= num);
      loop invariant (j == 2) ==> (first == 1);
      loop invariant (j <= \at(num,Pre)) ==> (first >= 1);
      loop assigns j, first;
    */
    for (int j = 2; j <= num; j++) {
        first *= j;
    }

    int result = 0;
    
    /*@
      loop invariant 0 <= result <= 9;
      loop invariant (first > 0) ==> (result >= 0 && result <= 9);
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }
            
    return result;
}
