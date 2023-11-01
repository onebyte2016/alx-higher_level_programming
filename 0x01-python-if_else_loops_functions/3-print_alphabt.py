#!/usr/bin/python3
for char in range(ord('a'), ord('z') + 1):
  if char != 'e' and char != 'q':
   print("{}".format(chr(char)), end="")
