#include "draw.h"

/**
 * Convert character into pixel representation.
 *
 * Convert character c into a pixel representation.
 *
 * @param c The character to draw
 * @return 2D std::array of bool representing character c
 */
SYM get_symbol_from_char(char c)
{
    // Big switch-case to check all characters
    // NOTE: This might not be the most efficient way
    switch (c)
    {
        case '0':
            return SYM_ZERO;
        case '1':
            return SYM_ONE;
        case '2':
            return SYM_TWO;
        case '3':
            return SYM_THREE;
        case '4':
            return SYM_FOUR;
        case '5':
            return SYM_FIVE;
        case '6':
            return SYM_SIX;
        case '7':
            return SYM_SEVEN;
        case '8':
            return SYM_EIGHT;
        case '9':
            return SYM_NINE;
        case 'A':
            return SYM_A_UPPER;
        case 'a':
            return SYM_A_LOWER;
        case 'B':
            return SYM_B_UPPER;
        case 'b':
            return SYM_B_LOWER;
        case 'C':
            return SYM_C_UPPER;
        case 'c':
            return SYM_C_LOWER;
        case 'D':
            return SYM_D_UPPER;
        case 'd':
            return SYM_D_LOWER;
        case 'E':
            return SYM_E_UPPER;
        case 'e':
            return SYM_E_LOWER;
        case 'F':
            return SYM_F_UPPER;
        case 'f':
            return SYM_F_LOWER;
        case 'G':
            return SYM_G_UPPER;
        case 'g':
            return SYM_G_LOWER;
        case 'H':
            return SYM_H_UPPER;
        case 'h':
            return SYM_H_LOWER;
        case 'I':
            return SYM_I_UPPER;
        case 'i':
            return SYM_I_LOWER;
        case 'J':
            return SYM_J_UPPER;
        case 'j':
            return SYM_J_LOWER;
        case 'K':
            return SYM_K_UPPER;
        case 'k':
            return SYM_K_LOWER;
        case 'L':
            return SYM_L_UPPER;
        case 'l':
            return SYM_L_LOWER;
        case 'M':
            return SYM_M_UPPER;
        case 'm':
            return SYM_M_LOWER;
        case 'N':
            return SYM_N_UPPER;
        case 'n':
            return SYM_N_LOWER;
        case 'O':
            return SYM_O_UPPER;
        case 'o':
            return SYM_O_LOWER;
        case 'P':
            return SYM_P_UPPER;
        case 'p':
            return SYM_P_LOWER;
        case 'Q':
            return SYM_Q_UPPER;
        case 'q':
            return SYM_Q_LOWER;
        case 'R':
            return SYM_R_UPPER;
        case 'r':
            return SYM_R_LOWER;
        case 'S':
            return SYM_S_UPPER;
        case 's':
            return SYM_S_LOWER;
        case 'T':
            return SYM_T_UPPER;
        case 't':
            return SYM_T_LOWER;
        case 'U':
            return SYM_U_UPPER;
        case 'u':
            return SYM_U_LOWER;
        case 'V':
            return SYM_V_UPPER;
        case 'v':
            return SYM_V_LOWER;
        case 'W':
            return SYM_W_UPPER;
        case 'w':
            return SYM_W_LOWER;
        case 'X':
            return SYM_X_UPPER;
        case 'x':
            return SYM_X_LOWER;
        case 'Y':
            return SYM_Y_UPPER;
        case 'y':
            return SYM_Y_LOWER;
        case 'Z':
            return SYM_Z_UPPER;
        case 'z':
            return SYM_Z_LOWER;
        case '!':
            return SYM_EXCM;
        case '"':
            return SYM_DQ;
        case '#':
            return SYM_HASH;
        case '$':
            return SYM_DLR;
        case '%':
            return SYM_PCENT;
        case '\'':
            return SYM_QTE;
        case '(':
            return SYM_PTHS_LEFT;
        case ')':
            return SYM_PTHS_RIGHT;
        case '*':
            return SYM_STAR;
        case '+':
            return SYM_PLUS;
        case ',':
            return SYM_COMMA;
        case '-':
            return SYM_MINUS;
        case '.':
            return SYM_DOT;
        case '/':
            return SYM_SLASH;
        case ':':
            return SYM_COLON;
        case ';':
            return SYM_SCOLON;
        case '<':
            return SYM_LESS;
        case '=':
            return SYM_EQUAL;
        case '>':
            return SYM_GRTR;
        case '?':
            return SYM_QSTN;
        case '@':
            return SYM_AT;
        case '[':
            return SYM_SQR_LEFT;
        case '\\':
            return SYM_BSLASH;
        case ']':
            return SYM_SQR_RIGHT;
        case '^':
            return SYM_CARET;
        case '_':
            return SYM_USCORE;
        case '`':
            return SYM_BTICK;
        case '{':
            return SYM_CRLY_LEFT;
        case '|':
            return SYM_BAR;
        case '}':
            return SYM_CRLY_RIGHT;
        case '~':
            return SYM_TILDE;
        default:
            return SYM_ERR_UNKNOWN;
    }
}

