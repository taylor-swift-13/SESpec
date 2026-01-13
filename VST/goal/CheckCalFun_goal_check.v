From  Require Import CheckCalFun_goal CheckCalFun_proof_auto CheckCalFun_proof_manual.

Module VC_Correctness : VC_Correct.
  Include common_strategy_proof.
  Include int_array_strategy_proof.
  Include CheckCalFun_proof_auto.
  Include CheckCalFun_proof_manual.
End VC_Correctness.
