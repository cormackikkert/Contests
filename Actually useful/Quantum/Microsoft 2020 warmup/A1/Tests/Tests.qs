namespace Tests
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation AllocateQubitTest () : ()
    {
        body
        {
            using (qs = Qubit[1])
            {
                Assert([PauliZ], [qs[0]], Zero, "Newly allocated qubit must be in |0> state");
            }
            
            Message("Test passed");
        }
    }

    Test("Test")
    operation A1 () : Unit {
        Fact(Solve(I) == 0, "Test1");
        Fact(Solve(X) == 1, "Test2");
    }
}