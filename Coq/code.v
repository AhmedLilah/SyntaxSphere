(* Define a function that computes the factorial of a natural number *)
Fixpoint factorial (n : nat) : nat :=
  match n with
  | 0 => 1
  | S n' => n * factorial n'
  end.

(* State and prove that the factorial of 0 is 1 *)
Theorem factorial_0 : factorial 0 = 1.
Proof.
  simpl. (* Simplify the goal using the definition of factorial *)
  reflexivity. (* The goal is a reflexive equality, so we can use this tactic *)
Qed. (* We have proved the goal, so we end the proof *)
