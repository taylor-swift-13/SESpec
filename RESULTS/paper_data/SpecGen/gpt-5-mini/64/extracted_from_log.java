class SVCOMP_linear_0172__253 {
static int unknown() {
    //@ ensures \result == 0;
    //@ assignable \nothing;
return 0;
}

static void foo253() {
    //@ ensures true;
    //@ assignable \nothing;

int i;
int j;
int a;
int b;

a = 0;
b = 0;
j = 1;
i = 1;

//@ maintaining a >= 0;
//@ maintaining i == 1 + 2 * a;
//@ maintaining j == 1 + a;
//@ maintaining b == - (a * (a - 1)) / 2;
//@ decreases Integer.MAX_VALUE - a;
while (unknown() != 0) {
a = a + 1;
b = b + j - i;
i = i + 2;
if (i % 2 == 0){
j = j + 2;
}
else{
j = j + 1;
}
}

}
}