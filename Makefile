all: C_to_x86 C_to_x86_simple Mr.E CD_Key Comb
	
C_to_x86:
	gcc -m32 -o C_to_x86 C_to_x86.c

C_to_x86_simple:
	gcc -m32 -o C_to_x86_simple C_to_x86_simple.c
	
CD_Key:
	gcc -m32 -std=c99 -o CD_Key CD_Key.c
	
Mr.E:
	gcc -m32 -s -o Mr.E Mr.E.c
	
Comb:
	gcc -m32 -o combination combination.c -lm

.PHONY: C_to_x86 C_to_x86_simple Mr.E CD_Key

clean:
	rm C_to_x86 C_to_x86_simple Mr.E CD_Key


