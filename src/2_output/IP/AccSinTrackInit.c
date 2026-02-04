
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void AccSinTrackInit(SMnvrData *past)

/*@
With past_tmA past_dChimax past_Chim past_Chim0 past_amax past_acc_Ref past_dChi_Ref past_Chi_Ref past_tm1p past_tm2p past_tm3p past_t_sinacc past_t_conacc past_t_m1a past_t_m1b past_t_m3a past_t_m3b past_F_Init_Trajectory
Require past->tmA == past_tmA && past->dChimax == past_dChimax && past->Chim == past_Chim && past->Chim0 == past_Chim0 && past->amax == past_amax && past->acc_Ref == past_acc_Ref && past->dChi_Ref == past_dChi_Ref && past->Chi_Ref == past_Chi_Ref && past->tm1p == past_tm1p && past->tm2p == past_tm2p && past->tm3p == past_tm3p && past->t_sinacc == past_t_sinacc && past->t_conacc == past_t_conacc && past->t_m1a == past_t_m1a && past->t_m1b == past_t_m1b && past->t_m3a == past_t_m3a && past->t_m3b == past_t_m3b && past->F_Init_Trajectory == past_F_Init_Trajectory
Ensure emp
*/{
    float64 tacc;
    float64 tv;

    
    tacc = 2.0 * Fabsx(past->dChimax / past->amax);
    tv = Fabsx((past->Chim - past->Chim0) / past->dChimax) - tacc;

    
    if(tv <= 0.0)
    {
        tv = 0.0;

        tacc = Sqrtx(2.0 * Fabsx((past->Chim - past->Chim0) / past->amax));
    }

    
    past->tm1p = tacc;

    
    past->tm2p = tacc + tv;

    
    past->tm3p = 2.0 * tacc + tv;

    return;
}