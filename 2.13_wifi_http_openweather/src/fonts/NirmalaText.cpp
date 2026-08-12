#include "FontTypes.h"
#include "NirmalaText.h"

// ########################################################################################
// Character bitmaps for Nirmala Text 8pt - BITMAPS REMOVED DUE TO LICENSE CONSTRAINTS
// Generate the bitmaps with TheDotFactory - https://github.com/pavius/the-dot-factory/tags
// Refer to the ReadMe for more information
// ########################################################################################

const uint8_t NirmalaText_8ptBitmaps[] = 
{
	// @0 ' ' (2 pixels wide)

	// @11 '!' (1 pixels wide)

	// @22 '"' (3 pixels wide)

	// @33 '#' (6 pixels wide)

	// @44 '$' (5 pixels wide)

	// @55 '%' (9 pixels wide)

	// @77 '&' (8 pixels wide)

	// @88 ''' (1 pixels wide)

	// @99 '(' (2 pixels wide)

	// @110 ')' (2 pixels wide)

	// @121 '*' (5 pixels wide)

	// @132 '+' (5 pixels wide)

	// @143 ',' (2 pixels wide)

	// @154 '-' (3 pixels wide)

	// @165 '.' (1 pixels wide)

	// @176 '/' (4 pixels wide)

	// @187 '0' (6 pixels wide)

	// @198 '1' (3 pixels wide)

	// @209 '2' (4 pixels wide)

	// @220 '3' (4 pixels wide)

	// @231 '4' (6 pixels wide)

	// @242 '5' (4 pixels wide)

	// @253 '6' (5 pixels wide)

	// @264 '7' (4 pixels wide)

	// @275 '8' (5 pixels wide)

	// @286 '9' (5 pixels wide)

	// @297 ':' (1 pixels wide)

	// @308 ';' (2 pixels wide)

	// @319 '<' (5 pixels wide)

	// @330 '=' (5 pixels wide)

	// @341 '>' (5 pixels wide)

	// @352 '?' (4 pixels wide)

	// @363 '@' (9 pixels wide)

	// @385 'A' (7 pixels wide)

	// @396 'B' (5 pixels wide)

	// @407 'C' (5 pixels wide)

	// @418 'D' (6 pixels wide)

	// @429 'E' (4 pixels wide)

	// @440 'F' (4 pixels wide)

	// @451 'G' (6 pixels wide)

	// @462 'H' (6 pixels wide)

	// @473 'I' (1 pixels wide)

	// @484 'J' (3 pixels wide)

	// @495 'K' (5 pixels wide)

	// @506 'L' (3 pixels wide)

	// @517 'M' (8 pixels wide)

	// @528 'N' (6 pixels wide)

	// @539 'O' (7 pixels wide)

	// @550 'P' (5 pixels wide)

	// @561 'Q' (7 pixels wide)

	// @572 'R' (6 pixels wide)

	// @583 'S' (4 pixels wide)

	// @594 'T' (5 pixels wide)

	// @605 'U' (6 pixels wide)

	// @616 'V' (7 pixels wide)

	// @627 'W' (11 pixels wide)

	// @649 'X' (6 pixels wide)

	// @660 'Y' (5 pixels wide)

	// @671 'Z' (6 pixels wide)

	// @682 '[' (2 pixels wide)

	// @693 'bs' (4 pixels wide)

	// @704 ']' (2 pixels wide)

	// @715 '^' (6 pixels wide)

	// @726 '_' (5 pixels wide)

	// @737 '`' (2 pixels wide)

	// @748 'a' (4 pixels wide)

	// @759 'b' (5 pixels wide)

	// @770 'c' (4 pixels wide)

	// @781 'd' (5 pixels wide)

	// @792 'e' (4 pixels wide)

	// @803 'f' (4 pixels wide)

	// @814 'g' (5 pixels wide)

	// @825 'h' (5 pixels wide)

	// @836 'i' (1 pixels wide)

	// @847 'j' (3 pixels wide)

	// @858 'k' (4 pixels wide)

	// @869 'l' (1 pixels wide)

	// @880 'm' (7 pixels wide)

	// @891 'n' (5 pixels wide)

	// @902 'o' (5 pixels wide)

	// @913 'p' (5 pixels wide)

	// @924 'q' (5 pixels wide)

	// @935 'r' (3 pixels wide)

	// @946 's' (3 pixels wide)

	// @957 't' (4 pixels wide)

	// @968 'u' (5 pixels wide)

	// @979 'v' (5 pixels wide)

	// @990 'w' (9 pixels wide)

	// @1012 'x' (5 pixels wide)

	// @1023 'y' (5 pixels wide)

	// @1034 'z' (5 pixels wide)

	// @1045 '{' (3 pixels wide)

	// @1056 '|' (1 pixels wide)

	// @1067 '}' (3 pixels wide)

	// @1078 '~' (5 pixels wide)
};

