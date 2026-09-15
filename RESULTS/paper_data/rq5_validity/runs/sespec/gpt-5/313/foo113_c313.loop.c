
int foo113_c313(int count) {

    int ret = 0;
    int diameter = 2 * count;
    int center = diameter * diameter;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index >= 1;
              loop invariant center == (2 * count) * (2 * count);
              loop invariant diameter == 2 * count;
              loop invariant count == \at(count,Pre);
              loop invariant 0 <= ret;
              loop assigns index, ret;
            */
            for (int index = 1; index <= 2 * count; index++) {
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant i >= 1;
              loop invariant center == (2 * count) * (2 * count);
              loop invariant diameter == 2 * count;
              loop invariant count == \at(count,Pre);
              loop invariant 0 <= ret;
              loop assigns i, ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
                int diagnalLengthSquare = (index * index + i * i);
                if (diagnalLengthSquare <= center) {
                    ret++;
                }
            }
            
        }
            
        return ret;
}
