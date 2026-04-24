class SVCOMP_unlinear_0005__13 {
static int main13(int x,int y) {

int a=x;
int b=y;
int p=1;
int q=0;

while(a!=0 && b!=0) {
if (a % 2 ==0 && b % 2 ==0 ){
a = a/2;
b = b/2;
p = 4*p;
}
else if (a % 2 ==1 && b % 2 ==0 ){
a = a-1;
q = q+b*p;
}
else if (a % 2 ==0 && b % 2 ==1 ){
b = b-1;
q = q+a*p;
}
else {
a = a-1;
b = b-1;
q = q+(a+b+1)*p;
}
}

return 0;
}
}
