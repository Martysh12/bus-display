#include "draw.h"
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << stringify_disp_num(draw_disp_num(1234)) << std::endl;
    return 0;
}

