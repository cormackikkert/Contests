namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using ((q1, q2) = (Qubit(), Qubit())) {
            unitary([q1, q2]);
            if (M(q2) == Zero) {
                set ans = 1;
            } else {
                set ans = 0;
            }
            Reset(q1);
            Reset(q2);
        }
        return ans;
    }

    operation Test() : Unit {
        // idk syntax, hopefully it works
        
    }
}