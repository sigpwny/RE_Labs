#include <stdio.h>
#include <string.h>



int function(int a, int b)
{
    int c = 0;
    c = a + b;
    return c;
}

int main(){
	int i;
        int a = 0, b = 2, c = 0;

	for (i = 0; i < 10; i++)
        {
            if(a == 4)
            {
                a += 2*b;
            }
            else
            {
    	        a += b;
            }
	}
	
        c = function(a, b);

	return 0;
}
