namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q = Qubit()) {
            H(q);
            unitary(q); unitary(q);
            H(q);
            if (M(q) == Zero) {
                set ans = 0;
            } else {
                set ans = 1;
            }
            Reset(q);
        }
        return ans;
    }

    operation Test() : Unit {
        if (Solve(Z) == 0 and Solve(S) == 1) {
            Message("Works");
        } else {
            Message("Doesn't work");
        }
    }
}