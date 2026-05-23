class SVCOMP_linear_0054__147 {
//@ ensures \result == 0;
static int unknown() {
return 0;
}

//@ ensures true;
static void foo147() {

int x;
int y;
int xa;
int ya;

xa = 0;
ya = 0;

//@ maintaining true;
while(unknown() != 0){
x = xa + ya * 2 + 1;
if(unknown() != 0){
y = ya - xa * 2 + x;
}
else{
y = ya - xa * 2 - x;
}
xa = x - y * 2;
ya = x * 2 + y;
}

}
}