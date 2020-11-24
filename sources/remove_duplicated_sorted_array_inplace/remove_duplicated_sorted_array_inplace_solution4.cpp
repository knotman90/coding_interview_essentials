/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int removeDuplicates(int* A, int n1) {
    if(n1 <= 1)
        return n1;
    int x1 = 0;
    int y = 1;
    int consecutive = 1;
    while(y < n1)
    {
        if(A[x1] == A[y] && consecutive == 1){
            A[++x1] = A[y]; 
            consecutive = 2;
        }
        if(A[x1] != A[y]){
            A[++x1] = A[y]; 
            consecutive = 1;
        }
        y++;
    }
    return x1+1;
    
}
