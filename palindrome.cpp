#include <string>
#include <iostream>

bool isPalindrome(std::string str) {
    
    std::string strBackward = str;
    std::reverse(strBackward.begin(), strBackward.end());
    
    return str.compare(strBackward);
}

//#include <string>
//#include <iostream>

int main(int argc, char **argv) {

    if (isPalindrome(argv[1]) == 0)
        std::cout << argv[1] << " is a palindrome." << std::endl;
    else std::cout << argv[1] << " is not a palindrome." << std::endl;

    return 0;
}
