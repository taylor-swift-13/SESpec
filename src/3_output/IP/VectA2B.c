
void VectA2B(float64 *ptrB, const float64 *ptrA, siint32 num)
{
	siint32 si;

	/*@
		loop invariant 0 <= si <= num;
		loop invariant \forall integer k; 0 <= k < si ==> ptrB[k] == ptrA[k];
	*/
	for(si=0; si<num; si++)
	{
		ptrB[si] = ptrA[si];
	}

	return;
}
