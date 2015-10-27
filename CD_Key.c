#include <stdio.h>
#include <string.h>

static char var1[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
_
void func1(){
	printf("Invalid CD key!\n");
}


int func2(char chr){
	if ((chr >= 48) && (chr <= 57))
		return 1;
	else
		return 0;
}


int func3(char chr){
	if ((chr >= 65) && (chr <= 90))
		return 1;
	else
		return 0;
}


int func4(char* var3){
	int var2 = 0;	
	for (int i = 0; i < 20; i++){
		var2 += var3[i];
	}
	var2 *= 1337;
	var2 %= 89989;
	var2 +=10000;
	char var4[6];
	sprintf(var4, "%d", var2);
	if (!strcmp(var4, &var3[20])){
		return 1;
	}
	else
		return 0;	
}


int func5(char* var3){
	if ((var3[15] == var1[(((int)(var3[5] ^ var3[10]) + 13) % 26) + 10]) && (var3[19] == var1[((var3[9] ^ var3[14] + 13) % 26) + 10]))
		return 1;
	else
		return 0;
}



int func6(char* var3){
	int var5 = 0;	
	for (int i = 0; i < 5; i++){
		
		if (var3[10+i] == var1[((var3[0+i] + var3[5+i]) % 36)]){
			var5++;
		}
	}
	if (var5 == 5){
		return 1;
	}
	else
		return 0;
}

 
int func7(char* var3){
	int var6 = 0;	
	for (int i = 5; i < 10; i++){
		if (func2(var3[i]))
			var6 += var3[i];
	}	
	if (var6 % 2 == 1)
		return 1;
	else
		return 0;
}




int main(int argc, char* argv[]){
	if (argc != 2){
		printf("Usage: ./CDKeyValidator <CD_Key>\n");
		return 0;
	}

	if (strlen(argv[1]) != 25) {
		func1();
		return 0;
	}
	printf("Passed First Check!\n");
	char var3[26];
	strncpy(var3, argv[1], 26);
	int var7 = 0;

	for (int i = 0; i < 25; i++){
		if (func2(var3[i]) || func3(var3[i])){

		}
		else{
			func1();
			return 0;
		}
	}
	printf("Passed Second Check!\n");

	if(!(func2(var3[0]) && func3(var3[4]))){
		func1();	
		return 0;
	}
	else
		var7++;
	printf("Passed Third Check!\n");

	if(func7(var3)){
		var7++;
	}
	else{
		func1();
		return 0;
	}	
	printf("Passed Fourth Check!\n");	

	if (func6(var3)){
		var7++;
	}
	else{
		func1();
		return 0;
	}	
	printf("Passed Fifth Check!\n");
	

	if(func5(var3)){
		var7++;
	}
	else{
		func1();
		return 0;
	}	
	printf("Passed Sixth Check!\n");

	if (func4(var3)){
		var7++;
	}
	else{
		func1();
		return 0;
	}
	printf("Passed Seventh Check!\n");
	

	if (var7 == 5)
		printf("Correct CD Key!\n");
	else 
		printf("Invalid CD Key!\n");




	return 0;
}










