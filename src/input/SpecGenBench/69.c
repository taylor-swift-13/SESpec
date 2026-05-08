int foo69(int n, int time);

int foo69(int n, int time) {

        time = time % (n - 1) * 2;
        if (time < n) {
            return time + 1;
        }
        return n * 2 - time - 1;
}
