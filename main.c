#include <stdio.h>

/* Find log2(num) */
int Log2( int num )
{
  int pwr = 0;

  while (num > 1)
  {
    num >>= 1;
    pwr++;
  }

  return pwr;
} /* End of 'Log2' function */

/* Translate from decimal to aliquot to binary system */
void Dec2Any( int num, int base, char *res )
{
  int i, pwr = 0;

  pwr = Log2(base);

  for (i = 31; i >= 0; i--)
  {
    int tmp_num = num & (base - 1);

    if (tmp_num < 10)
      res[i] = '0' + tmp_num;
    else
      res[i] = 'A' + tmp_num - 10;
    num >>= pwr;
  }

  res[32] = '\0';
} /* End of 'Dec2Any' function */

/* Transpose number bits function */
void Transpose( int *num )
{
  int tmp = *num, num_fin = 0, bits_four;

  for (bits_four = 0; bits_four < 8; bits_four++)
  {
    num_fin <<= 4;
    num_fin += tmp & 15;
    tmp >>= 4;
  }

  *num = num_fin;
} /* End of 'Translate' function */

/* Program main function */
void main( void )
{
  int n;
  char res2[33], res16[33];

  scanf("%i", &n);

  Dec2Any(n, 2, res2);
  Dec2Any(n, 16, res16);

  printf("Bin: %s\nHex: %s\nTransposed:\n", res2, res16);

  Transpose(&n);

  Dec2Any(n, 2, res2);
  Dec2Any(n, 16, res16);

  printf("Bin: %s\nHex: %s", res2, res16);
} /* End of 'main' function */
