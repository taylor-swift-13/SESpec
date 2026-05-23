public class Sespec0315 {
    static int foo315(int s) {
        int foo315 = 0;
        for (int l = 1; l <= s; l++) {
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
