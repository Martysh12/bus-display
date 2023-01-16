#include "draw.h"
#include <iostream>

// TODO: Program takes quite a while to run. Optimize it.

// Takes one argument (number) and displays it.
// TODO: remove afterwards since this is for debugging
int main(int argc, char* argv[])
{
    if(argc == 1) return 0;

    int display_number = 0;
    try {
        display_number = std::stoi(std::string(argv[1]));
    }
    catch(...) { return 0; }

    std::cout << stringify_disp_num(draw_disp_num(display_number)) << std::endl;
    return 0;
}

