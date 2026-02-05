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
From  Require Import main26_goal.
Require Import Logic.LogicGenerator.demo932.Interface.
Local Open Scope Z_scope.
Local Open Scope sets.
Local Open Scope string.
Local Open Scope list.
Import naive_C_Rules.
Require Import int_array_lib.
Local Open Scope sac.

Lemma proof_of_main26_safety_wit_3 : main26_safety_wit_3.
Proof. Admitted. 

Lemma proof_of_main26_safety_wit_4 : main26_safety_wit_4.
Proof. Admitted. 

Lemma proof_of_main26_safety_wit_5 : main26_safety_wit_5.
Proof. Admitted. 

Lemma proof_of_main26_safety_wit_7 : main26_safety_wit_7.
Proof. Admitted. 

Lemma proof_of_main26_entail_wit_2 : main26_entail_wit_2.
Proof. Admitted. 

Lemma proof_of_main26_entail_wit_3 : main26_entail_wit_3.
Proof. Admitted. 

Lemma proof_of_main26_return_wit_1 : main26_return_wit_1.
Proof. Admitted. 

