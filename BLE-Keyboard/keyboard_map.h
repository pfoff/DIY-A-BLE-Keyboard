#include <stdint.h>
#include "keycode.h"

// This part was adpated to Apple //c Keyboard, which has a 14x5 matrix
#define KEYBOARD_NUM_OF_COLUMNS 10 // !< Number of columns in the keyboard matrix
#define KEYBOARD_NUM_OF_ROWS    8  // !< Number of rows in the keyboard matrix

static const uint8_t row_pin_array[KEYBOARD_NUM_OF_ROWS] = {10,11,12,13,14,15,16,17};
static const uint8_t column_pin_array[KEYBOARD_NUM_OF_COLUMNS] = {0,1,2,3,4,5,6,7,8,9};

static const uint8_t wakeup_button_row_index = 2;			//select row_pin_array[2] = 21
static const uint8_t wakeup_button_column_index = 1;	//select column_pin_array[1] = 2 
//wakeup button is default_matrix_lookup[2][1] = 0x29 and it's ESC key

/** Table containing the mapping between the key matrix and the HID Usage codes for each key. */
static const uint8_t default_matrix_lookup[KEYBOARD_NUM_OF_COLUMNS * KEYBOARD_NUM_OF_ROWS] =
{
/*		X0		1		2		3		4		5		6		7		8		9   */
/*0*/		KC_ESCAPE,	KC_1,		KC_2,		KC_3,		KC_4,		KC_6,		KC_5,		KC_7,		KC_8,		KC_9,
/*1*/		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_Y,		KC_T,		KC_U,		KC_I,		KC_O,
/*2*/		KC_A,		KC_D,		KC_S,		KC_H,		KC_F,		KC_G,		KC_J,		KC_K,		KC_SCOLON,	KC_L,
/*3*/		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMMA,	KC_DOT,		KC_SLASH,
/*4*/		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_BSLASH,	KC_EQUAL,	KC_0,		KC_MINUS,
/*5*/		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_GRAVE,	KC_P,		KC_LBRACKET,	KC_RBRACKET,
/*6*/		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_RETURN,	KC_UP,		KC_SPACE,	KC_QUOT,
/*7*/		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_BSPACE,	KC_DOWN,	KC_LEFT,	KC_RIGHT
};

// error for now:
// f pressed => b
// h => j
// q => 9
// ] => '
// 0 => SPC
// e => g
// r => v
/* Old example matrix:
 *	0x3E, 0x35, 0x3B, 0x22, 0xFF, 0x23, 0x00, 0x00,0x00, 
	0x41, 0x39, 0x3A, 0x05, 0x00, 0x11, 0x00, 0x00,0x00, 
	0x40, 0x29, 0x3D, 0x0A, 0x00, 0x0B, 0x00, 0xE3,0x49, 
	0x1A, 0x14, 0x08, 0x15, 0x00, 0x18, 0x0C, 0x00,0x00, 
	0x1F, 0x1E, 0x20, 0x21, 0x00, 0x24, 0x25, 0x00,0x00, 
	0x16, 0x04, 0x07, 0x09, 0x00, 0x0D, 0x0E, 0x00,0x00, 
*/


/* Apple //c keyboard matrix  */
/*	X0	1	2	3	4	5	6	7	8	9
Y0	ESC	1	2	3	4	6	5	7	8	9

1	TAB	Q	W	E	R	Y	T	U	I	O

2	A	D	S	H	F	G	J	K	;	L

3	Z	X	C	V	B	N	M	<	>	?

4	NO	NO	NO	NO	NO	NO	\	+	0	-

5	NO	NO	NO	NO	NO	NO	~	P	[	]

6	NO	NO	NO	NO	NO	NO	RET	UP	SPC	"

7	NO	NO	NO	NO	NO	NO	DEL	DN	LT	RT
*/
/* vim: set ts=8 sw=8 tw=0 noet :*/
