---
title: リベンジ、はじめてのC ~あのわからなかったポインタが~
---

# アジェンダ
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->
<!-- code_chunk_output -->

- [アジェンダ](#アジェンダ)
- [この勉強会について](#この勉強会について)
- [参考](#参考)

<!-- /code_chunk_output -->

# この勉強会について
- 対象者
	- 以前C言語を学んだけど、イマイチ理解していなから学び直したい人
	- これからC言語を勉強するので、しっかり学びたい人
	- 転職面接のFizzBuzz試験でドヤ顔したい方

- 参加者へのお願い事
	- なるべく会話しながら進めてゆきたいです。途中での質問大歓迎です！
		"自分の疑問はみんなの疑問" 是非共有させてください。

アジェンダ
- C言語とは
	- 概要
	- 出来ること

- 基本的文法 ~FizzBuzzへの最短の道~
	- 型(int, float, char...)
	- 算術式
	- 条件文(if, switch)
	- ループ文(for, while)

- ポインターとは? ~FizzBuzzから分かるポインター～

    for(char *word = "Fizz\0Buzz";argc<20;argc++)
        printf("%d:%s\n",argc,(word+14-4*(argc%2==0)-9*(argc%3==0)));

    main(i){for(char *w="FizzBuzz\0Fizz";i<101;i++)printf("%s\n",(w+13-4*(i%2==0)-9*(i%3==0)))}


main(i){
	for(char*w="FizzBuzz\0Fizz";i<101;i++)
		if(i%3==0||i%5==0){
			printf("%s\n",w+13-4*(i%5==0)-9*(i%3==0))
		}else{
			printf("%d\n",i)
		}

for(char*w="FizzBuzz\0Fizz";i<101;i++){int j=4*(i%5==0)+9*(i%3==0);j>0?printf("%s\n",w+13-j):printf("%d\n",i);}

for(;i<101;i++){int j=4*(i%5==0)+9*(i%3==0);j>0?printf("%s\n",&"FizzBuzz\0Fizz"[13-j]):printf("%d\n",i);}

main(i){
	for(;i<101;puts(i++%5?"":"Buzz"))
		printf(
			i%3?
				i%5?
					"%d":
				0:
				"Fizz"
			,i);
}

main(i){
	for(char*w="FizzBuzz\0Fizz";i<101;i++)
		if(i%3==0||i%5==0){
			printf("%s\n",w+13-4*(i%5==0)-9*(i%3==0))
		}else{
			printf("%d\n",i)
		}

# 参考
Title: FizzBuzzを1byteで実装する - Qiita
URL: https://qiita.com/ymg_aq/items/b8e5d26035180bc8797e#_reference-47928755625956643f7b

Title: How to Manipulate Filenames Having Spaces and Special Characters in Linux
URL: https://www.tecmint.com/manage-linux-filenames-with-special-characters/