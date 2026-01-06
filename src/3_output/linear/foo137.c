
/*@
    requires v3 >= 0 && v1 <= 5 && (v1 - v3) >= 0 && v2 * 2 - v1 - v3 == 0 && v2 + 5 >= 0 && v2 <= 5;
    */
    
void foo137(int v1, int v2, int v3) {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;


    
            /*@
          loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (v2 * 2 + t * 2 >= \at(v2,Pre) * 2);
          loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x1 == 100 + v1 * t);
          loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x3 == -50 + v3 * t);
          loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t >= 0);
          loop invariant (!(\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5)) ==> ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == \at(v3,Pre))&&(v2 == \at(v2,Pre))&&(v1 == \at(v1,Pre)));
          loop invariant v3 == \at(v3,Pre);
          loop invariant v1 == \at(v1,Pre);
          loop assigns x1, x2, x3, v2, t;
            */
            while(v2 + 5 >= 0 && v2 <= 5){
       x1 = x1 + v1;
       x3 = x3 + v3;
       x2 = x2 + v2;
       if(x2 * 2 - x1 - x3 >= 0){
       v2 = v2 - 1;

      }
       else if(x2 * 2 - x1 - x3 <= 0){
       v2 = v2 + 1;
      }
       t = t + 1;
      }
            

    /*@ assert v2 * 2 + t * 2 >= v1 + v3; */

  }
