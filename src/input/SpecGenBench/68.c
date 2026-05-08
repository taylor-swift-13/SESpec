int foo68(int n, int time);

int foo68(int n, int time) {

        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
}
