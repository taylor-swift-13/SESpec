

/*@
requires \valid(p) && \valid(q);
assigns \nothing;
ensures \result == *p + *q;
*/
int add14(int *p, int *q) {
    return *p + *q;
}

int moo14() {
    int a = 24;
    int b = 32;
    int x;

    x = add14(&a, &b) ;
    // @ assert x == a + b ;
    // @ assert x == 56 ;

    x = add14(&a, &a) ;
    // @ assert x == a + a ;
    // @ assert x == 48 ;
    return 0;
}