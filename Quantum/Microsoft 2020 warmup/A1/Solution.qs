namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0; 
        using (q = Qubit()) {
            unitary(q);
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
        if (Solve(I) == 0 and Solve(X) == 1) {
            Message("Works");
        } else {
            Message("Doesn't work");
        }
    }
    
}
