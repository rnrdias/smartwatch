/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "fonts.h"

CONST UPP_BitmapFormat Font_numeric_24 = {
    0x0e,
    0x03,
    0x2d,
    0x0d,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, // .
        0x00, 0x00, 0x02, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, // /
        0x00, 0xfc, 0xfa, 0xf6, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0xf6, 0xfa, 0xfc, 0x00, 0x00, 0xef, 0xc7, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xc7, 0xef, 0x00, 0x00, 0x7f, 0xbf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xdf, 0xbf, 0x7f, 0x00, // 0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xc7, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x00, // 1
        0x00, 0x00, 0x02, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0xf6, 0xfa, 0xfc, 0x00, 0x00, 0xe0, 0xd0, 0xb8, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3b, 0x17, 0x0f, 0x00, 0x00, 0x7f, 0xbf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, // 2
        0x00, 0x00, 0x02, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0xf6, 0xfa, 0xfc, 0x00, 0x00, 0x00, 0x10, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xbb, 0xd7, 0xef, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xdf, 0xbf, 0x7f, 0x00, // 3
        0x00, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0x00, 0x00, 0x0f, 0x17, 0x3b, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xbb, 0xd7, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x00, // 4
        0x00, 0xfc, 0xfa, 0xf6, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x02, 0x00, 0x00, 0x00, 0x0f, 0x17, 0x3b, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xb8, 0xd0, 0xe0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xdf, 0xbf, 0x7f, 0x00, // 5
        0x00, 0xfc, 0xfa, 0xf6, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x02, 0x00, 0x00, 0x00, 0xef, 0xd7, 0xbb, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xb8, 0xd0, 0xe0, 0x00, 0x00, 0x7f, 0xbf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xdf, 0xbf, 0x7f, 0x00, // 6
        0x00, 0x00, 0x02, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0xf6, 0xfa, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xc7, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x00, // 7
        0x00, 0xfc, 0xfa, 0xf6, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0xf6, 0xfa, 0xfc, 0x00, 0x00, 0xef, 0xd7, 0xbb, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xbb, 0xd7, 0xef, 0x00, 0x00, 0x7f, 0xbf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xdf, 0xbf, 0x7f, 0x00, // 8
        0x00, 0xfc, 0xfa, 0xf6, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0xf6, 0xfa, 0xfc, 0x00, 0x00, 0x0f, 0x17, 0x3b, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xbb, 0xd7, 0xef, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xdf, 0xbf, 0x7f, 0x00, // 9
    },
};