#include "draw.h"

/**
 * Convert character into pixel representation.
 *
 * Convert character c into a pixel representation.
 *
 * @param c The character to draw
 * @return 2D std::array of bfalsel representing character c
 */
SYM get_symbol_from_char(char c)
{
    if(SYMBOL_TABLE.count(c) == 0) return SYM_ERR_UNKNOWN;
    return SYMBOL_TABLE[c];
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
    
    for (size_t i = 0; i < rows.size(); ++i)
    {
        joined_rows.insert(joined_rows.end(), rows[i].begin(), rows[i].end());

        if (i != rows.size() - 1)
        {
            joined_rows.insert(joined_rows.end(), false);
        }
    }

    DISP_NUM_ROW final_row {};
    
    // Copying vector to our final row
    for (size_t i = 0; i < joined_rows.size(); ++i)
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
    
    DISP_NUM display {}; // yeah... make sure to include the braces, or you'll get uninizialized memory.
    
    for (size_t i = 0; i < SYM_HEIGHT; ++i)
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

// TODO: Following functions are for debugging. Remove it once done.

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

