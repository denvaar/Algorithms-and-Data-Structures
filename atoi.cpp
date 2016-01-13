#include <iostream>
#include <stdlib.h>
#include <sstream>

int my_atoi(const char *str) {
    int value;
    std::stringstream ss(str);
    ss >> value;
    if (!ss) return 0;
    return value;
}

int main(int argc, char **argv) {
    
    // Implement atoi
    std::cout << "15a: " << atoi("15a") << std::endl;
    std::cout << "denver2: " << atoi("denver2") << std::endl;
    std::cout << "den22ver: " << atoi("den22ver") << std::endl;
    std::cout << "22denver: " << atoi("22denver") << std::endl;
    
    std::cout << "15a: " << my_atoi("15a") << std::endl;
    std::cout << "denver2: " << my_atoi("denver2") << std::endl;
    std::cout << "den22ver: " << my_atoi("den22ver") << std::endl;
    std::cout << "22denver: " << my_atoi("22denver") << std::endl;
    
    return 0;
}
