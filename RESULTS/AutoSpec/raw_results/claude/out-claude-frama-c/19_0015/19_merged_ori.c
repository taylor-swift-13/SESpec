/*@
requires \valid_read(b);
requires \valid(a);
requires \separated(a, b);
ensures *a == \old(*a);
ensures *a == 0;
disjoint behaviors;
complete behaviors;
behavior b_true:;
behavior b_false:;
assumes *b == 0;
assumes *b != 0;
assigns *a;
```c;
```;
/*@;
*/
void reset_1st_if_2nd_is_true(int* a, int const* b){
    if(*b) *a = 0 ;
}

int moo19(){
    int a = 5 ;
    int x = 0 ;
    reset_1st_if_2nd_is_true(&a, &x);
    // @ assert a == 5 ;
    // @ assert x == 0 ;

    int const b = 1 ;
    reset_1st_if_2nd_is_true(&a, &b);
    // @ assert a == 0 ;
    // @ assert b == 1 ;
    return 0;
}

