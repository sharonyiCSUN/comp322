# CS322LAB-0
Making Sense of Ones and Zeroes
The concept of this program is to intake either a filename or integers to be translated from ASCII to binary.
From there it will convert binary to ASCII character, decimal, and Parity bit.

What I did was have the program check if the inputs are valid, which are:
 if the content after argv[0] is either a '-', filename (.txt), n number of 8-bits or less, or '-' followed by n number of 8-bits

If argv[1] has content ('-' followed by n number of 8-bits, filename(.txt), or n number of 8-bits or less, then the program will then continue and proceed to pring out the 8-bits, ASCII character, decimal value after converted to ASCII, then the parity bit.
