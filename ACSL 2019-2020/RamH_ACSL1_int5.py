# Hrishikesh Ram 12/12/2019
# Enloe High School, Raleigh NC, 11th Grade
# Intermediate Contest 1


def transform(n, p):
    result = ""
    for i in range(0, len(str(n))-p):
        result += str(int(str(n)[i]) + int(str(n)[len(str(n))-p]))[len(str(int(str(n)[i]) + int(str(n)[len(str(n))-p])))-1]
    result += str(n)[len(str(n))-p]
    for i in range(len(str(n))-p+1, len(str(n))):
        result += str(abs(int(str(n)[i]) - int(str(n)[len(str(n))-p])))[len(str(abs(int(str(n)[i]) - int(str(n)[len(str(n))-p]))))-1]
    return result


file = open("D://intdata.txt")
for i in range(5):
    inp = file.readline()
    print(transform(int(inp[0:inp.find(" ")]), int(inp[inp.find(" ")+1:])))
