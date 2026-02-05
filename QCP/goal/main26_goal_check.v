From  Require Import main26_goal main26_proof_auto main26_proof_manual.

Module VC_Correctness : VC_Correct.
  Include common_strategy_proof.
  Include int_array_strategy_proof.
  Include main26_proof_auto.
  Include main26_proof_manual.
End VC_Correctness.
