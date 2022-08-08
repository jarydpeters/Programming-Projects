/*  Bit Stuffing
 *
 *  Stores, reads, and modifies parameters of a "box" 
 *  all "box" parameters are stored a single integer value
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

// Expanded int value of 32 bits to stuff with box parameters.
// Contents, reading right to left:
// bits 0-3:   border style
// bits 4-7:   border color
// bits 8-11:  border opacity
// bits 12-15: fill color
// bits 16-19: fill opacity
int boxParameters = 0b00000000000000000000000000000000;

// opacity/transparency
const char* opacity[2] = {"Transparent", "Opaque"};
#define TRANSPARENT 0b0
#define OPAQUE      0b1

// border styles
const char* style[3] = {"Solid", "Dotted", "Dashed"};
#define SOLID   0b00
#define DOTTED  0b01
#define DASHED  0b10

// primary colors
const char* color[8] = {"Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "White"};
#define BLACK   0b000
#define RED     0b001
#define GREEN   0b010
#define YELLOW  0b011
#define BLUE    0b100
#define MAGENTA 0b101
#define CYAN    0b110
#define WHITE   0b111

void setFillOpacity(int fillOpacity);
void setFillColor(int fillColor);
void setBorderOpacity(int borderOpacity);
void setBorderColor(int borderColor);
void setBorderStyle(int borderStyle);

void getFillOpacity(void);
void getFillColor(void);
void getBorderOpacity(void);
void getBorderColor(void);
void getBorderStyle(void);

int main(void)
{
    //output default values
    printf("Starting box values:\n");
    getFillOpacity();
    getFillColor();
    getBorderOpacity();
    getBorderColor();
    getBorderStyle();

    //demonstrate writability
    setFillOpacity(OPAQUE);
    setFillColor(MAGENTA);
    setBorderOpacity(OPAQUE);
    setBorderColor(GREEN);
    setBorderStyle(DASHED);

    //print changed values
    printf("\nBox values after first change:\n");
    getFillOpacity();
    getFillColor();
    getBorderOpacity();
    getBorderColor();
    getBorderStyle();

    //demonstrate rewritability
    setFillOpacity(OPAQUE);
    setFillColor(RED);
    setBorderOpacity(TRANSPARENT);
    setBorderColor(YELLOW);
    setBorderStyle(DOTTED);

    //print changed (again) values
    printf("\nBox values after second change:\n");
    getFillOpacity();
    getFillColor();
    getBorderOpacity();
    getBorderColor();
    getBorderStyle();

    return 0;
}

//setters

void setFillOpacity(int fillOpacity)
{
    //clear out old 1-bit value
    boxParameters &= 0b11101111111111111111;
    //set new value
    boxParameters |= (fillOpacity << 16); 
}

void setFillColor(int fillColor)
{
    //clear out old 3-bit value
    boxParameters &= 0b11111000111111111111;
    //set new value
    boxParameters |= (fillColor << 12); 
}

void setBorderOpacity(int borderOpacity)
{
    //clear out old 1-bit value
    boxParameters &= 0b11111111111011111111;
    //set new value
    boxParameters |= (borderOpacity << 8); 
}

void setBorderColor(int borderColor)
{
    //clear out old 3-bit value
    boxParameters &= 0b11111111111110001111;
    //set new value
    boxParameters |= (borderColor << 4); 
}

void setBorderStyle(int borderStyle)
{
    //clear out old 2-bit value
    boxParameters &= 0b11111111111111111100;
    //set new value
    boxParameters |= (borderStyle << 0); 
}

//getters

void getFillOpacity(void)
{
    printf("Fill Opacity:   %s\n", opacity[(boxParameters >> 16) & 0b01]);
}

void getFillColor(void)
{
    printf("Fill Color:     %s\n", color[(boxParameters >> 12) & 0b111]);
}

void getBorderOpacity(void)
{
    printf("Border Opacity: %s\n", opacity[(boxParameters >> 8) & 0b01]);
}

void getBorderColor(void)
{
    printf("Border Color:   %s\n", color[(boxParameters >> 4) & 0b111]);
}

void getBorderStyle(void)
{
    printf("Border Style:   %s\n", style[(boxParameters >> 0) & 0b11]);
}