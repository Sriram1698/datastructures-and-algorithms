#include <iostream>
#include <string>

using std::string;

bool isPalindrome(string str) 
{
    if (str.length() <= 1){return true;}
    return (str[0] == str[str.length()-1]) && isPalindrome(str.substr(1, str.length()-2));
}

int main() {
  string str = "abacaba";
  std::cout << isPalindrome(str) << std::endl;
  return EXIT_SUCCESS;
}
