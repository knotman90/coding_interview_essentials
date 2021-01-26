/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int removeDuplicates(int* A, int n1)
{
  if (n1 <= 1)
    return n1;

  int last_inserted      = 0;
  int currently_examined = 1;
  int consecutive        = 1;
  while (currently_examined < n1)
  {
    if (A[last_inserted] == A[currently_examined] && consecutive == 1)
    {
      A[++last_inserted] = A[currently_examined];
      consecutive        = 2;
    }
    if (A[last_inserted] != A[currently_examined])
    {
      A[++last_inserted] = A[currently_examined];
      consecutive        = 1;
    }
    currently_examined++;
  }
  return last_inserted + 1;
}
