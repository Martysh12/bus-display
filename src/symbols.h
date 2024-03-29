#ifndef SYMBOLS_H_
#define SYMBOLS_H_
#pragma once

#include <array>
#include <unordered_map>

#define SYM_WIDTH 12
#define SYM_HEIGHT 20

// Type used for centering the rows in draw.cpp
using SYM_ROW = std::array<bool, SYM_WIDTH>; 
// A bitmap for the given symbol
using SYM = std::array<SYM_ROW, SYM_HEIGHT>;

/* Bitmaps of all symbols */
extern const SYM SYM_ZERO;
extern const SYM SYM_ONE;
extern const SYM SYM_TWO;
extern const SYM SYM_THREE;
extern const SYM SYM_FOUR;
extern const SYM SYM_FIVE;
extern const SYM SYM_SIX;
extern const SYM SYM_SEVEN;
extern const SYM SYM_EIGHT;
extern const SYM SYM_NINE;
extern const SYM SYM_A_UPPER;
extern const SYM SYM_A_LOWER;
extern const SYM SYM_B_UPPER;
extern const SYM SYM_B_LOWER;
extern const SYM SYM_C_UPPER;
extern const SYM SYM_C_LOWER;
extern const SYM SYM_D_UPPER;
extern const SYM SYM_D_LOWER;
extern const SYM SYM_E_UPPER;
extern const SYM SYM_E_LOWER;
extern const SYM SYM_F_UPPER;
extern const SYM SYM_F_LOWER;
extern const SYM SYM_G_UPPER;
extern const SYM SYM_G_LOWER;
extern const SYM SYM_H_UPPER;
extern const SYM SYM_H_LOWER;
extern const SYM SYM_I_UPPER;
extern const SYM SYM_I_LOWER;
extern const SYM SYM_J_UPPER;
extern const SYM SYM_J_LOWER;
extern const SYM SYM_K_UPPER;
extern const SYM SYM_K_LOWER;
extern const SYM SYM_L_UPPER;
extern const SYM SYM_L_LOWER;
extern const SYM SYM_M_UPPER;
extern const SYM SYM_M_LOWER;
extern const SYM SYM_N_UPPER;
extern const SYM SYM_N_LOWER;
extern const SYM SYM_O_UPPER;
extern const SYM SYM_O_LOWER;
extern const SYM SYM_P_UPPER;
extern const SYM SYM_P_LOWER;
extern const SYM SYM_Q_UPPER;
extern const SYM SYM_Q_LOWER;
extern const SYM SYM_R_UPPER;
extern const SYM SYM_R_LOWER;
extern const SYM SYM_S_UPPER;
extern const SYM SYM_S_LOWER;
extern const SYM SYM_T_UPPER;
extern const SYM SYM_T_LOWER;
extern const SYM SYM_U_UPPER;
extern const SYM SYM_U_LOWER;
extern const SYM SYM_V_UPPER;
extern const SYM SYM_V_LOWER;
extern const SYM SYM_W_UPPER;
extern const SYM SYM_W_LOWER;
extern const SYM SYM_X_UPPER;
extern const SYM SYM_X_LOWER;
extern const SYM SYM_Y_UPPER;
extern const SYM SYM_Y_LOWER;
extern const SYM SYM_Z_UPPER;
extern const SYM SYM_Z_LOWER;
extern const SYM SYM_EXCM;
extern const SYM SYM_DQ;
extern const SYM SYM_HASH;
extern const SYM SYM_DLR;
extern const SYM SYM_PCENT;
extern const SYM SYM_QTE;
extern const SYM SYM_PTHS_LEFT;
extern const SYM SYM_PTHS_RIGHT;
extern const SYM SYM_STAR;
extern const SYM SYM_PLUS;
extern const SYM SYM_COMMA;
extern const SYM SYM_MINUS;
extern const SYM SYM_DOT;
extern const SYM SYM_SLASH;
extern const SYM SYM_COLON;
extern const SYM SYM_SCOLON;
extern const SYM SYM_LESS;
extern const SYM SYM_EQUAL;
extern const SYM SYM_GRTR;
extern const SYM SYM_QSTN;
extern const SYM SYM_AT;
extern const SYM SYM_SQR_LEFT;
extern const SYM SYM_BSLASH;
extern const SYM SYM_SQR_RIGHT;
extern const SYM SYM_CARET;
extern const SYM SYM_USCORE;
extern const SYM SYM_BTICK;
extern const SYM SYM_CRLY_LEFT;
extern const SYM SYM_BAR;
extern const SYM SYM_CRLY_RIGHT;
extern const SYM SYM_TILDE;
extern const SYM SYM_ERR_UNKNOWN;

extern std::unordered_map<char,SYM> SYMBOL_TABLE;

#endif /* ifndef SYMBOLS_H_ */