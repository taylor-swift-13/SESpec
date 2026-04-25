int unknown();
void foo160(int n) {
    int x = 1;
    int m = 1;

    while (x < n) {

        if (unknown()) {
            m = x;
        }

        x = x + 1;
    }

}
