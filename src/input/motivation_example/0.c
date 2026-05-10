
typedef struct __CheckCal
{
        int pkv[10];
        int len;
        int chksum;

} CheckCal;



void Check(CheckCal *pIp){
        int i = 0;
        int chksum = 0;

        for (; i < pIp->len; i++){
            chksum = chksum + pIp->pkv[i];
        }
        
        pIp->chksum = chksum;

}


void boo(CheckCal *pIp)
{

    pIp->len = 3;
    Check(pIp);
    /*@ assert pIp->chksum == pIp->pkv[0] + pIp->pkv[1] + pIp->pkv[2]; */
}


