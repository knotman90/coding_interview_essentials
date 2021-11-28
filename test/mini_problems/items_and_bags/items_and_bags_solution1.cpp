 #include <algorithm>
 #include <numeric>

size_t items_and_bags(const std::vector<int> &F, std::vector<int> &B) {
    std::sort(B.begin(), B.end(), std::greater<int>());
    auto sum = std::accumulate(F.begin(), F.end(), 0);
    size_t Bidx = 0;
    while(sum > 0){
        sum-=B[Bidx];
        if(sum <= 0)
            break;
        Bidx++;
    }
    return Bidx+1;
}