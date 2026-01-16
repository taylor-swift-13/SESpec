Require Import TripleAbsMaxFun_goal TripleAbsMaxFun_proof_auto TripleAbsMaxFun_proof_manual.

Module VC_Correctness : VC_Correct.
  Include common_strategy_proof.
  Include int_array_strategy_proof.
  Include TripleAbsMaxFun_proof_auto.
  Include TripleAbsMaxFun_proof_manual.
End VC_Correctness.
