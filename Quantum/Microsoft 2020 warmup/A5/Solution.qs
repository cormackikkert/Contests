namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            Controlled unitary([q1], q2);
            H(q1);
            if (M(q1) == Zero) {
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
        // idk syntax, hopefully it works
        if (Solve(Z) == 0) {
            Message("works");
        }
    }
}