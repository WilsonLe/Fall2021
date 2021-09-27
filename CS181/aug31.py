def sumSquares(n):
    sum = 0
    for i in range(1, n + 1):
        sum += i*i
    return sum


def charCount(s, c1, c2):
    count = 0
    for i in range(len(s)):
        if c1 == s[i] or c2 == s[i]:
            count += 1
    return count


def XORSub(s, s1, s2):
    if (s1 in s or s2 in s):
        if (s1 in s and s2 in s):
            return False
        else:
            return True
    else:
        return False


# print(sumSquares(3))
# print(charCount('hello', 'h', 'o'))
print(XORSub('dogcat', 'dog', 'pig'))
