
int fun24(int n) {
    int i = 7;
    int x = 1;

    while(i <= n) {
        x += 1;
        i += 3;
    }
    return x;
}

int goo24() {
    int a = fun24(10);
    //@ assert a == 3;
}