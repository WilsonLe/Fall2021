def mean(L):
    """Calculates the arithmetic means of an input list

    Args:
        L (List): input list that is used to calculate arithmetic mean of

    Returns:
        double: the arithmetic mean of the input list
    """
    sum = 0
    for value in L:
        sum += value
    average = sum / len(L)
    return average


print("Running tests")
assert mean([1, 2, 3, 4, 5]) == 3, "Test 1 failed"
print("Test 1 passed")
assert mean([-3, -2, -1, 0, 1, 2, 3]) == 0, "Test 2 failed"
print("Test 2 passed")
assert mean([3, 5, 1, 6, 5, 7, 9]) == (36 / 7), "Test 3 failed"
print("Test 3 passed")
assert mean([7, 6, 4, 3, 10, 27, -42, 24]) == (39 / 8), "Test 4 failed"
print("Test 4 passed")
assert mean([8, 7, 9, 10, 5, 1, -20, -39]) == (-19 / 8), "Test 5 failed"
print("Test 5 passed")


def maximum(L):
    """find the largest value in an input list

    Args:
        L (List): user input list of double/integers

    Returns:
        double/integers: the largest value in the input list
    """
    max_val = L[0]
    for val in L:
        if val > max_val:
            max_val = val
    return max_val


print("Running tests")
assert maximum([1, 2, 3, 4, 5]) == 5, "Test 1 failed"
print("Test 1 passed")
assert maximum([10, 30, 20, 25]) == 30, "Test 2 failed"
print("Test 2 passed")
assert maximum([20, 40, -10, 30]) == 40, "Test 3 failed"
print("Test 3 passed")
assert maximum([40, 70, 80, 90, 110, 420]) == 420, "Test 4 failed"
print("Test 4 passed")
assert maximum([42, 10, 6, 19, 72]) == 72, "Test 5 failed"
print("Test 5 passed")


def areReverse(s1, s2):
    """check if the two input strings are reverses of each other

    Args:
        s1 (string): first input string
        s2 (string): second input string

    Returns:
        boolean: 
            True of both input strings are reverses of each other
            False if otherwise
    """
    if len(s1) == len(s2):
        for i in range(len(s1)):
            if s1[i] != s2[len(s1) - i - 1]:
                return False
        return True
    else:
        return False


print("Running tests")
assert areReverse("cat", "tac") == True, "Test 1 failed"
print("Test 1 passed")
assert areReverse("racecar", "racecar") == True, "Test 2 failed"
print("Test 2 passed")
assert areReverse("denison", "denison") == False, "Test 3 failed"
print("Test 3 passed")
assert areReverse("181", "181") == True, "Test 4 failed"
print("Test 4 passed")
assert areReverse("python", "nohtyp") == True, "Test 5 failed"
print("Test 5 passed")


def duplicateString(s):
    """generate a string where every character will appear twice next to each other based on an input string

    Args:
        s (string): an input string to have its characteres duplicated

    Returns:
        string: a new duplicated string where very character will appear twice next to each other
    """
    newString = ""
    for char in s:
        newString += (char+char)
    return newString


print("Running tests")
assert duplicateString("cat") == "ccaatt", "Test 1 failed"
print("Test 1 passed")
assert duplicateString("hello") == "hheelllloo", "Test 2 failed"
print("Test 2 passed")
assert duplicateString("denison") == "ddeenniissoonn", "Test 3 failed"
print("Test 3 passed")
assert duplicateString("computer") == "ccoommppuutteerr", "Test 4 failed"
print("Test 4 passed")
assert duplicateString("dog") == "ddoogg", "Test 5 failed"
print("Test 5 passed")


def merge(L1, L2, n):
    """generate a new sorted list using two input sorted list

    Args:
        L1 (List): first sorted list
        L2 (List): second sorted list
        n (integer): common length of both sorted list

    Returns:
        List: a sorted list, containing values from both input lists
    """
    newList = []
    i = 0
    j = 0
    while (i < len(L1) and j < len(L2)):
        if (L1[i] < L2[j]):
            newList.append(L1[i])
            i += 1
        else:
            newList.append(L2[j])
            j += 1
    if (i >= len(L1)):
        while j < len(L2):
            newList.append(L2[j])
            j += 1
    else:
        while i < len(L1):
            newList.append(L1[i])
            i += 1
    return newList


print("Running tests")
assert merge([1, 2, 3, 4], [5, 6, 7, 8], 4) == [
    1, 2, 3, 4, 5, 6, 7, 8], "Test 1 failed"
print("Test 1 passed")
assert merge([2, 4, 6, 8], [1, 3, 5, 7], 4) == [
    1, 2, 3, 4, 5, 6, 7, 8], "Test 2 failed"
print("Test 2 passed")
assert merge([1, 2, 3, 4], [1, 2, 3, 4], 4) == [
    1, 1, 2, 2, 3, 3, 4, 4], "Test 3 failed"
print("Test 3 passed")
assert merge([-4, -3, -2, -1], [1, 2, 3, 4], 4) == [
    -4, -3, -2, -1, 1, 2, 3, 4], "Test 4 failed"
print("Test 4 passed")
assert merge([], [], 0) == [], "Test 5 failed"
print("Test 5 passed")


def twoThreeFactorsOnly(x):
    """check if an input integer is a factor of 2 and 3

    Args:
        x (integer): input integer

    Returns:
        boolean:
            True if the input integer is a factor of 2 and 3
            False if the input integer is not a factor of 2 and 3 (even False if the integer is a factor of 2 or 3)
    """
    if x % 2 == 0 and x % 3 == 0:
        while x != 1:
            if x % 2 == 0:
                x = x / 2
            elif x % 3 == 0:
                x = x / 3
            else:
                return False
        return True
    else:
        return False


print("Running tests")
assert twoThreeFactorsOnly(9) == False, "Test 1 failed"
print("Test 1 passed")
assert twoThreeFactorsOnly(4) == False, "Test 2 failed"
print("Test 2 passed")
assert twoThreeFactorsOnly(6) == True, "Test 3 failed"
print("Test 3 passed")
assert twoThreeFactorsOnly(749) == False, "Test 4 failed"
print("Test 4 passed")
assert twoThreeFactorsOnly(11664) == True, "Test 5 failed"
print("Test 5 passed")
