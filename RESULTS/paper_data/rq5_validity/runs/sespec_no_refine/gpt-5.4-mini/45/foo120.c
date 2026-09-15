
/*@ predicate PLACE_HOLDER_v2(int v2, int t) = v2 == \at(v2,Pre) - t; */
/*@ predicate PLACE_HOLDER_x1(int x1, int t, int v1) = x1 == 100 + t * v1; */
/*@ predicate PLACE_HOLDER_x2(int x2, int t, int v2) = x2 == 75 + t * \at(v2,Pre); */
/*@ predicate PLACE_HOLDER_x3(int x3, int t, int v3) = x3 == -50 + t * v3; */
/*@ predicate PLACE_HOLDER_t(int t) = t >= 0; */

void foo120(int v1, int v2, int v3) {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;

    /*@
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (v2 == \at(v2,Pre) - t) ;
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x1 == 100 + t * v1) ;
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x2 == 75 + t * \at(v2,Pre)) ;
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x3 == -50 + t * v3) ;
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t >= 0) ;
      loop invariant (!(\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5)) ==> ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == \at(v3,Pre))&&(v2 == \at(v2,Pre))&&(v1 == \at(v1,Pre)));
      loop invariant v3 == \at(v3,Pre);
      loop invariant v1 == \at(v1,Pre);
      loop assigns x1, x3, x2, v2, t;
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

}
