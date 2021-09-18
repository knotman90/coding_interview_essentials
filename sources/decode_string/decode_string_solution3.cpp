// solution submitted by a candidate at degiro
// git stQuadratic time complexity
enum class status
{
    start,
    letter,
    number
};

std::string decompress_document(const std::string& aStr) {
    int length = aStr.length();
    
    std::string result;
    int current_index = 0;
    
    status current_status = status::start;
    int current_number = 0;
    
    while(current_index < length)
    {
        const char &new_char = aStr[current_index];
        if (new_char >= 'a' && new_char <= 'z')
        {
            if (current_status == status::number)
                throw std::runtime_error("bad format");
            
            current_status = status::letter;
            result += new_char;            

			++current_index;
        }
        else if(new_char >= '0' && new_char <= '9')
        {
            if (current_status != status::number)
            {
                current_number = 0;
                current_status = status::number;
            }
            
            current_number *= 10;
            current_number += (new_char - '0');
			
			++current_index;
        }
        else if(new_char == '[')
        {
            if (current_status != status::number)
                throw std::runtime_error("bad format");
            
            int number_of_open_braces = 1;
			int in_brace_index = current_index + 1;
			
			while (in_brace_index < length)
			{
				if (aStr[in_brace_index] == '[')
					++number_of_open_braces;
				else if (aStr[in_brace_index] == ']')
				{
					--number_of_open_braces;
					if (number_of_open_braces == 0)
						break;
				}
				
				++in_brace_index;
			}
			
			if (number_of_open_braces != 0)
				throw std::runtime_error("bad format");
			
			std::string in_brace_string = decompress_document(aStr.substr(current_index + 1, in_brace_index - current_index - 1));
			for (int repeat_index = 0; repeat_index < current_number; ++repeat_index)
				result += in_brace_string;			

			current_index = in_brace_index + 1;
			current_status = status::start;
        }
		else
			throw std::runtime_error("bad format");
    }
	
	if (current_status == status::number)
		throw std::runtime_error("bad format");
    
    return result;
}

