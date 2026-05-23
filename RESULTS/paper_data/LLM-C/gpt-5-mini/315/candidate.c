int maxVolume(int s);

/*@
    requires s >= 1;
    assigns \nothing;
    ensures \result >= 0;
    ensures \forall integer L, B;
        1 <= L <= s && 1 <= B <= s - L + 1 ==> \result >= L * B * (s - L - B);
    ensures \exists integer L, B;
        1 <= L <= s && 1 <= B <= s - L + 1 && \result == L * B * (s - L - B);
*/
int maxVolume(int s) {

        int maxVolume = 0;

        /*@
            loop invariant 1 <= l && l <= s + 1;
            loop invariant maxVolume >= 0;
            loop invariant \forall integer L, B;
                1 <= L < l && 1 <= B <= s - L + 1 ==> maxVolume >= L * B * (s - L - B);
            loop assigns l, maxVolume;
            loop variant s - l + 1;
        */
        for (int l = 1; l <= s; l++) {
            /*@
                loop invariant 1 <= b && b <= s - l + 2;
                loop invariant maxVolume >= 0;
                loop invariant \forall integer B;
                    1 <= B < b ==> maxVolume >= l * B * (s - l - B);
                loop assigns b, maxVolume;
                loop variant s - l + 2 - b;
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
