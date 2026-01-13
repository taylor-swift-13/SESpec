typedef struct __CheckCal
{
        int pkv[10];
        int len;
        int chksum;

} CheckCal;


/*@
    requires \valid(pIp);
    requires 0 <= pIp->len <= 10;
    requires \valid_read(pIp->pkv + (0 .. pIp->len - 1));
    ensures pIp->chksum == \sum(0, pIp->len - 1, \lambda integer k; pIp->pkv[k]);
    assigns pIp->chksum;
*/
void CheckCalFun(CheckCal *pIp){
    int i = 0;
    int chksum = 0;

    /*@
      loop invariant 0 <= i <= pIp->len;
      loop invariant chksum == \sum(0, i - 1, \lambda integer k; pIp->pkv[k]) \/
                         (i == 0 && chksum == 0);
      loop assigns i, chksum;
      loop variant pIp->len - i;
    */
    for (; i < pIp->len; i++){
        chksum = chksum + pIp->pkv[i];
    }
    
    pIp->chksum = chksum;
}

void foo(CheckCal *pIp)
{

    pIp->len = 3;
    CheckCalFun(pIp);

}