#include "draw.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // Program takes quite a while to run... Gotta optimize it.
    std::cout << stringify_disp_num(draw_disp_num(21)) << std::endl;
    return 0;
}

