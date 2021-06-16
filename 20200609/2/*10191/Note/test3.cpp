/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */
#include <vector>

std::vector<int> values = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
//   qsort (values.data(), 6, sizeof(int), compare);
  qsort (values.data(), 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}