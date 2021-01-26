std::string decode_string_recursive_helper(const std::string& s, std::size_t& i)
{
    const auto size = s.size();
    std::string ans;
    int multiplier = 0;
    while(i < size)
    {
        const auto curr_char = s[i];
        if(std::isdigit(s[i]))
        {
            //parse the whole number
            while(i < size && std::isdigit(s[i]))
            {
                multiplier*=10;
                multiplier+=s[i]-'0';
                i++;
            }   
        }else if(s[i]=='[')
        {
            const std::string nested = decode_string_recursive_helper(s, ++i);
            for(int k = 0 ; k < multiplier ;k++)
                ans+=nested;
            //no increment of i here.
        }else if(s[i]==']')
        {
            i++;
            break;
        }else{
            ans+=s[i];
            i++;
        }
    }
    return ans;
}

std::string decode_string_recursive(const std::string& s)
{
    std::size_t pos = 0;
    return decode_string_recursive_helper(s,pos);
}