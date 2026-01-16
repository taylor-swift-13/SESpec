
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void VectA2B(float64 *ptrB, const float64 *ptrA, siint32 num)
/*@
With ptrB_l ptrA_l
Require store_int_array(ptrB, ptrA, ptrB_l) && ptrA > 0 && ptrA < 100 && store_int_array(ptrA, num, ptrA_l) && num > 0 && num < 100
Ensure emp
*/
{

	siint32 si;


 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  ptrB_l ptrA_l,    
    store_int_array(ptrB, ptrA, ptrB_l) && ptrA > 0 && ptrA < 100 && store_int_array(ptrA, num, ptrA_l) && num > 0 && num < 100 &&
    (0 <= si && si <= num) &&
(forall (k:Z), 0 <= k && k < si => ptrB_l[k] == ptrA_l[k])
    */
    
	for(si=0; si<num; si++)
	{
		ptrB[si] = ptrA[si];
	}

	return;
}
void AttitudeSelectXY(void)

/*@

Require emp

Ensure emp
*/{
    

	
	
	VectA2B(&mAttitude.Cbi[0][0], &mStsGyroData.Cbi[0][0],3*3);
	VectA2B(&mAttitude.Cbo[0][0], &mStsGyroData.Cbo[0][0],3*3);
	VectA2B(&mAttitude.Cbr[0][0], &mStsGyroData.Cbr[0][0],3*3);

	if(mAttitude.flgXYIn == SI_KALMAN)
	{
		if (mGyro.bValid3Axis == TRUE32)
		{
			mAttitude.angle[0] = mStsGyroData.angle[0];
			mAttitude.angle[1] = mStsGyroData.angle[1];
#if HAVE_ES
			if (mKalman.flgAttSel != 0)
			{
				VectA2B(&mAttitude.Cbi[0][0], &mEsDssGyroAtt.Cbi_es[0][0], 3*3);
				VectA2B(&mAttitude.Cbr[0][0], &mEsDssGyroAtt.Cbr_es[0][0], 3*3);
				VectA2B(&mAttitude.Cbo[0][0], &mEsDssGyroAtt.Cbo_es[0][0], 3*3);
				mAttitude.angle[0] = mEsDssGyroAtt.angle[0];
				mAttitude.angle[1] = mEsDssGyroAtt.angle[1];
			}
#endif
		}
		else
		{
			mAttitude.angle[0] = mAttitude.angleB[0];
			mAttitude.angle[1] = mAttitude.angleB[1];
		}
	}
	else if(mAttitude.flgXYIn == SI_STS)  
    {
		
		VectA2B(&mAttitude.Cbi[0][0], &mStsSelectData.Cbi[0][0],3*3);
		VectA2B(&mAttitude.Cbr[0][0], &mStsSelectData.Cbr[0][0],3*3);
		VectA2B(&mAttitude.Cbo[0][0], &mStsSelectData.Cbo[0][0],3*3);

        
        if(mStsSelectData.bUsable == TRUE32)
        {
	        mAttitude.angle[0] = mStsSelectData.angle[0];
			mAttitude.angle[1] = mStsSelectData.angle[1];
        }
        else
		{
			mAttitude.angle[0] = mAttitude.angleB[0];
			mAttitude.angle[1] = mAttitude.angleB[1];
		}
    }
    else if(mAttitude.flgXYIn == SI_DSS)  
	{
		if(mDss.bSpxy == FALSE32)
		{
			
			mAttitude.angle[0] = mAttitude.angleB[0];
			mAttitude.angle[1] = mAttitude.angleB[1];
		}
		else
		{
			if(mModeManage.flgMode == SAM)
			{
				
				mAttitude.angle[0] = mDss.angle[0];
				mAttitude.angle[1] = mDss.angle[1];
			}
			else
			{
                mAttitude.angle[0] = mDss.angleSSF[0];
                mAttitude.angle[1] = mDss.angleSSF[1];
			}
		}
	}
	else if(mAttitude.flgXYIn == SI_RIGA) 
	{
		mAttitude.angle[0] = mGyro.pG[0];
		mAttitude.angle[1] = mGyro.pG[1];
	}
#if HAVE_ES
	else if (mAttitude.flgXYIn == SI_ES)
	{
		
		if (mSts.numUsable == 0)
		{
			
			VectA2B(&mAttitude.Cbi[0][0], &mEsDssGyroAtt.Cbi_es[0][0], 9);
			VectA2B(&mAttitude.Cbr[0][0], &mEsDssGyroAtt.Cbr_es[0][0], 9);
			VectA2B(&mAttitude.Cbo[0][0], &mEsDssGyroAtt.Cbo_es[0][0], 9);
		}

		if (mEsGr.bEPValid == TRUE32)
		{
			mAttitude.angle[0] = mEsGr.phi;
			mAttitude.angle[1] = mEsGr.theta;
		}
		else
		{
			mAttitude.angle[0] = mAttitude.angleB[0];
			mAttitude.angle[1] = mAttitude.angleB[1];
		}
	}
#endif
	else if(mAttitude.flgXYIn == SI_QUATERNION)
	{
		mAttitude.angle[0] = 2.0 * mAttManeuver.qc[0];
		mAttitude.angle[1] = 2.0 * mAttManeuver.qc[1];
	}
	else if(mAttitude.flgXYIn == SI_NO)  
	{
		mAttitude.angle[0] = mAttitude.angleB[0];
		mAttitude.angle[1] = mAttitude.angleB[1];
	}
	else
	{
		NULL_STATEMENT();
	}

	C2Q(&mAttitude.qbi[0], &mAttitude.Cbi[0][0]);
	C2Q(&mAttitude.qbr[0], &mAttitude.Cbr[0][0]);

    return;
}