#include <stdio.h>
#include <math.h>

void input(int x, int y);
double distance(int x, int y);
void output(int x, int y, double d);

typedef struct point
{
  int x;
  int y;
} POINT;

int main()
{
  POINT p1;
  input(p1.x, p1.y);
  printf("%d, %d", p1.x, p1.y);
  // double d = distance(p1.x, p1.y);
  // output(p1.x, p1.y, d);
  return 0;
}

// 入力
void input(int x, int y)
{
  POINT p;
  printf(" > (x, y) < ");
  scanf("%d %d", &p.x, &p.y);
  x = p.x;
  y = p.y;
}

// 原点からの距離を計算
double distance(int x, int y)
{
  return sqrt(x * x + y * y);
}

// 出力
void output(int x, int y, double d)
{
  printf("Distance between (%d, %d) and (0, 0) is %.2f\n", x, y, d);
}

/*
1.プログラミング方針
まず入力部分で座標を入力する。次に入力した座標を使って原点からの距離を求める。最後にその距離を出力する。

2.実行結果
 > (x, y) < 3 4
Distance between (3, 4) and (0, 0) is 5.00

 > (x, y) < -3 4
Distance between (-3, 4) and (0, 0) is 5.00

 > (x, y) <  5 8
Distance between (5, 8) and (0, 0) is 9.43


3.プログラムを作成する上での困難だった点、工夫点
どこで構造体を使って、どこで使わないかをよく考えた。構造体は、人間が見やすいように変数をまとめたものだと認識している。計算部分や入出力部分は、ある特定の変数について扱っているのではなく、普遍的な変数を扱うものなのでpという普遍的な変数を使った。そしてmainの中身は具体的な変数であるのでp1などとして、p2, p3などと簡単に変数を増やせるように工夫した。
また、C言語において関数が二つの戻り値をはけないというのが面倒だった。関数の中で引数にそのまま値をいれればいいのではないかと思ったが、それではそれを解決するためにポインタを使って二つの戻り値があるかのようにした。

*/
