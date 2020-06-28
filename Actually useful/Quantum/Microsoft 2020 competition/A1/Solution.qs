namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using ((q1, q2) = (Qubit(), Qubit())) {
            X(q1); X(q2);
            unitary([q1, q2]);
            if (M(q1) == One) {
                set ans = 0;
            } else {
                set ans = 1;
            }
            Reset(q1);
            Reset(q2);
        }
        return ans;
    }

    operation Test() : Unit {
        Message("here");
    }
}
