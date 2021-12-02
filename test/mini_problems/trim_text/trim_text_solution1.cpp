#include <cctype>

template <typename Fn>
void skip_if(const std::string& msg, int& pos, Fn fn)
{
  while (pos >= 0 && fn(msg[pos]))
  {
    pos--;
  }
}

std::string trim_text_lineartime(const std::string& message, const size_t K)
{
  int pos = message.size() - 1;
  while (pos >= 0)
  {
    skip_if(message, pos, [](const auto& c) { return std::isspace(c); });
    if ((pos + 1) <= K)
      break;
    skip_if(message, pos, [](const auto& c) { return std::isalnum(c); });
  }
  return message.substr(0, pos + 1);
}