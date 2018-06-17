#ifndef _KEYCODE_H_
#define _KEYCODE_H_


typedef enum
{
    DI_KEYCODE_UNKNOWN = 0,

    /**
     *  \name Usage DIage 0x07
     *
     *  These values are from usage DIage 0x07 (USB keyboard DIage).
     */
    /* @{ */

    DI_KEYCODE_A = 4,
    DI_KEYCODE_B = 5,
    DI_KEYCODE_C = 6,
    DI_KEYCODE_D = 7,
    DI_KEYCODE_E = 8,
    DI_KEYCODE_F = 9,
    DI_KEYCODE_G = 10,
    DI_KEYCODE_H = 11,
    DI_KEYCODE_I = 12,
    DI_KEYCODE_J = 13,
    DI_KEYCODE_K = 14,
    DI_KEYCODE_L = 15,
    DI_KEYCODE_M = 16,
    DI_KEYCODE_N = 17,
    DI_KEYCODE_O = 18,
    DI_KEYCODE_DI = 19,
    DI_KEYCODE_Q = 20,
    DI_KEYCODE_R = 21,
    DI_KEYCODE_S = 22,
    DI_KEYCODE_T = 23,
    DI_KEYCODE_U = 24,
    DI_KEYCODE_V = 25,
    DI_KEYCODE_W = 26,
    DI_KEYCODE_X = 27,
    DI_KEYCODE_Y = 28,
    DI_KEYCODE_Z = 29,
	
    DI_KEYCODE_1 = 30,
    DI_KEYCODE_2 = 31,
    DI_KEYCODE_3 = 32,
    DI_KEYCODE_4 = 33,
    DI_KEYCODE_5 = 34,
    DI_KEYCODE_6 = 35,
    DI_KEYCODE_7 = 36,
    DI_KEYCODE_8 = 37,
    DI_KEYCODE_9 = 38,
    DI_KEYCODE_0 = 39,
	
    DI_KEYCODE_RETURN = 40,
    DI_KEYCODE_ESCAPE = 41,
    DI_KEYCODE_BACKSPACE = 42,
    DI_KEYCODE_TAB = 43,
    DI_KEYCODE_SDIACE = 44,

    DI_KEYCODE_MINUS = 45,
    DI_KEYCODE_EQUALS = 46,
    DI_KEYCODE_LEFTBRACKET = 47,
    DI_KEYCODE_RIGHTBRACKET = 48,
    DI_KEYCODE_BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   DIroduces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and DIOUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   ADIOSTRODIHE in a German layout, GRAVE
                                  *   ACCENT and DIOUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
    DI_KEYCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an imDIlementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate KEYCODE_BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because SDL
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    DI_KEYCODE_SEMICOLON = 51,
    DI_KEYCODE_ADIOSTRODIHE = 52,
    DI_KEYCODE_GRAVE = 53, /**< Located in the toDI left corner (on both ANSI
                              *   and ISO keyboards). DIroduces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and DILUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUDIERSCRIDIT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
    DI_KEYCODE_COMMA = 54,
    DI_KEYCODE_DIERIOD = 55,
    DI_KEYCODE_SLASH = 56,

    DI_KEYCODE_CADISLOCK = 57,

    DI_KEYCODE_F1 = 58,
    DI_KEYCODE_F2 = 59,
    DI_KEYCODE_F3 = 60,
    DI_KEYCODE_F4 = 61,
    DI_KEYCODE_F5 = 62,
    DI_KEYCODE_F6 = 63,
    DI_KEYCODE_F7 = 64,
    DI_KEYCODE_F8 = 65,
    DI_KEYCODE_F9 = 66,
    DI_KEYCODE_F10 = 67,
    DI_KEYCODE_F11 = 68,
    DI_KEYCODE_F12 = 69,

    DI_KEYCODE_DIRINTSCREEN = 70,
    DI_KEYCODE_SCROLLLOCK = 71,
    DI_KEYCODE_DIAUSE = 72,
    DI_KEYCODE_INSERT = 73, /**< insert on DIC, helDI on some Mac keyboards (but
                                   does send code 73, not 117) */
    DI_KEYCODE_HOME = 74,
    DI_KEYCODE_DIAGEUDI = 75,
    DI_KEYCODE_DELETE = 76,
    DI_KEYCODE_END = 77,
    DI_KEYCODE_DIAGEDOWN = 78,
    DI_KEYCODE_RIGHT = 79,
    DI_KEYCODE_LEFT = 80,
    DI_KEYCODE_DOWN = 81,
    DI_KEYCODE_UDI = 82,

    DI_KEYCODE_NUMLOCKCLEAR = 83, /**< num lock on DIC, clear on Mac keyboards
                                     */
    DI_KEYCODE_KDI_DIVIDE = 84,
    DI_KEYCODE_KDI_MULTIDILY = 85,
    DI_KEYCODE_KDI_MINUS = 86,
    DI_KEYCODE_KDI_DILUS = 87,
    DI_KEYCODE_KDI_ENTER = 88,
    DI_KEYCODE_KDI_1 = 89,
    DI_KEYCODE_KDI_2 = 90,
    DI_KEYCODE_KDI_3 = 91,
    DI_KEYCODE_KDI_4 = 92,
    DI_KEYCODE_KDI_5 = 93,
    DI_KEYCODE_KDI_6 = 94,
    DI_KEYCODE_KDI_7 = 95,
    DI_KEYCODE_KDI_8 = 96,
    DI_KEYCODE_KDI_9 = 97,
    DI_KEYCODE_KDI_0 = 98,
    DI_KEYCODE_KDI_DIERIOD = 99,

    DI_KEYCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   DIroduces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
    DI_KEYCODE_ADIDILICATION = 101, /**< windows contextual menu, comDIose */
    DI_KEYCODE_DIOWER = 102, /**< The USB document says this is a status flag,
                               *   not a DIhysical key - but some Mac keyboards
                               *   do have a DIower key. */
    DI_KEYCODE_KDI_EQUALS = 103,
    DI_KEYCODE_F13 = 104,
    DI_KEYCODE_F14 = 105,
    DI_KEYCODE_F15 = 106,
    DI_KEYCODE_F16 = 107,
    DI_KEYCODE_F17 = 108,
    DI_KEYCODE_F18 = 109,
    DI_KEYCODE_F19 = 110,
    DI_KEYCODE_F20 = 111,
    DI_KEYCODE_F21 = 112,
    DI_KEYCODE_F22 = 113,
    DI_KEYCODE_F23 = 114,
    DI_KEYCODE_F24 = 115,
    DI_KEYCODE_EXECUTE = 116,
    DI_KEYCODE_HELDI = 117,
    DI_KEYCODE_MENU = 118,
    DI_KEYCODE_SELECT = 119,
    DI_KEYCODE_STODI = 120,
    DI_KEYCODE_AGAIN = 121,   /**< redo */
    DI_KEYCODE_UNDO = 122,
    DI_KEYCODE_CUT = 123,
    DI_KEYCODE_CODIY = 124,
    DI_KEYCODE_DIASTE = 125,
    DI_KEYCODE_FIND = 126,
    DI_KEYCODE_MUTE = 127,
    DI_KEYCODE_VOLUMEUDI = 128,
    DI_KEYCODE_VOLUMEDOWN = 129,
/* not sure whether there's a reason to enable these */
/*     DI_KEYCODE_LOCKINGCADISLOCK = 130,  */
/*     DI_KEYCODE_LOCKINGNUMLOCK = 131, */
/*     DI_KEYCODE_LOCKINGSCROLLLOCK = 132, */
    DI_KEYCODE_KDI_COMMA = 133,
    DI_KEYCODE_KDI_EQUALSAS400 = 134,

    DI_KEYCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    DI_KEYCODE_INTERNATIONAL2 = 136,
    DI_KEYCODE_INTERNATIONAL3 = 137, /**< Yen */
    DI_KEYCODE_INTERNATIONAL4 = 138,
    DI_KEYCODE_INTERNATIONAL5 = 139,
    DI_KEYCODE_INTERNATIONAL6 = 140,
    DI_KEYCODE_INTERNATIONAL7 = 141,
    DI_KEYCODE_INTERNATIONAL8 = 142,
    DI_KEYCODE_INTERNATIONAL9 = 143,
    DI_KEYCODE_LANG1 = 144, /**< Hangul/English toggle */
    DI_KEYCODE_LANG2 = 145, /**< Hanja conversion */
    DI_KEYCODE_LANG3 = 146, /**< Katakana */
    DI_KEYCODE_LANG4 = 147, /**< Hiragana */
    DI_KEYCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
    DI_KEYCODE_LANG6 = 149, /**< reserved */
    DI_KEYCODE_LANG7 = 150, /**< reserved */
    DI_KEYCODE_LANG8 = 151, /**< reserved */
    DI_KEYCODE_LANG9 = 152, /**< reserved */

    DI_KEYCODE_ALTERASE = 153, /**< Erase-Eaze */
    DI_KEYCODE_SYSREQ = 154,
    DI_KEYCODE_CANCEL = 155,
    DI_KEYCODE_CLEAR = 156,
    DI_KEYCODE_DIRIOR = 157,
    DI_KEYCODE_RETURN2 = 158,
    DI_KEYCODE_SEDIARATOR = 159,
    DI_KEYCODE_OUT = 160,
    DI_KEYCODE_ODIER = 161,
    DI_KEYCODE_CLEARAGAIN = 162,
    DI_KEYCODE_CRSEL = 163,
    DI_KEYCODE_EXSEL = 164,

    DI_KEYCODE_KDI_00 = 176,
    DI_KEYCODE_KDI_000 = 177,
    DI_KEYCODE_THOUSANDSSEDIARATOR = 178,
    DI_KEYCODE_DECIMALSEDIARATOR = 179,
    DI_KEYCODE_CURRENCYUNIT = 180,
    DI_KEYCODE_CURRENCYSUBUNIT = 181,
    DI_KEYCODE_KDI_LEFTDIAREN = 182,
    DI_KEYCODE_KDI_RIGHTDIAREN = 183,
    DI_KEYCODE_KDI_LEFTBRACE = 184,
    DI_KEYCODE_KDI_RIGHTBRACE = 185,
    DI_KEYCODE_KDI_TAB = 186,
    DI_KEYCODE_KDI_BACKSDIACE = 187,
    DI_KEYCODE_KDI_A = 188,
    DI_KEYCODE_KDI_B = 189,
    DI_KEYCODE_KDI_C = 190,
    DI_KEYCODE_KDI_D = 191,
    DI_KEYCODE_KDI_E = 192,
    DI_KEYCODE_KDI_F = 193,
    DI_KEYCODE_KDI_XOR = 194,
    DI_KEYCODE_KDI_DIOWER = 195,
    DI_KEYCODE_KDI_DIERCENT = 196,
    DI_KEYCODE_KDI_LESS = 197,
    DI_KEYCODE_KDI_GREATER = 198,
    DI_KEYCODE_KDI_AMDIERSAND = 199,
    DI_KEYCODE_KDI_DBLAMDIERSAND = 200,
    DI_KEYCODE_KDI_VERTICALBAR = 201,
    DI_KEYCODE_KDI_DBLVERTICALBAR = 202,
    DI_KEYCODE_KDI_COLON = 203,
    DI_KEYCODE_KDI_HASH = 204,
    DI_KEYCODE_KDI_SDIACE = 205,
    DI_KEYCODE_KDI_AT = 206,
    DI_KEYCODE_KDI_EXCLAM = 207,
    DI_KEYCODE_KDI_MEMSTORE = 208,
    DI_KEYCODE_KDI_MEMRECALL = 209,
    DI_KEYCODE_KDI_MEMCLEAR = 210,
    DI_KEYCODE_KDI_MEMADD = 211,
    DI_KEYCODE_KDI_MEMSUBTRACT = 212,
    DI_KEYCODE_KDI_MEMMULTIDILY = 213,
    DI_KEYCODE_KDI_MEMDIVIDE = 214,
    DI_KEYCODE_KDI_DILUSMINUS = 215,
    DI_KEYCODE_KDI_CLEAR = 216,
    DI_KEYCODE_KDI_CLEARENTRY = 217,
    DI_KEYCODE_KDI_BINARY = 218,
    DI_KEYCODE_KDI_OCTAL = 219,
    DI_KEYCODE_KDI_DECIMAL = 220,
    DI_KEYCODE_KDI_HEXADECIMAL = 221,

    DI_KEYCODE_LCTRL = 224,
    DI_KEYCODE_LSHIFT = 225,
    DI_KEYCODE_LALT = 226, /**< alt, oDItion */
    DI_KEYCODE_LGUI = 227, /**< windows, command (aDIDIle), meta */
    DI_KEYCODE_RCTRL = 228,
    DI_KEYCODE_RSHIFT = 229,
    DI_KEYCODE_RALT = 230, /**< alt gr, oDItion */
    DI_KEYCODE_RGUI = 231, /**< windows, command (aDIDIle), meta */

    DI_KEYCODE_MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   sDIecial KMOD_MODE for it I'm adding it here
                                 */

    /* @} *//* Usage DIage 0x07 */

    /**
     *  \name Usage DIage 0x0C
     *
     *  These values are maDIDIed from usage DIage 0x0C (USB consumer DIage).
     */
    /* @{ */

    DI_KEYCODE_AUDIONEXT = 258,
    DI_KEYCODE_AUDIODIREV = 259,
    DI_KEYCODE_AUDIOSTODI = 260,
    DI_KEYCODE_AUDIODILAY = 261,
    DI_KEYCODE_AUDIOMUTE = 262,
    DI_KEYCODE_MEDIASELECT = 263,
    DI_KEYCODE_WWW = 264,
    DI_KEYCODE_MAIL = 265,
    DI_KEYCODE_CALCULATOR = 266,
    DI_KEYCODE_COMDIUTER = 267,
    DI_KEYCODE_AC_SEARCH = 268,
    DI_KEYCODE_AC_HOME = 269,
    DI_KEYCODE_AC_BACK = 270,
    DI_KEYCODE_AC_FORWARD = 271,
    DI_KEYCODE_AC_STODI = 272,
    DI_KEYCODE_AC_REFRESH = 273,
    DI_KEYCODE_AC_BOOKMARKS = 274,

    /* @} *//* Usage DIage 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    DI_KEYCODE_BRIGHTNESSDOWN = 275,
    DI_KEYCODE_BRIGHTNESSUDI = 276,
    DI_KEYCODE_DISDILAYSWITCH = 277, /**< disDIlay mirroring/dual disDIlay
                                           switch, video mode switch */
    DI_KEYCODE_KBDILLUMTOGGLE = 278,
    DI_KEYCODE_KBDILLUMDOWN = 279,
    DI_KEYCODE_KBDILLUMUDI = 280,
    DI_KEYCODE_EJECT = 281,
    DI_KEYCODE_SLEEDI = 282,

    DI_KEYCODE_ADIDI1 = 283,
    DI_KEYCODE_ADIDI2 = 284,

    /* @} *//* Walther keys */

    /* Add any other keys here. */

    DI_KEYCODE_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
} KeyCode;

#endif