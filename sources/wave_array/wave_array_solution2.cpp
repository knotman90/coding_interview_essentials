std::vector<int> wave_linear(const std::vector<int> &A) 
{

    if(A.size() <= 2)
    	return A;

    std::vector<int> B(A);
    for(size_t i = 0 ; i < B.size() ; i+=2)
    {
        std::cout<<B<<std::endl;
        if(i > 0 && B[i-1] > B[i])
        	std::swap(B[i-1], B[i]);

        if(i < B.size()-1 && B[i+1] < B[i])
        	std::swap(B[i+1],  B[i]);
    }
    return B;
}
