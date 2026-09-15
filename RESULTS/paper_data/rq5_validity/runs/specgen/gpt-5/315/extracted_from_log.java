public class Sespec0315 {
    //@ ensures \result >= 0;
    //@ ensures s <= 1 ==> \result == 0;
    /*@ spec_public @*/ static int foo315(int s) {
        int foo315 = 0;
        //@ maintaining l >= 1;
        //@ maintaining foo315 >= 0;
        //@ decreases (s < 1 ? 0 : s - l + 1);
        for (int l = 1; l <= s; l++) {
            //@ maintaining b >= 1;
            //@ maintaining foo315 >= 0;
            //@ decreases (s - l + 1 < 1 ? 0 : s - l + 2 - b);
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
}