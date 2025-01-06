#include <iostream>
#include "utils.h"

int main(int argc, char* argv[]) {
    std::optional<Solution> solution = processArguments(argc, argv);

    if (!solution)
        return 1;
}
