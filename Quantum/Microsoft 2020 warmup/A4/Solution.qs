namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        set ans = 0;
        using ((q1, q2) = Qubit()) {
            X(q);
            unitary(q);
            H(q);
            
        }
    }

    operation Test() : Unit {
        // idk syntax, hopefully it works
    }
}