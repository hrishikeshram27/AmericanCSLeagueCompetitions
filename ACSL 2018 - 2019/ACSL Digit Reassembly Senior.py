with open('ACSL1Senior.txt') as myFile:
	for x in range(5):
		full_line = myFile.readline()
		num = full_line[:(full_line.find(' '))]
		looper = int(full_line[((full_line.find(' '))+1):])
		add = 0
		while len(num) >= looper:
			add += int(num[0:looper])
			num = num[looper:]
		else:
			while len(num) < looper:
				num += '0'
			add += int(num)
		print('Input: ',full_line,'\nOutput: ',add,'\n------------------------------------------',sep='')
