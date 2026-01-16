/*@
requires \valid(a) && \valid(b);
requires \separated(a, b);
ensures *b == \old(*a);
ensures *a == \old(*b);
assigns *a, *b;
*/
 void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int moo10(){
    int a = 42;
    int b = 37;

    swap(&a, &b);

    //@ assert a == 37 && b == 42;

    return 0;
}