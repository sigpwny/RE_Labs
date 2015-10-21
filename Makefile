all: C_to_x86 Mr.E
	
C_to_x86:
	gcc -m32 -ggdb -o C_to_x86 C_to_x86.c
	
Mr.E:
	gcc -m32 -s -o Mr.E Mr.E.c

.PHONY: C_to_x86 Mr.E

clean:
	rm C_to_x86 Mr.E


