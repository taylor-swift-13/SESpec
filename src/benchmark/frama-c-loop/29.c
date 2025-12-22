int sum(char n) {
    int s = 0;
    char k = 0;

    while(k <= n) {    
        s = s + (int)k;
        k = k + 1;
    }
    return (int)s;
}

int goo29() {
    int s = sum(5);
    //@ assert s == 15;
}