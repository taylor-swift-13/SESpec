
typedef struct __CheckCal
{
        int pkv[10];
        int len;
        int chksum;

} CheckCal;

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
    requires \valid(pIp);
    requires \valid(pIp->pkv + (0..9));
    requires \forall integer i; 0 <= i < 10 ==> 0 <= pIp->pkv[i] <= 100;
    requires pIp->len <= 10;
    ensures pIp->chksum == sum(&pIp->pkv[0], 0, pIp->len);
    ensures \forall integer j; 0 <= j < 10 ==> pIp->pkv[j] == \old(pIp->pkv[j]);
    ensures pIp->len == \old(pIp->len);
    assigns pIp->chksum;
*/
void CheckCalFun(CheckCal *pIp){
        int i = 0;
        int chksum = 0;

        /*@ 
          loop invariant (0 < \at(pIp,Pre)->len) ==> (0 <= i <= \at(pIp,Pre)->len);
          loop invariant (0 < \at(pIp,Pre)->len) ==> (chksum == sum(&pIp->pkv[0], 0, i));
          loop invariant (!(0 < \at(pIp,Pre)->len)) ==> ((chksum == 0)&&(i == 0)&&(pIp == \at(pIp,Pre))&&(\at(pIp,Pre)->len == \at(pIp->len,Pre))&&(\at(pIp,Pre)->chksum == \at(pIp->chksum,Pre)));
          loop invariant pIp == \at(pIp,Pre);
          loop invariant \at(pIp,Pre)->len == \at(pIp->len,Pre);
          loop invariant \at(pIp,Pre)->chksum == \at(pIp->chksum,Pre);
          loop invariant \forall integer j; 0 <= j < 10 ==> pIp->pkv[j] == \at(pIp->pkv[j],Pre);
          loop assigns i, chksum;
        */
        for (; i < pIp->len; i++){
            chksum = chksum + pIp->pkv[i];
        }
        
        pIp->chksum = chksum;
}
