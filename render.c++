#include "render.h"


std::string GenerateTabs(unsigned int tabs) {
    std::string returnString = "";
    std::string tabString = "\t";
    for (int i = 0; i < tabs; i++) {
        returnString.append(tabString);
    }
    // std::cout << returnString << std::endl;
    return returnString;
}