/**
 * Join and center symbol rows.
 *
 * Join all elements of rows (delimited by ' '), center them, and return them.
 *
 * @param rows The rows to join & center
 * @return Big row consisting of joined & centered rows
 */
DISP_NUM_ROW disp_num_center_rows(std::vector<SYM_ROW> rows)
{
    int padding_l = (DISP_NUM_WIDTH - (SYM_WIDTH * rows.size() + rows.size())) / 2;
 
    std::vector<bool> joined_rows {};
    joined_rows.reserve((rows.size() * SYM_WIDTH) + rows.size() - 1);
    
    for (unsigned int i = 0; i < rows.size(); ++i)
    {
        joined_rows.insert(joined_rows.end(), rows[i].begin(), rows[i].end());

        if (i != rows.size() - 1)
        {
            joined_rows.insert(joined_rows.end(), false);
        }
    }

    DISP_NUM_ROW final_row {};
    
    // Copying vector to our final row
    for (unsigned int i = 0; i < joined_rows.size(); ++i)
    {
        // very smart padding trick :bigbrain:
        final_row[i + padding_l] = joined_rows[i];
    }

    return final_row;
}

/**
 * Draw number bus_num onto a 2D pixel matrix.
 *
 * Draws number bus_num, and centers it on a 2D pixel matrix.
 * Used for drawing the number-only displays on buses.
 *
 * @param bus_num The number to draw
 * @return The finished 2D pixel matrix.
 */
DISP_NUM draw_disp_num(int bus_num)
{
    if (bus_num < 0 || bus_num >= 1000) {
        // Displaying negative bus numbers is possible, because we're converting the int to a std::string.
        // You could theoretically remove the check, but... why?
        
        return DISP_NUM {}; // Returning empty display to symbolize that you fucked up
    }

    std::string digits = std::to_string(bus_num);

    std::vector<SYM> symbols {}; // Empty vector for storing symbols

    // Populating vector with true/false symbols
    for (const auto& c : digits)
    {
        symbols.push_back(get_symbol_from_char(c));
    }
    
    DISP_NUM display {}; // yeah... make sure to include the braces, or you'll get a random memory thing.
    
    for (int i = 0; i < SYM_HEIGHT; ++i)
    {
        std::vector<SYM_ROW> to_center {};

        for (const auto& s : symbols)
        {
            to_center.push_back(s[i]);
        }

        display[i] = disp_num_center_rows(to_center);
    }

    return display;
}

/**
 * Draw number bus_num and string bus_desc onto a 2D pixel matrix.
 *
 * Draws number bus_num on the leftmost side, and draws string bus_desc.
 * Used for drawing the number-and-description displays on buses.
 *
 * @param bus_num The number to draw
 * @param bus_desc The text to draw
 * @return The finished 2D pixel matrix.
 */
DISP_SIDE draw_disp_side(int bus_num, std::string bus_desc)
{
    // TODO: Displaying advanced infromation (bus description, etc.) with a scrolling effect.
    return DISP_SIDE {};
}

// TODO: Following functions are for debug. Remove it after debugging.

/**
 * Convert 2D pixel matrix into a printable string.
 *
 * Convert 2D pixel matrix into a printable string
 * that can be displayed directly in the terminal.
 *
 * @param disp The 2D pixel matrix
 * @return Printable string representation of the 2D pixel matrix
 */
std::string stringify_disp_num(DISP_NUM disp)
{
    std::string buf;
    
    // Iterating over 2D array.
    for (const auto& y : disp)
    {
        for (const auto& x : y)
        {
            buf += x ? "##" : ".."; // 2 characters make a square
        }

        buf += '\n';
    }

    return buf;
}

/**
 * Convert 2D pixel matrix into a printable string.
 *
 * Convert 2D pixel matrix into a printable string
 * that can be displayed directly in the terminal.
 *
 * @param disp The 2D pixel matrix
 * @return Printable string representation of the 2D pixel matrix
 */
std::string stringify_disp_side(DISP_SIDE disp)
{
    std::string buf;
    
    for (const auto& y : disp)
    {
        for (const auto& x : y)
        {
            buf += x ? "##" : "..";
        }

        buf += '\n';
    }

    return buf;
}

