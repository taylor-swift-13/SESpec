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

(*----- Function TripleAbsMaxFun -----*)

Definition TripleAbsMaxFun_safety_wit_1 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  ((( &( "absfx1" ) )) # Int  |->_)
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_2 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  ((( &( "absfy2" ) )) # Int  |->_)
  **  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition TripleAbsMaxFun_safety_wit_3 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  ((( &( "absfz3" ) )) # Int  |->_)
  **  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_4 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_5 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_6 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 0 pIp_abs_l 0) <> (INT_MIN)) |]
.

Definition TripleAbsMaxFun_safety_wit_7 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_8 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition TripleAbsMaxFun_safety_wit_9 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_10 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition TripleAbsMaxFun_safety_wit_11 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_12 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) <> (INT_MIN)) |]
.

Definition TripleAbsMaxFun_safety_wit_13 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition TripleAbsMaxFun_safety_wit_14 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) <> (INT_MIN)) |]
.

Definition TripleAbsMaxFun_safety_wit_15 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (1 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 1) |]
.

Definition TripleAbsMaxFun_safety_wit_16 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_17 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_18 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_19 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_20 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_21 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_22 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_23 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (0 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 0) |]
.

Definition TripleAbsMaxFun_safety_wit_24 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) <> (INT_MIN)) |]
.

Definition TripleAbsMaxFun_safety_wit_25 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_26 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) <> (INT_MIN)) |]
.

Definition TripleAbsMaxFun_safety_wit_27 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_28 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) <> (INT_MIN)) |]
.

Definition TripleAbsMaxFun_safety_wit_29 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_safety_wit_30 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) <> (INT_MIN)) |]
.

