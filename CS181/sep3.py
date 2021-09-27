# write a function charFreq(s) that  returns a dict that maps character to their frequencies in string s

# write function removeOdds(L) that removes all odd values from a list of ints. return nothing, update input list to remove all odd number

def charFreq(s: str):
    d = {}
    for char in s:
        if char in d.keys():
            d[char] += 1
        else:
            d[char] = 1
    return d


charFreq('hello world')


def removeOdds(L):
    L = [x for x in L if x % 2 == 0]
    return L


L = [1, 3, 5, 7]
L2 = removeOdds(L)
print(L)
print(L2)
