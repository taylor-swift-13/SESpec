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

(*----- Function foo176 -----*)

Definition foo176_safety_wit_1 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |->_)
  **  ((( &( "n" ) )) # Int  |->_)
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition foo176_safety_wit_2 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |->_)
  **  ((( &( "n" ) )) # Int  |-> 0)
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition foo176_safety_wit_3 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> 0)
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| ((2 * k_pre ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (2 * k_pre )) |]
.

Definition foo176_safety_wit_4 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> 0)
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition foo176_safety_wit_5 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (0 >= (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> 0)
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| False |]
.

Definition foo176_safety_wit_6 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> 0)
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| ((0 + 1 ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (0 + 1 )) |]
.

Definition foo176_safety_wit_7 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> 0)
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition foo176_safety_wit_8 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> (0 + 1 ))
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition foo176_safety_wit_9 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (1 <> 1) |] 
  &&  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> (0 + 1 ))
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| False |]
.

Definition foo176_safety_wit_10 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (1 = 1) |] 
  &&  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> (0 + 1 ))
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition foo176_safety_wit_11 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (1 = 1) |] 
  &&  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 0)
  **  ((( &( "n" ) )) # Int  |-> (0 + 1 ))
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| ((i_pre + 1 ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (i_pre + 1 )) |]
.

Definition foo176_safety_wit_12 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (1 = 1) |] 
  &&  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 0)
  **  ((( &( "n" ) )) # Int  |-> (0 + 1 ))
  **  ((( &( "k" ) )) # Int  |-> k_pre)
  **  ((( &( "j" ) )) # Int  |-> j_pre)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition foo176_entail_wit_1 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  emp
|--
  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  emp
.

Definition foo176_entail_wit_2 := 
forall (k_pre: Z) (j_pre: Z) (i_pre: Z) ,
  [| (1 = 1) |] 
  &&  [| (0 < (2 * k_pre )) |] 
  &&  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 0)
  **  ((( &( "n" ) )) # Int  |-> (0 + 1 ))
  **  ((( &( "i" ) )) # Int  |-> (i_pre + 1 ))
|--
  [| (k_pre > 0) |] 
  &&  [| (k_pre < 20000001) |] 
  &&  [| (i_pre = j_pre) |]
  &&  ((( &( "b" ) )) # Int  |-> 1)
  **  ((( &( "n" ) )) # Int  |-> 0)
  **  ((( &( "i" ) )) # Int  |-> i_pre)
.

Module Type VC_Correct.

Include common_Strategy_Correct.
Include int_array_Strategy_Correct.

Axiom proof_of_foo176_safety_wit_1 : foo176_safety_wit_1.
Axiom proof_of_foo176_safety_wit_2 : foo176_safety_wit_2.
Axiom proof_of_foo176_safety_wit_3 : foo176_safety_wit_3.
Axiom proof_of_foo176_safety_wit_4 : foo176_safety_wit_4.
Axiom proof_of_foo176_safety_wit_5 : foo176_safety_wit_5.
Axiom proof_of_foo176_safety_wit_6 : foo176_safety_wit_6.
Axiom proof_of_foo176_safety_wit_7 : foo176_safety_wit_7.
Axiom proof_of_foo176_safety_wit_8 : foo176_safety_wit_8.
Axiom proof_of_foo176_safety_wit_9 : foo176_safety_wit_9.
Axiom proof_of_foo176_safety_wit_10 : foo176_safety_wit_10.
Axiom proof_of_foo176_safety_wit_11 : foo176_safety_wit_11.
Axiom proof_of_foo176_safety_wit_12 : foo176_safety_wit_12.
Axiom proof_of_foo176_entail_wit_1 : foo176_entail_wit_1.
Axiom proof_of_foo176_entail_wit_2 : foo176_entail_wit_2.

End VC_Correct.
