class SVCOMP_linear_0118__204 {
static int unknown() {
return 0;
}

static void foo204(int x, int y) {

while(unknown()){
if(x >= 0 && y >= 0){
x = x - 1;
}
else if(x < 0 && y >= 0){
y = y - 1;
}
else if(y < 0){
x = x + 1;
y = y - 1;
}
}

}
}
