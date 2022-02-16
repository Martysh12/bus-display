#include "draw.h"
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << stringify_disp_num(draw_disp_num(420)) << std::endl;
    return 0;
}

