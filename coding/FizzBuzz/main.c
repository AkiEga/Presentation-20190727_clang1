#include <stdio.h>

int main(int argc, char **argv){	
	int i;
	for(i = 1;i<101;i++){
		printf("% 4d: ", i);
		if(i%15 == 0){
			printf("FizzBuzz\n");
		}else if(i%3 ==0){
			printf("Fizz\n");
		}else if(i%5 ==0){
			printf("Buzz\n");
		}else{
			printf("%d\n",i);
		}
	}
	return 0;
}


    for(char *word = "Fizz\0Buzz";argc<20;argc++)
        printf("%d:%s\n",argc,(word+14-4*(argc%2==0)-9*(argc%3==0)));

    main(i){for(char *w="FizzBuzz\0Fizz";i<101;i++)printf("%s\n",(w+13-4*(i%2==0)-9*(i%3==0)))}


/*
参考) FizzBuzzのcodegolfを世界一分かりやすく解説！#c言語 - Qiita
URL: https://qiita.com/smicle/items/cf48853177e5ffdc574b

↓実はここまで詰められたりします
```c
main(i){for(;i<101;puts(i++%5?"":"Buzz"))printf(i%3?i%5?"%d":0:"Fizz",i);}
```
*/