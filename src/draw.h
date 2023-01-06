#ifndef DRAW_H_
#define DRAW_H_
#pragma once

#include "symbols.h"

#include <array>
#include <string>
#include <vector>

/* CONSTANTS */

#define DISP_NUM_WIDTH 39 // FIXME: Setting width to 38 (which is the correct width, 3 characters) causes crash
#define DISP_NUM_HEIGHT 20

#define DISP_SIDE_WIDTH 104
#define DISP_SIDE_HEIGHT 20

/* ========= */

/* USINGS */

using DISP_NUM_ROW = std::array<bool, DISP_NUM_WIDTH>;
using DISP_SIDE_ROW = std::array<bool, DISP_SIDE_WIDTH>;

using DISP_NUM = std::array<DISP_NUM_ROW , DISP_NUM_HEIGHT>;
using DISP_SIDE = std::array<DISP_SIDE_ROW, DISP_SIDE_HEIGHT>;

/* ======== */

DISP_NUM draw_disp_num(int);
DISP_SIDE draw_disp_side(int, std::string);

// TODO: Following functions are for debug. Remove them after debugging.
std::string stringify_disp_num(DISP_NUM);
std::string stringify_disp_side(DISP_SIDE);

#endif /* ifndef DRAW_H_ */