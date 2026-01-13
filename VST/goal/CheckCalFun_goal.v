Require Import Coq.ZArith.ZArith.
Require Import Coq.Bool.Bool.
Require Import Coq.Strings.String.
Require Import Coq.Lists.List.
Require Import Coq.Classes.RelationClasses.
Require Import Coq.Classes.Morphisms.
Require Import Coq.micromega.Psatz.
Require Import Coq.Sorting.Permutation.
From AUXLib Require Import int_auto Axioms Feq Idents List_lemma VMap.
Require Import SetsClass.SetsClass. Import SetsNotation.
From SimpleC.SL Require Import Mem SeparationLogic.
Require Import Logic.LogicGenerator.demo932.Interface.
Local Open Scope Z_scope.
Local Open Scope sets.
Local Open Scope string.
Local Open Scope list.
Import naive_C_Rules.
Require Import int_array_lib.
Local Open Scope sac.
Require Import common_strategy_goal.
Require Import common_strategy_proof.
Require Import int_array_strategy_goal.
Require Import int_array_strategy_proof.

(*----- Function CheckCalFun -----*)

Definition CheckCalFun_safety_wit_1 := 
forall (pIp_pre: Z) (pIp_chksum: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  ((( &( "i" ) )) # Int  |->_)
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition CheckCalFun_safety_wit_2 := 
forall (pIp_pre: Z) (pIp_chksum: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  ((( &( "chksum" ) )) # Int  |->_)
  **  ((( &( "i" ) )) # Int  |-> 0)
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition CheckCalFun_safety_wit_3 := 
forall (pIp_pre: Z) (pIp_chksum: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  [| (0 < pIp_len) |]
  &&  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((( &( "chksum" ) )) # Int  |-> 0)
  **  ((( &( "i" ) )) # Int  |-> 0)
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
|--
  [| ((0 + (Znth 0 pIp_pkv_l 0) ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (0 + (Znth 0 pIp_pkv_l 0) )) |]
.

Definition CheckCalFun_safety_wit_4 := 
forall (pIp_pre: Z) (pIp_chksum: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  [| (0 < pIp_len) |]
  &&  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((( &( "chksum" ) )) # Int  |-> (0 + (Znth 0 pIp_pkv_l 0) ))
  **  ((( &( "i" ) )) # Int  |-> 0)
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
|--
  [| ((0 + 1 ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (0 + 1 )) |]
.

Definition CheckCalFun_entail_wit_1 := 
forall (pIp_pre: Z) (pIp_chksum: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
|--
  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
.

Definition CheckCalFun_entail_wit_2 := 
forall (pIp_pre: Z) (pIp_chksum: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  [| (0 < pIp_len) |]
  &&  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((( &( "chksum" ) )) # Int  |-> (0 + (Znth 0 pIp_pkv_l 0) ))
  **  ((( &( "i" ) )) # Int  |-> (0 + 1 ))
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
|--
  ((( &( "chksum" ) )) # Int  |-> 0)
  **  ((( &( "i" ) )) # Int  |-> 0)
  **  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
.

Definition CheckCalFun_return_wit_1 := 
forall (pIp_pre: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  [| (0 >= pIp_len) |]
  &&  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> 0)
|--
  TT && emp 
.

Definition CheckCalFun_partial_solve_wit_1 := 
forall (pIp_pre: Z) (pIp_chksum: Z) (pIp_len: Z) (pIp_pkv_l: (@list Z)) ,
  [| (0 < pIp_len) |]
  &&  (store_int_array &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
|--
  [| (0 < pIp_len) |]
  &&  (((&((pIp_pre)  # "__CheckCal" ->ₛ "pkv") + (0 * sizeof(INT) ) )) # Int  |-> (Znth 0 pIp_pkv_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__CheckCal" ->ₛ "pkv") 0 0 10 pIp_pkv_l )
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "len")) # Int  |-> pIp_len)
  **  ((&((pIp_pre)  # "__CheckCal" ->ₛ "chksum")) # Int  |-> pIp_chksum)
.

Module Type VC_Correct.

Include common_Strategy_Correct.
Include int_array_Strategy_Correct.

Axiom proof_of_CheckCalFun_safety_wit_1 : CheckCalFun_safety_wit_1.
Axiom proof_of_CheckCalFun_safety_wit_2 : CheckCalFun_safety_wit_2.
Axiom proof_of_CheckCalFun_safety_wit_3 : CheckCalFun_safety_wit_3.
Axiom proof_of_CheckCalFun_safety_wit_4 : CheckCalFun_safety_wit_4.
Axiom proof_of_CheckCalFun_entail_wit_1 : CheckCalFun_entail_wit_1.
Axiom proof_of_CheckCalFun_entail_wit_2 : CheckCalFun_entail_wit_2.
Axiom proof_of_CheckCalFun_return_wit_1 : CheckCalFun_return_wit_1.
Axiom proof_of_CheckCalFun_partial_solve_wit_1 : CheckCalFun_partial_solve_wit_1.

End VC_Correct.
