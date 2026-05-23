/*@ 
  requires s >= 0;
  assigns \nothing;
  ensures \result >= 0;
*/
int maxVolume(int s);

int maxVolume(int s) {

        int maxVolume = 0;

        /*@
          loop invariant 1 <= l <= s + 1;
          loop invariant maxVolume >= 0;
          loop assigns l, maxVolume;
          loop variant s - l + 1;
        */
        for (int l = 1; l <= s; l++) {
            /*@
              loop invariant 1 <= b <= (s - l + 1) + 1;
              loop invariant maxVolume >= 0;
              loop assigns b, maxVolume;
              loop variant (s - l + 1) - b + 1;
            */
            for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                /*@ assert h >= -1; */
                int volume = l * b * h;
                if (volume > maxVolume) {
                    maxVolume = volume;
                }
            }
        }
        return maxVolume;
}
