#ifndef TM1637_H_
#define TM1637_H_

#include <stdbool.h>

/* Initiate TM1637 display
 *
 * Takes the clock and data pin names (integers) as input. */
void TM1637_init(uint clk, uint dio);

void TM1637_on();

/* Put one or two bytes on TM1637 display. 
 *
 * start_pos: uint from 0 to 3 where 0 is to the left
 * data: raw data for one or two bytes, the first byte will be but to the left */
void TM1637_put_2_bytes(uint start_pos, uint data);

/* Put one to four bytes on TM1637 display. 
 *
 * start_pos: uint from 0 to 3 where 0 is to the left
 * data: raw data for one to four bytes, the first byte will be but to the left */
void TM1637_put_4_bytes(uint start_pos, uint data);

/* Display a number with 4 digits.
 *
 * The least significat digit will be put to the right.
 * Arguments:
 *  int number: The number to display (currently only positve)
 *  bool leadingZeros: If leading Zeros should be displayed or not. */
void TM1637_display(int number, bool leadingZeros);    
  
/* Display a number on the 2 leftmost digits on the display, with or without
 * a colon.
 *
 * !!! Avoid using this function since it will cause the right side to blink */
void TM1637_display_left(int number, bool leadingZeros, bool colon);

/* Display a number on the 2 rightmost digits on the display. */
void TM1637_display_right(int number, bool leadingZeros);

/* Set the display brightness.
 *
 * val can be a value from 0 to 7. 
 *
 * Display brightness is not immeidiatly updated, but next time something is
 * displayed it will have the new brightness. */
void TM1637_set_brightness(int val);

/* Clear the display. */
void TM1637_clear();
 
#endif // TM1637_H_
