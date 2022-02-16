#pragma once

#include "symbols.h"

#include <array>
#include <string>
#include <vector>

/* CONSTANTS */

constexpr int DISP_NUM_WIDTH   = 39; // FIXME: Setting width to 38 (which is the correct width, 3 characters) causes crash
constexpr int DISP_NUM_HEIGHT  = 20;

constexpr int DISP_SIDE_WIDTH  = 104;
constexpr int DISP_SIDE_HEIGHT = 20;

/* ========= */

/* TYPEDEFS */

typedef std::array<bool, DISP_NUM_WIDTH > DISP_NUM_ROW;
typedef std::array<bool, DISP_SIDE_WIDTH> DISP_SIDE_ROW;

typedef std::array<DISP_NUM_ROW , DISP_NUM_HEIGHT> DISP_NUM;
typedef std::array<DISP_SIDE_ROW, DISP_SIDE_HEIGHT> DISP_SIDE;

/* ======== */

DISP_NUM draw_disp_num(int);
DISP_SIDE draw_disp_side(int, std::string);

// TODO: Following functions are for debug. Remove them after debugging.
std::string stringify_disp_num(DISP_NUM);
std::string stringify_disp_side(DISP_SIDE);

