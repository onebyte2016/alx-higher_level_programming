#!/usr/bin/python3
for char in range(ord('a'), ord('z') + 1):
	char = chr(char)
	if char != 'e' and char != 'q':
		print("{}".format(char), end="")
