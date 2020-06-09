# Hrishikesh Ram 01-22-2020
# Enloe High School, Raleigh NC, 11th Grade
# Senior Contest 2
def common(one, two):
    longest = ""
    for i in range(0, len(one)):
        for j in range(i, len(one) + 1):
            if one[i:j] in two and len(one[i:j]) == len(longest) and one[i:j] < longest:
                longest = one[i:j]
            elif one[i:j] in two and len(one[i:j]) > len(longest):
                longest = one[i:j]
    return longest


commons = []


def difference(one, two):
    if len(common(one, two)) > 0:
        splitter = common(one, two)
        commons.append(common(one, two))
        oneOne = one[:one.find(splitter)]
        oneTwo = one[one.find(splitter) + len(splitter):]
        twoOne = two[:two.find(splitter)]
        twoTwo = two[two.find(splitter) + len(splitter):]
        difference(oneOne, twoOne)
        difference(oneTwo, twoTwo)


myFile = open("D://ACSL 2//2srtest.txt")

for i in range(5):
    commons.clear()
    str1 = myFile.readline()
    str2 = myFile.readline()

    str1 = ''.join(char for char in str1 if char.isalpha()).upper()
    str2 = ''.join(char for char in str2 if char.isalpha()).upper()

    difference(str1, str2)
    print(sum([len(word) for word in commons]))

myFile.close()