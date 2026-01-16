From  Require Import foo176_goal foo176_proof_auto foo176_proof_manual.

Module VC_Correctness : VC_Correct.
  Include common_strategy_proof.
  Include int_array_strategy_proof.
  Include foo176_proof_auto.
  Include foo176_proof_manual.
End VC_Correctness.
