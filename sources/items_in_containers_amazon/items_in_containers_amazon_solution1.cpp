using Query = std::pair<int,int>;
constexpr char kContDelimiter = '|';
constexpr char kItem = '*';

int count_items_in_substring(const std::string& s ,const Query& query)
{
    const auto& [start,end] = query;
    assert(start <=end);
    assert(end <= std::ssize(s));

    auto curr_char = start;
    //find the first container
    while(curr_char <= end && s[curr_char]!=kContDelimiter)
        curr_char++;
    curr_char++;

    int ans = 0;
    int cont_counter = 0;
    while(curr_char <= end)
    {
        if(s[curr_char]==kItem){
            cont_counter++;
        }else if(s[curr_char]==kContDelimiter){
            ans+=cont_counter;
            cont_counter=0;
        }
        curr_char++;
    }
    return ans;
}
std::vector<int> items_in_containers_naive(const std::string& curr_char,const std::vector<Query>& Q)
{
    std::vector<int> ans;
    ans.reserve(Q.size());
    for(const auto& q : Q)
        ans.push_back(count_items_in_substring(curr_char, q));
    return ans;
}