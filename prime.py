'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
import sys
import math

def findpower(num):
	divisor = 2
	prod = 1
	while True:
		div = 0
		while num%divisor == 0:
			div = div + 1
			num = num/divisor
		if divisor == 2:
			prod = prod * div
		else:
			prod = prod * ( div + 1 )
		divisor = divisor + 1
		if divisor * divisor > num:
			if num > 1:
				prod = prod * 2
			break
	return prod
	
T = int(sys.stdin.readline())
answers = []

for i in xrange(T):
	N = int(sys.stdin.readline())
	print findpower(N)
