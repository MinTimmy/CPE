#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b)
{
  return ( *(int*)a > *(int*)b);
}

int main()
{
  int num[] = {456,15,48,45,1,654,51,486,45,16,54,51,67,5,165,4,651,567,656,45,4,654,1002};

  qsort(num, sizeof(num) / sizeof(int), sizeof(int), compare);

  for(int i = 0; i < sizeof(num)/sizeof(int); i++){
    printf("%d ", num[i]);
  }
}