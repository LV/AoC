#include <format>
#include <stdexcept>
#include <string>
#include <vector>

class Solution {
private:
    unsigned int year;
    unsigned int day;
    unsigned int part;

public:
    // utils::processArguments() validates the input parameters already
    Solution(unsigned int year, unsigned int day, unsigned int part) 
        : year(year), day(day), part(part) {}

    std::string getStringInput();
    std::vector<std::string> getVectorInput();
};
