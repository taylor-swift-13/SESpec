/*@
    requires s >= 0;
    ensures \result >= 0;
    ensures \exists integer l, b, h; 1 <= l <= s && 1 <= b <= s - l + 1 && h == s - l - b && \result == l * b * h;
*/
int maxVolume(int s) {

        int maxVolume = 0;

        /*@
            loop invariant 1 <= l <= s + 1;
            loop invariant maxVolume >= 0;
            loop assigns l, b, h, volume, maxVolume;
        */
        for (int l = 1; l <= s; l++) {
            /*@
                loop invariant 1 <= b <= s - l + 2;
                loop invariant maxVolume >= 0;
                loop assigns b, h, volume, maxVolume;
            */
            for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > maxVolume) {
                    maxVolume = volume;
                }
            }
        }
        return maxVolume;
}
