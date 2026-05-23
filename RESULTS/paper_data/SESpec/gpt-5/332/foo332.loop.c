
int foo332(int num, int c) {

    int result = 1;
    if (num == c) {
        return 1;
    } else if ((c - num) >= 5) {
        return 0;
    } else {
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant c == \at(c,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant (var == \at(num,Pre) + 1) ==> (result == 1);
          loop invariant (var < \at(c,Pre) + 1) ==> (var <= \at(c,Pre));
          loop invariant (var < \at(c,Pre) + 1) ==> (1 <= var - \at(num,Pre));
          loop assigns var, result;
        */
        for (int var = num + 1; var < c + 1; var++) {
            result = (result * (var % 10)) % 10;
        }
        
        return result % 10;
    }
}
