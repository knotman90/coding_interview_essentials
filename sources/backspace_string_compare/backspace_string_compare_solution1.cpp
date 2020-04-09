    bool backspaceCompare(string S, string T) {
        
        int i = S.size()-1;
        int j = T.size()-1;
        int cd1, cd2;
        cd1 = cd2 = 0;
        
        while(i>=0 || j >=0)
        {
            cout<<i<<" "<<j<<endl;
           if(i>=0)
           {
               if(S[i]=='#'){
                    cd1++;
                    i--;
                    continue;
                }
               else if(cd1)
               {
                   i--;
                   cd1--;
                   continue;
               }
           }
            
            
           if(j>=0)
           {
               if(T[j]=='#'){
                    cd2++;
                    j--;
                    continue;
                }
               else if(cd2)
               {
                   j--;
                   cd2--;
                   continue;
               }
           }
        
           if((i>=0 && j<0) || (i<0 && j>=0) || S[i]!=T[j] )
               return false;   
            
            if(i>=0)
                i--;
            if(j>=0)
            j--;
            
            
        }
        return true;
    }