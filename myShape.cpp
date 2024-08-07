/**
 * @file myShape.cpp
 * @brief Program that prompts users for colour, radius, and side length, then uses the input to instantiate objects
 * of Circle and Square classes to store and manipulate given data. It displays information such as colour, type of shape,
 * perimeter, area, and overall dimension using the Show() method. After displaying the information, the user can observe
 * the data relevant to their input.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmers Alexia Tu, Hyungseop Lee
 *
 */

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <stdio.h>
#pragma warning(disable: 4996)

#define R1_RADIUS 5.5
#define R2_RADIUS 10.5
#define S1_LEN 5
#define S2_LEN 12

int main(void) {
    Circle round1("red", R1_RADIUS);
    Circle round2("blue", R2_RADIUS);
    Circle playARound;//instantiate with default value

    Square square1("orange", S1_LEN);
    Square square2("purple", S2_LEN);
    Square playASquare;

    playARound = round1.operator+(round2);
    playASquare = square2.operator+(square1);
    playARound.Show(); //printing after both additions just because that was the order stated in requirements
    playASquare.Show();

    playARound = round1.operator*(round2);
    playASquare = square2.operator*(square1);
    playARound.Show();
    playASquare.Show();


    playARound = round1;
    if (playARound == round1) {
        printf("Hurray !!\n");
    }
    else {
        printf("Awww !!\n");
    }

    return 0;
}
