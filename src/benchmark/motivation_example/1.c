
typedef struct __CheckCal
{
        int pkv[10];
        int len;
        int chksum;

} CheckCal;


/*@
    requires \valid(pIp);
    requires \valid(pIp->pkv + (0..9));
    requires \forall integer i; 0 <= i < 10 ==> 0 <= pIp->pkv[i] <= 100;
    requires pIp->len <= 10;
*/ 
void CheckCalFun(CheckCal *pIp){
        int i = 0;
        int chksum = 0;

        for (; i < pIp->len; i++){
            chksum = chksum + pIp->pkv[i];
        }
        
        pIp->chksum = chksum;

}
/*@
    requires \valid(pIp);
    requires \valid(pIp->pkv + (0..9));
    requires \forall integer i; 0 <= i < 10 ==> 0 <= pIp->pkv[i] <= 100;
    requires pIp->len <= 10;
*/
void foo(CheckCal *pIp)
{

    pIp->len = 3;
    CheckCalFun(pIp);
    /*@ assert pIp->chksum == pIp->pkv[0] + pIp->pkv[1] + pIp->pkv[2]; */
}




typedef struct __CheckCal
{
        int pkv[10];
        int len;
        int chksum;

} CheckCal;

void CheckCalFun(CheckCal *pIp){
        int i = 0;
        int chksum = 0;

        for (; i < pIp->len; i++){
            chksum = chksum + pIp->pkv[i];
        }
        
        pIp->chksum = chksum;

}

void foo(CheckCal *pIp)
{

    pIp->len = 3;
    CheckCalFun(pIp);
    /*@ assert pIp->chksum == pIp->pkv[0] + pIp->pkv[1] + pIp->pkv[2]; */
}

