# リベンジ、はじめてのC -あのわからなかったポインタが-
## アジェンダ
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->
<!-- code_chunk_output -->

- [リベンジ、はじめてのC -あのわからなかったポインタが-](#リベンジ-はじめてのc-あのわからなかったポインタが-)
  - [アジェンダ](#アジェンダ)
  - [自己紹介](#自己紹介)
  - [この勉強会について](#この勉強会について)
  - [C言語講座](#c言語講座)
    - [C言語とは](#c言語とは)
    - [ワークフロー (実演)](#ワークフロー-実演)
    - [開発環境](#開発環境)
    - [基本的文法](#基本的文法)
    - [ポインターとは? -hello worldからわかるポインタ-](#ポインターとは-hello-worldからわかるポインタ-)
    - [(演習) FizzBuzz](#演習-fizzbuzz)
        - [出力例](#出力例)
    - [雑談](#雑談)

<!-- /code_chunk_output -->
## 自己紹介
- 出身&来歴: 
```
AD198x: 千葉に生まれる
AD2007: 大学@東京 
AD2011: 大学院@東京 
AD2013: とある自動車部品メーカー@愛知に就職 
AD2019: 東京🗼へ転勤　←いまココ 
```
<br>

- 得意分野
  - OS: Linux, RTOS(Tron系), Windows NT
  - Lang. :   
    - C/C++(そこそこガッツリ) 
    - C#(ちょいちょい),  
    - Python(そこそこ) 
    - Powershell(好き)  
    - JavaScript&Typescript(ちょっと)
  - Lib. : CUDA, OpenMP, OpenMPI, OpenCV
  - Platform: WPF, Qt, Windows API, .NET
  - Other: 画像処理、並列処理、組み込み
<br>
- 趣味
  オタク趣味全般, 自動車, 野球観戦, 自作PC, 自作キーボード, etc

## この勉強会について
- 対象者
	- 以前C言語を学んだけど、イマイチ理解していなから学び直したい人
	- これからC言語を勉強するので、しっかり学びたい人

- 参加者へのお願い事
	- なるべく会話しながら進めてゆきたいです。途中での質問大歓迎です！<br>
		"自分の疑問はみんなの疑問" 是非共有させてください。

## C言語講座
### C言語とは
- 特徴
  - コンパイル型言語
    CPUが理解しやすい機械語に変換(コンパイル)を要します
  - 手続き型言語
- メリット
  - 処理速度が高速
    - 中間処理が少ないのでCPUの処理量がすくない
    - ハードウェアに特化した処理を実装しやすいので並列処理(OpenMP, CUDA, SSE...)を追加しやすい
    - 上記特性なので、さらに最適化をかけて高速化されたライブラリも多数存在(boost, openblas)
  - CPUやメモリといったハードウェアの処理を意識したプログラミングを要求されるのでスキルアップしやすい
  - 歴史が古いのでソフト資産が膨大(e.g. boost, openblas, UNIX, Linux)
  - 組み込み系/IOT(arudino, mbed )との相性良好
- デメリット
  - プログラミングの難易度が高い
  - オブジェクト指向を標準でサポートしていない

### ワークフロー (実演)
お馴染み "hello world" を実演します
1. コーディング
  ソースコードを書く
  ```c
  #include <stdio.h>

  int main(int argc, char **argv){
    printf("hello world\n");
    return 0;
  }
  ```
2. コンパイル(ビルド)
  コンパイラというツールCPUが理解しやすい機械語に変換し実行ファイルを作る(e.g. a.out)
  ```shell
  $ clang main.c
  ```
3. テスト
  実行ファイルを動かして意図通りに動いているか確認
  ```shell
  $ a.exe
  ```
4. (意図通りに動いていれば) 完成
  ```shell
  $ .\a.exe
  hello world
  ```
<br>

### 開発環境
手っ取り早いのなら↓がおすすめです。<br>
[Online C++ compiler | ブラウザでプログラミング・実行ができる「オンライン実行環境」| paiza.IO](https://paiza.io/ja/projects/new?language=cpp)

本格的にやりたい場合は
- windows: 
  - visual studio 2019 (IDE)
  - eclipse (IDE)
  - gcc from MinGW (Compiler)
  - clang (Compiler)

- mac
  - xcode (IDE)
  - visual studio for mac (IDE)
  - gcc (Compiler)
  - clang (Compiler)

- linux
  - gcc (Compiler)
  - clang (Compiler)
  - eclipse (IDE)

- multi platform
  - eclipse (IDE)
  - CLion (IDE)
  - QtCreator (IDE)

### 基本的文法
- コメント
基本的には下記コメントが可能。
```c
/*hogehoge*/
// fugafuga
```
- 型
  - 数値
  	int: 整数
	  float: 浮動小数点
  - 文字
	  char: 文字

- 変数
  - 宣言, 代入
  ```c
  int a;
  float b;
  char c='c';
  a = 1;
  b = 2;
  ```
  - 配列
  ```c
  int a[3] = {1,2,3};
  char h[5] = {'h', 'e', 'l', 'l', 'o'};
  char w[] = "world";
  ```
- 算術式
	- 四則演算(+, -, *, /)
  - 剰余算
  ```c
  int a;
  a = 4%3; // a = 1
  ```
- インクリメント/デクリメント
  ```c
  int a=0, b;
  a = a + 1;  // a = 1
  a++;        // a = 2
  a+=10;      // a = 12
  a--;        // a = 11

  // 前置きと後置きで挙動が違う
  // 前置き: インクリメント → インクリメント以外の処理
  // 後置き: インクリメント以外の処理 → インクリメント
  b = ++a;    // b = 12, a=13 
  ```


- 条件文(if, switch)
  - if
  ```c
  if( a == b){ 
    // aとbが等しい時
    hoge();
  }else if(a == c){
    // aとbが等しくなく、かつ、aとcが等しい時
    fuga();
  }else{
    // aとbが等しくなく、かつ、aとcも等しくない時
    hogefuga();
  }
  ```

- ループ文(for, while)
  - for
  ```c
  int i,a;
  a=0;
  for(i=0;i<100;i++){
    a = a+1;
  }
  ```
  - while
  ```c
  int i=0;
  while(i<100){
    i++;
    fugafuga();
  }
  ```
  ```c
  int i=0;
  do{
    i++;
    fugafuga();
  }while (i<1); // iが1になっているのでここです抜けてしまう
  ```

### ポインターとは? -hello worldからわかるポインタ-
- ポインターとは?
  c言語はメモリ上の値を参照できる "ポインター" という機能があります。

  ```c
  int a=0;
  int *b; // 'int *' でint型のアドレスを指し示すためのポインタ
  b = &a; // '&'でその変数のアドレスを渡すという意味
  a = 1;  // a = 1, b =1
  b = 2;  // a = 2, b =2
  ```

  変数の項で一瞬文字列のお話をしましたが、
  文字列であるchar[]はchar型の値がメモリ空間上に詰められているだけです。
  (以降、実演)


### (演習) FizzBuzz
1から100までの数字に対し、下記ルールで出力するプログラムをc言語で書いてください  
- 3で割り切れる場合は: Fizz
- 5で割り切れる場合は: Buzz
- 両者で割り切れる場合は: Fizz Buzz
- それ以外は: そのままの数字

##### 出力例
```shell
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
```

### 雑談
例)  
- こんな物作りたいんですけどどうすればいいですか?
- 開発環境についての悩み