#if 0 
void printMatrix(vector<vector<int> > &B){
        const int rows = B.size();
   
    const int cols = B.back().size();
      for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                cout<<B[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
}


vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<vector<int> > temp = B;
    
    
    const int rows = B.size();
    if(rows <= 0 )
        return B;
    const int cols = B[0].size();
    if(cols <= 0)
        return B;
        
        // printMatrix(temp);
    for(int a = 0 ; a < A ; a++ )
    {
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                int m = B[i][j];
                if(i > 0){
                    m = std::max(m, B[i-1][j]);
                }
                if(i < rows-1){
                    m = std::max(m, B[i+1][j]);
                }
                if(j > 0){
                    m = std::max(m, B[i][j-1]);
                }
                if(j < cols-1){
                    m = std::max(m, B[i][j+1]);
                }
                temp[i][j] = m;
            }
        }
        
        B = temp;
       // printMatrix(temp);
    }
    return B;
}
#endif