# Hrishikesh Ram 12/12/2019
# Enloe High School, Raleigh NC, 11th Grade
# Senior Contest 1


def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            if i not in factors:
                factors.append(i)
    if n > 1:
        if n not in factors:
            factors.append(n)
    return len(factors)


def transform(n, p):
    result = ""
    for i in range(0, len(str(n))-p):
        result += str(int(str(n)[i]) + int(str(n)[len(str(n))-p]))
    if n != 1:
        result += str(prime_factors(n))
    for i in range(len(str(n))-p+1, len(str(n))):
        result += str(abs(int(str(n)[i]) - int(str(n)[len(str(n))-p])))
    return result


file = open("D://srdata1.txt")
for i in range(5):
    inp = file.readline()
    print(transform(int(inp[0:inp.find(" ")]), int(inp[inp.find(" ")+1:])))
