#include <stdio.h>
#include <math.h>

void input(int *px, int *py);
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
  input(&p1.x, &p1.y);
  output(p1.x, p1.y, distance(p1.x, p1.y));
  return 0;
}

// 入力
void input(int *px, int *py)
{
  POINT p;
  printf(" > (x, y) < ");
  scanf("%d %d", &p.x, &p.y);
  *px = p.x;
  *py = p.y;
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