Definition TripleAbsMaxFun_safety_wit_31 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((( &( "absfz3" ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((( &( "absfy2" ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((( &( "absfx1" ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((( &( "pIp" ) )) # Ptr  |-> pIp_pre)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| (2 <= INT_MAX) |] 
  &&  [| ((INT_MIN) <= 2) |]
.

Definition TripleAbsMaxFun_return_wit_1_1 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_2 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_3 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_4 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_5 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_6 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_7 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_8 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_9 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_10 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_11 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_12 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) > (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 2 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_13 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_14 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_15 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_16 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) > (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 2 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_17 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 0 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_18 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_19 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_20 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 0 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_21 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 0 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_22 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_23 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (-(Znth 0 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 0 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_24 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (Znth 0 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) > (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 0 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_25 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 1 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_26 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 1 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_27 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_28 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_29 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_30 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (-(Znth 1 pIp_abs_l 0))) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (-(Znth 1 pIp_abs_l 0)))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_31 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((-(Znth 0 pIp_abs_l 0)) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 1 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_return_wit_1_32 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_abs_l: (@list Z)) ,
  [| ((-(Znth 2 pIp_abs_l 0)) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) <= (Znth 1 pIp_abs_l 0)) |] 
  &&  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> (Znth 1 pIp_abs_l 0))
|--
  TT && emp 
.

Definition TripleAbsMaxFun_partial_solve_wit_1 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (0 * sizeof(INT) ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 0 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_2 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (1 * sizeof(INT) ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 1 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_3 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_4 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (0 * sizeof(INT) ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 0 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_5 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (0 * sizeof(INT) ) )) # Int  |-> (Znth 0 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 0 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_6 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (1 * sizeof(INT) ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 1 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_7 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (1 * sizeof(INT) ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 1 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_8 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (1 * sizeof(INT) ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 1 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_9 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (1 * sizeof(INT) ) )) # Int  |-> (Znth 1 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 1 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_10 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_11 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_12 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_13 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_14 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_15 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_16 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) < 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Definition TripleAbsMaxFun_partial_solve_wit_17 := 
forall (pIp_pre: Z) (pIp_ret: Z) (pIp_ret_v: Z) (pIp_tmax: Z) (pIp_abs_l: (@list Z)) ,
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (store_int_array &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
|--
  [| ((Znth 2 pIp_abs_l 0) < 0) |] 
  &&  [| ((Znth 1 pIp_abs_l 0) >= 0) |] 
  &&  [| ((Znth 0 pIp_abs_l 0) >= 0) |]
  &&  (((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") + (2 * sizeof(INT) ) )) # Int  |-> (Znth 2 pIp_abs_l 0))
  **  (store_int_array_missing_i_rec &((pIp_pre)  # "__TripleAbsMax" ->ₛ "abs") 2 0 3 pIp_abs_l )
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "tmax")) # Int  |-> pIp_tmax)
  **  ((&((pIp_pre)  # "__TripleAbsMax" ->ₛ "ret")) # Ptr  |-> pIp_ret)
  **  ((pIp_ret) # Int  |-> pIp_ret_v)
.

Module Type VC_Correct.

Include common_Strategy_Correct.
Include int_array_Strategy_Correct.

Axiom proof_of_TripleAbsMaxFun_safety_wit_1 : TripleAbsMaxFun_safety_wit_1.
Axiom proof_of_TripleAbsMaxFun_safety_wit_2 : TripleAbsMaxFun_safety_wit_2.
Axiom proof_of_TripleAbsMaxFun_safety_wit_3 : TripleAbsMaxFun_safety_wit_3.
Axiom proof_of_TripleAbsMaxFun_safety_wit_4 : TripleAbsMaxFun_safety_wit_4.
Axiom proof_of_TripleAbsMaxFun_safety_wit_5 : TripleAbsMaxFun_safety_wit_5.
Axiom proof_of_TripleAbsMaxFun_safety_wit_6 : TripleAbsMaxFun_safety_wit_6.
Axiom proof_of_TripleAbsMaxFun_safety_wit_7 : TripleAbsMaxFun_safety_wit_7.
Axiom proof_of_TripleAbsMaxFun_safety_wit_8 : TripleAbsMaxFun_safety_wit_8.
Axiom proof_of_TripleAbsMaxFun_safety_wit_9 : TripleAbsMaxFun_safety_wit_9.
Axiom proof_of_TripleAbsMaxFun_safety_wit_10 : TripleAbsMaxFun_safety_wit_10.
Axiom proof_of_TripleAbsMaxFun_safety_wit_11 : TripleAbsMaxFun_safety_wit_11.
Axiom proof_of_TripleAbsMaxFun_safety_wit_12 : TripleAbsMaxFun_safety_wit_12.
Axiom proof_of_TripleAbsMaxFun_safety_wit_13 : TripleAbsMaxFun_safety_wit_13.
Axiom proof_of_TripleAbsMaxFun_safety_wit_14 : TripleAbsMaxFun_safety_wit_14.
Axiom proof_of_TripleAbsMaxFun_safety_wit_15 : TripleAbsMaxFun_safety_wit_15.
Axiom proof_of_TripleAbsMaxFun_safety_wit_16 : TripleAbsMaxFun_safety_wit_16.
Axiom proof_of_TripleAbsMaxFun_safety_wit_17 : TripleAbsMaxFun_safety_wit_17.
Axiom proof_of_TripleAbsMaxFun_safety_wit_18 : TripleAbsMaxFun_safety_wit_18.
Axiom proof_of_TripleAbsMaxFun_safety_wit_19 : TripleAbsMaxFun_safety_wit_19.
Axiom proof_of_TripleAbsMaxFun_safety_wit_20 : TripleAbsMaxFun_safety_wit_20.
Axiom proof_of_TripleAbsMaxFun_safety_wit_21 : TripleAbsMaxFun_safety_wit_21.
Axiom proof_of_TripleAbsMaxFun_safety_wit_22 : TripleAbsMaxFun_safety_wit_22.
Axiom proof_of_TripleAbsMaxFun_safety_wit_23 : TripleAbsMaxFun_safety_wit_23.
Axiom proof_of_TripleAbsMaxFun_safety_wit_24 : TripleAbsMaxFun_safety_wit_24.
Axiom proof_of_TripleAbsMaxFun_safety_wit_25 : TripleAbsMaxFun_safety_wit_25.
Axiom proof_of_TripleAbsMaxFun_safety_wit_26 : TripleAbsMaxFun_safety_wit_26.
Axiom proof_of_TripleAbsMaxFun_safety_wit_27 : TripleAbsMaxFun_safety_wit_27.
Axiom proof_of_TripleAbsMaxFun_safety_wit_28 : TripleAbsMaxFun_safety_wit_28.
Axiom proof_of_TripleAbsMaxFun_safety_wit_29 : TripleAbsMaxFun_safety_wit_29.
Axiom proof_of_TripleAbsMaxFun_safety_wit_30 : TripleAbsMaxFun_safety_wit_30.
Axiom proof_of_TripleAbsMaxFun_safety_wit_31 : TripleAbsMaxFun_safety_wit_31.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_1 : TripleAbsMaxFun_return_wit_1_1.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_2 : TripleAbsMaxFun_return_wit_1_2.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_3 : TripleAbsMaxFun_return_wit_1_3.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_4 : TripleAbsMaxFun_return_wit_1_4.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_5 : TripleAbsMaxFun_return_wit_1_5.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_6 : TripleAbsMaxFun_return_wit_1_6.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_7 : TripleAbsMaxFun_return_wit_1_7.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_8 : TripleAbsMaxFun_return_wit_1_8.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_9 : TripleAbsMaxFun_return_wit_1_9.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_10 : TripleAbsMaxFun_return_wit_1_10.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_11 : TripleAbsMaxFun_return_wit_1_11.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_12 : TripleAbsMaxFun_return_wit_1_12.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_13 : TripleAbsMaxFun_return_wit_1_13.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_14 : TripleAbsMaxFun_return_wit_1_14.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_15 : TripleAbsMaxFun_return_wit_1_15.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_16 : TripleAbsMaxFun_return_wit_1_16.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_17 : TripleAbsMaxFun_return_wit_1_17.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_18 : TripleAbsMaxFun_return_wit_1_18.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_19 : TripleAbsMaxFun_return_wit_1_19.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_20 : TripleAbsMaxFun_return_wit_1_20.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_21 : TripleAbsMaxFun_return_wit_1_21.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_22 : TripleAbsMaxFun_return_wit_1_22.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_23 : TripleAbsMaxFun_return_wit_1_23.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_24 : TripleAbsMaxFun_return_wit_1_24.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_25 : TripleAbsMaxFun_return_wit_1_25.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_26 : TripleAbsMaxFun_return_wit_1_26.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_27 : TripleAbsMaxFun_return_wit_1_27.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_28 : TripleAbsMaxFun_return_wit_1_28.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_29 : TripleAbsMaxFun_return_wit_1_29.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_30 : TripleAbsMaxFun_return_wit_1_30.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_31 : TripleAbsMaxFun_return_wit_1_31.
Axiom proof_of_TripleAbsMaxFun_return_wit_1_32 : TripleAbsMaxFun_return_wit_1_32.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_1 : TripleAbsMaxFun_partial_solve_wit_1.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_2 : TripleAbsMaxFun_partial_solve_wit_2.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_3 : TripleAbsMaxFun_partial_solve_wit_3.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_4 : TripleAbsMaxFun_partial_solve_wit_4.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_5 : TripleAbsMaxFun_partial_solve_wit_5.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_6 : TripleAbsMaxFun_partial_solve_wit_6.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_7 : TripleAbsMaxFun_partial_solve_wit_7.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_8 : TripleAbsMaxFun_partial_solve_wit_8.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_9 : TripleAbsMaxFun_partial_solve_wit_9.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_10 : TripleAbsMaxFun_partial_solve_wit_10.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_11 : TripleAbsMaxFun_partial_solve_wit_11.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_12 : TripleAbsMaxFun_partial_solve_wit_12.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_13 : TripleAbsMaxFun_partial_solve_wit_13.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_14 : TripleAbsMaxFun_partial_solve_wit_14.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_15 : TripleAbsMaxFun_partial_solve_wit_15.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_16 : TripleAbsMaxFun_partial_solve_wit_16.
Axiom proof_of_TripleAbsMaxFun_partial_solve_wit_17 : TripleAbsMaxFun_partial_solve_wit_17.

End VC_Correct.
