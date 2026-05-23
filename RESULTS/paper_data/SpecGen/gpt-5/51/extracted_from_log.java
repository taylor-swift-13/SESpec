class SVCOMP_linear_0099__188 {
//@ ensures \result == 0;
//@ assignable \nothing;
/*@ spec_public @*/ static int unknown() {
return 0;
}

//@ ensures true;
//@ assignable \nothing;
/*@ spec_public @*/ static void foo188() {

int x;
int y;
int z;
int w;

x = 0;
y = 0;
z = 0;
w = 0;

//@ maintaining x >= 0 && w >= 0 && x <= w;
//@ maintaining z == 10 * w;
//@ maintaining -100 * w <= y && y <= 100 * w;
while(unknown() != 0){
if(x >= 4){
x = x + 1;
y = y + 2;

}
else if(y > 10 * w && z >= 100 * x){
y = 0 - y;
}
else{
x = x + 1;
y = y + 100;
}
w = w + 1;
z = z + 10;
}

}
}