// Character descriptors for Nirmala Text 8pt
// { [Char width in bits], [Offset into NirmalaText_8ptCharBitmaps in bytes] }
const FONT_CHAR_INFO NirmalaText_8ptDescriptors[] = 
{
	{2, 0}, 		//   
	{1, 11}, 		// ! 
	{3, 22}, 		// " 
	{6, 33}, 		// # 
	{5, 44}, 		// $ 
	{9, 55}, 		// % 
	{8, 77}, 		// & 
	{1, 88}, 		// ' 
	{2, 99}, 		// ( 
	{2, 110}, 		// ) 
	{5, 121}, 		// * 
	{5, 132}, 		// + 
	{2, 143}, 		// , 
	{3, 154}, 		// - 
	{1, 165}, 		// . 
	{4, 176}, 		// / 
	{6, 187}, 		// 0 
	{3, 198}, 		// 1 
	{4, 209}, 		// 2 
	{4, 220}, 		// 3 
	{6, 231}, 		// 4 
	{4, 242}, 		// 5 
	{5, 253}, 		// 6 
	{4, 264}, 		// 7 
	{5, 275}, 		// 8 
	{5, 286}, 		// 9 
	{1, 297}, 		// : 
	{2, 308}, 		// ; 
	{5, 319}, 		// < 
	{5, 330}, 		// = 
	{5, 341}, 		// > 
	{4, 352}, 		// ? 
	{9, 363}, 		// @ 
	{7, 385}, 		// A 
	{5, 396}, 		// B 
	{5, 407}, 		// C 
	{6, 418}, 		// D 
	{4, 429}, 		// E 
	{4, 440}, 		// F 
	{6, 451}, 		// G 
	{6, 462}, 		// H 
	{1, 473}, 		// I 
	{3, 484}, 		// J 
	{5, 495}, 		// K 
	{3, 506}, 		// L 
	{8, 517}, 		// M 
	{6, 528}, 		// N 
	{7, 539}, 		// O 
	{5, 550}, 		// P 
	{7, 561}, 		// Q 
	{6, 572}, 		// R 
	{4, 583}, 		// S 
	{5, 594}, 		// T 
	{6, 605}, 		// U 
	{7, 616}, 		// V 
	{11, 627}, 		// W 
	{6, 649}, 		// X 
	{5, 660}, 		// Y 
	{6, 671}, 		// Z 
	{2, 682}, 		// [ 
	{4, 693}, 		// BS
	{2, 704}, 		// ] 
	{6, 715}, 		// ^ 
	{5, 726}, 		// _ 
	{2, 737}, 		// ` 
	{4, 748}, 		// a 
	{5, 759}, 		// b 
	{4, 770}, 		// c 
	{5, 781}, 		// d 
	{4, 792}, 		// e 
	{4, 803}, 		// f 
	{5, 814}, 		// g 
	{5, 825}, 		// h 
	{1, 836}, 		// i 
	{3, 847}, 		// j 
	{4, 858}, 		// k 
	{1, 869}, 		// l 
	{7, 880}, 		// m 
	{5, 891}, 		// n 
	{5, 902}, 		// o 
	{5, 913}, 		// p 
	{5, 924}, 		// q 
	{3, 935}, 		// r 
	{3, 946}, 		// s 
	{4, 957}, 		// t 
	{5, 968}, 		// u 
	{5, 979}, 		// v 
	{9, 990}, 		// w 
	{5, 1012}, 		// x 
	{5, 1023}, 		// y 
	{5, 1034}, 		// z 
	{3, 1045}, 		// { 
	{1, 1056}, 		// | 
	{3, 1067}, 		// } 
	{5, 1078}, 		// ~
};

const FONT_INFO NirmalaText_8ptFontInfo =
{
	11, //  Character height
	' ', //  Start character
	'~', //  End character
	2, // Space width
	NirmalaText_8ptDescriptors, //  Character descriptor array
	NirmalaText_8ptBitmaps, //  Character bitmap array
};

uint16_t getNirmalaText8ptDescriptorCount() {
    return sizeof(NirmalaText_8ptDescriptors) / sizeof(FONT_CHAR_INFO);
}