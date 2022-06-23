#include <stdio.h>

void input();
void search_area(int i);
void output();

struct point
{
  int x;
  int y;
};

struct point tmp_num;
struct point table[5][100];
int count_each_area[5] = {0, 0, 0, 0, 0};

int main()
{
  input();
  output();
}

// 入力
void input()
{
  int i = 0;
  while (scanf("%d %d", &tmp_num.x, &tmp_num.y) != EOF)
  {
    search_area(i);
    i += 1;
  }
}

// 領域を判定する
void search_area(int i)
{
  if (tmp_num.x > 0 && tmp_num.y > 0)
  {
    table[1][i].x = tmp_num.x;
    table[1][i].y = tmp_num.y;
    count_each_area[1] += 1;
  }
  else if (tmp_num.x < 0 && tmp_num.y > 0)
  {
    table[2][i].x = tmp_num.x;
    table[2][i].y = tmp_num.y;
    count_each_area[2] += 1;
  }
  else if (tmp_num.x < 0 && tmp_num.y < 0)
  {
    table[3][i].x = tmp_num.x;
    table[3][i].y = tmp_num.y;
    count_each_area[3] += 1;
  }
  else if (tmp_num.x > 0 && tmp_num.y < 0)
  {
    table[4][i].x = tmp_num.x;
    table[4][i].y = tmp_num.y;
    count_each_area[4] += 1;
  }
  else
  {
    table[0][i].x = tmp_num.x;
    table[0][i].y = tmp_num.y;
    count_each_area[0] += 1;
  }
}

// 出力する
void output()
{
  for (int j = 1; j < 5; j++)
  {
    printf("The number of %d quadrant (RUQ) = %d\n", j, count_each_area[j]);
    for (int i = 0; i < 100; i++)
    {
      if (table[j][i].x != 0)
      {
        printf("(%d, %d)\n", table[j][i].x, table[j][i].y);
      }
    }
    printf("\n");
  }
}