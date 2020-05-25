#!/usr/bin/env python

# 1. We will start by assigning activities to equivalence classes.
# This equivalence relation will be the _transitive closure_ of (A,B) where activities A and B overlap.
# 2. We well try to assign the two parents C and J to activities within each class, and see if it becomes impossible.


N = int(input()) # Number of cases

for caseind in range(N):
    
    # Make a list of time-disjoint activity lists
    # E.g. partition according to an equivalence relation which is the transitive closure of (A,B) where A and B overlap.
  
    numacts = int(input())
    acts = [list(map(int,input().split())) for _ in range(numacts)]
    unassigned_acts = list(range(numacts))

    act_classes = []
    
    def overlapping_uacts(actInd):
        global unassigned_acts
        actStart, actEnd = acts[actInd]
        def actIndOverlaps(actInd): 
            act2Start, act2End = acts[actInd]
            overlapTime = min(actEnd,act2End) - max(actStart,act2Start)
            return overlapTime > 0
        return [actInd for actInd in unassigned_acts if actIndOverlaps(actInd)]

    def overlapping_allacts(actInd):
        global unassigned_acts
        actStart, actEnd = acts[actInd]
        def actIndOverlaps(actInd): 
            act2Start, act2End = acts[actInd]
            overlapTime = min(actEnd,act2End) - max(actStart,act2Start)
            return overlapTime > 0
        return [actInd for actInd in range(numacts) if actIndOverlaps(actInd)]


    act_assignment = []

    fail = False

    # Iterate through equivalence classes within one schedule
    while True:
        next_act = max((max(act_classes + [[-1]]))) + 1
        # Break If: All acts have been assigned to an equivalence class
        if next_act >= len(acts):
            break
        assert(next_act == min(unassigned_acts))
        
        parity = 0

        # Unassigned acts 
        act_class = [next_act]
        check_next = [next_act]
        unassigned_acts.remove(next_act)
        act_assignment.append((next_act,parity))
        parity = 1 - parity

        # Depth-first search of equivalence class
        while len(check_next) > 0:
            # Fetch next act to check, and the overlaps
            act = check_next.pop()
            #print("Check act num: ", act)
            overlap_acts = overlapping_uacts(act)
            #print("Overlapping unassigned: ", overlap_acts)
            ALL_overlap_acts = overlapping_allacts(act)
            #print("ALL overlapping: ", ALL_overlap_acts)
            adjacentparitiesOK = [assign[1]==parity for assign in act_assignment if (assign[0] != act) and (assign[0] in ALL_overlap_acts)]
            #print("Adjacent parities consistent: ", adjacentparitiesOK)
            #print(adjacentparitiesOK)
            #print(act_assignment)
            #print(parity)
            if not all(adjacentparitiesOK):
                # This schedule cannot be reconciled.
                fail = True
                break

            # Add overlapping acts to the equiv. class
            act_class.extend(overlap_acts)
            check_next.extend(overlap_acts)
            [unassigned_acts.remove(a) for a in overlap_acts]
            [act_assignment.append((a,parity)) for a in overlap_acts]
            #print("Act assignment: ", act_assignment)
            parity = 1 - parity
        
        if fail:
            break

        act_classes.append(act_class)
        #print("Equivalence class exhausted: ", act_class)

    if fail:
        print("Case #%d: IMPOSSIBLE" % (caseind+1))
    else:
        parityList = [assign[1] for assign in sorted(act_assignment,key=(lambda a: a[0]))]
        stringlist = ''.join("C" if p==0 else "J" for p in parityList)
        print("Case #%d: %s" % (caseind+1,stringlist))