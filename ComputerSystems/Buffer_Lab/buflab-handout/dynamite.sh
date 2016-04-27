#!/bin/bash
gcc -m32 -c asm_dynamite.s
objdump -d asm_dynamite.o > asm_dynamite.d
cat asm_dynamite.d
