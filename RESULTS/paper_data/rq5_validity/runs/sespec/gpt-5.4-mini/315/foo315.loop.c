
/*@
logic integer vol(integer l, integer b, integer h) = l * b * h;
*/

int foo315(int s) {

        int foo315 = 0;

        /*@ 
          loop invariant l >= 1;
          loop invariant s == \at(s,Pre);
          loop invariant foo315 >= 0;
          loop assigns l, foo315;
        */
        for (int l = 1; l <= s; l++) {

            /*@ 
              loop invariant 1 <= b <= s - l + 2;
              loop invariant foo315 >= 0;
              loop invariant s == \at(s,Pre);
              loop assigns b, foo315;
            */
            for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > foo315) {
                    foo315 = volume;
                }
            }
            
        }
            
        return foo315;
}
