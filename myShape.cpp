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

int main(void) {
    Circle round1("red", 5.5);
    Circle round2("blue", 10.5);
    Circle playARound;//instantiate with default value

    Square square1("orange", 5);
    Square square2("purple", 12);
    Square playASquare;

    playARound = round1.operator+(round2);
    playARound.Show();

    playARound = round1.operator*(round2);
    playARound.Show();

    playARound = round1;
    if (playARound == round1) {
        printf("Hurray !!\n");
    }
    else {
        printf("Awww !!\n");
    }

    return 0;
}
