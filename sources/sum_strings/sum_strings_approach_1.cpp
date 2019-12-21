long sum_two_strings(std::string str1, std::string str2, int base) {
  long num1, num2, result;
  if(base == 1){return str1.size() + str2.size();}
  num1 = std::stol(str1, nullptr, base);
  num2 = std::stol(str2, nullptr, base); // exception is thrown if number greater than range of long
  result = num1 + num2;
  if(base == 10) return result;
  auto convert_result_to_base = [ & ]() {
    int i = 0;
    long converted_result = 0;
    while (result > 0) {
      int num = result % base;
      result = result / base;
      (i == 0) ? (converted_result = num) : (converted_result = converted_result + num * std::pow(10, i));
      i++;
    }
    return converted_result;
  };
  return convert_result_to_base();
}