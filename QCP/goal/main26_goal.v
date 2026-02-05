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

(*----- Function main26 -----*)

Definition main26_safety_wit_1 := 
forall (y_pre: Z) (x_pre: Z) ,
  ((( &( "z" ) )) # Int  |->_)
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition main26_safety_wit_2 := 
forall (y_pre: Z) (x_pre: Z) ,
  ((( &( "w" ) )) # Int  |->_)
  **  ((( &( "z" ) )) # Int  |-> 1)
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition main26_safety_wit_3 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> 1)
  **  ((( &( "z" ) )) # Int  |-> 1)
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| ((1 * x_pre ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (1 * x_pre )) |]
.

Definition main26_safety_wit_4 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre < y_pre) |] 
  &&  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "z" ) )) # Int  |-> 1)
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| ((1 * x_pre ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (1 * x_pre )) |]
.

Definition main26_safety_wit_5 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre < y_pre) |] 
  &&  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "z" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| ((x_pre + 1 ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (x_pre + 1 )) |]
.

Definition main26_safety_wit_6 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre < y_pre) |] 
  &&  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "z" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition main26_safety_wit_7 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre >= y_pre) |] 
  &&  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "z" ) )) # Int  |-> 1)
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| ((x_pre + 1 ) <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= (x_pre + 1 )) |]
.

Definition main26_safety_wit_8 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre >= y_pre) |] 
  &&  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "z" ) )) # Int  |-> 1)
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition main26_safety_wit_9 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre > y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> 1)
  **  ((( &( "z" ) )) # Int  |-> 1)
  **  ((( &( "y" ) )) # Int  |-> y_pre)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition main26_entail_wit_1 := 
  TT && emp 
|--
  TT && emp 
.

Definition main26_entail_wit_2 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre >= y_pre) |] 
  &&  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "x" ) )) # Int  |-> (x_pre + 1 ))
|--
  ((( &( "w" ) )) # Int  |-> 1)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
.

Definition main26_entail_wit_3 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre < y_pre) |] 
  &&  [| (x_pre <= y_pre) |]
  &&  ((( &( "w" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "z" ) )) # Int  |-> (1 * x_pre ))
  **  ((( &( "x" ) )) # Int  |-> (x_pre + 1 ))
|--
  ((( &( "w" ) )) # Int  |-> 1)
  **  ((( &( "z" ) )) # Int  |-> 1)
  **  ((( &( "x" ) )) # Int  |-> x_pre)
.

Definition main26_return_wit_1 := 
forall (y_pre: Z) (x_pre: Z) ,
  [| (x_pre > y_pre) |]
  &&  emp
|--
  (Results 0 )
.

Module Type VC_Correct.

Include common_Strategy_Correct.
Include int_array_Strategy_Correct.

Axiom proof_of_main26_safety_wit_1 : main26_safety_wit_1.
Axiom proof_of_main26_safety_wit_2 : main26_safety_wit_2.
Axiom proof_of_main26_safety_wit_3 : main26_safety_wit_3.
Axiom proof_of_main26_safety_wit_4 : main26_safety_wit_4.
Axiom proof_of_main26_safety_wit_5 : main26_safety_wit_5.
Axiom proof_of_main26_safety_wit_6 : main26_safety_wit_6.
Axiom proof_of_main26_safety_wit_7 : main26_safety_wit_7.
Axiom proof_of_main26_safety_wit_8 : main26_safety_wit_8.
Axiom proof_of_main26_safety_wit_9 : main26_safety_wit_9.
Axiom proof_of_main26_entail_wit_1 : main26_entail_wit_1.
Axiom proof_of_main26_entail_wit_2 : main26_entail_wit_2.
Axiom proof_of_main26_entail_wit_3 : main26_entail_wit_3.
Axiom proof_of_main26_return_wit_1 : main26_return_wit_1.

End VC_Correct.
