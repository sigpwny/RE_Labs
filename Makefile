all: C_to_x86
	
C_to_x86:
	gcc -m32 -ggdb -o C_to_x86 C_to_x86.c

.PHONY: C_to_x86

clean:
	rm C_to_x86


