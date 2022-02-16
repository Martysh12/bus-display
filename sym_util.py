from PIL import Image, ImageGrab
import pyperclip

syms = [
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE",

    "A_UPPER",
    "A_LOWER",

    "B_UPPER",
    "B_LOWER",

    "C_UPPER",
    "C_LOWER",

    "D_UPPER",
    "D_LOWER",

    "E_UPPER",
    "E_LOWER",

    "F_UPPER",
    "F_LOWER",

    "G_UPPER",
    "G_LOWER",

    "H_UPPER",
    "H_LOWER",

    "I_UPPER",
    "I_LOWER",

    "J_UPPER",
    "J_LOWER",

    "K_UPPER",
    "K_LOWER",

    "L_UPPER",
    "L_LOWER",

    "M_UPPER",
    "M_LOWER",

    "N_UPPER",
    "N_LOWER",

    "O_UPPER",
    "O_LOWER",

    "P_UPPER",
    "P_LOWER",

    "Q_UPPER",
    "Q_LOWER",

    "R_UPPER",
    "R_LOWER",

    "S_UPPER",
    "S_LOWER",

    "T_UPPER",
    "T_LOWER",

    "U_UPPER",
    "U_LOWER",

    "V_UPPER",
    "V_LOWER",

    "W_UPPER",
    "W_LOWER",

    "X_UPPER",
    "X_LOWER",

    "Y_UPPER",
    "Y_LOWER",

    "Z_UPPER",
    "Z_LOWER",

    "EXCM",
    "DQ",
    "HASH",
    "DLR",
    "PCENT",
    "QTE",
    "PTHS_LEFT",
    "PTHS_RIGHT",
    "STAR",
    "PLUS",
    "COMMA",
    "MINUS",
    "DOT",
    "SLASH",
    "COLON",
    "SCOLON",
    "LESS",
    "EQUAL",
    "GRTR",
    "QSTN",
    "AT",
    "SQR_LEFT",
    "BSLASH",
    "SQR_RIGHT",
    "CARET",
    "USCORE",
    "BTICK",
    "CRLY_LEFT",
    "BAR",
    "CRLY_RIGHT",
    "TILDE",
    "ERR_UNKNOWN"
]

do_extern = True if input("Create extern? (yes/no) ").lower() == "yes" else False

if do_extern:
    cpp_code = ""

    for i in syms:
        cpp_code += f"extern const SYM SYM_{i};\n"

    print(cpp_code)
    pyperclip.copy(cpp_code)
else:
    im = ImageGrab.grabclipboard()

    if im is None:
        exit(1)

    def create_snippet(sym_img, var_name):
        cpp_code = f"const SYM SYM_{var_name} {{{{\n"

        for y in range(sym_img.size[1]):
            cpp_code += "    {{"
            for x in range(sym_img.size[0]):
                if sym_img.getpixel((x, y)) == (0, 0, 0):
                    cpp_code += "true , "
                else:
                    cpp_code += "false, "

            cpp_code = cpp_code[:-2]
            cpp_code += "}},\n"

        cpp_code = cpp_code[:-2] + "\n}};"

        return cpp_code

    GRID_W = 10
    GRID_H = 10

    SYM_W = 12
    SYM_H = 20

    SEP_X = 1
    SEP_Y = 1

    codes = []

    stop = False
    i = 0
    for y in range(GRID_H):
        if stop:
            break

        for x in range(GRID_W):
            left = x * SYM_W + x * SEP_X
            top =  y * SYM_H + y * SEP_Y

            width  = left + SYM_W
            height = top  + SYM_H

            new_im = im.crop((left, top, width, height))

            codes.append(create_snippet(new_im, syms[i]))

            i += 1

            if i == len(syms):
                stop = True
                break

    finished_code = "\n\n".join(codes)

    print(finished_code)
    pyperclip.copy(finished_code)
