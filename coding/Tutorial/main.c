#include <stdio.h>

int main(int argc, char **argv){
	char hello_world[]= "hello world";
	printf("hello_world array's address is %p.\n",hello_world);

	int i;
	for(i=0;i<sizeof(hello_world);i++){
		printf("%c: %p\n", hello_world[i], &hello_world[i]);
	}
	return 0;
}