def max_pairs(deck):
    res = 0
    history = set()
    prev = None
    for card in deck:
        print(history)
        if card not in history:
            history.add(card)
        else:
            print("got pair", card)
            if card != prev:
              history = set([prev])
            res += 1
        prev = card
    return res
