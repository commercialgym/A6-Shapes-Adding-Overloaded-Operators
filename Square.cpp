/**
 * @file Square.cpp
 * @brief Source file for the Square class.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmers Alexia Tu, Hyungseop Lee
 *
 * @details Source code/definition for the Square class, including constructors, destructor, accessor, mutator,
 * and virtual functions. Since it's a child class of the base class Shape, it can utilize the parent's constructor for validation.
 */

#include "Shape.h"
#include "Square.h"

 /**
  * @brief Constructor for the Square class.
  *
  * @param newColour Colour of the square.
  * @param newSideLength Side length of the square.
  *
  * @details This constructor can be used when both arguments are provided in the test harness. It validates
  * the side length and sets it to 0 if it's not within range. To validate the incoming newColour, it calls
  * the parent class using an initialization list with the parameters "Square" for the shape type and newColour.
  */
Square::Square(string newColour, float newSideLength) : Shape("Square", newColour) {
    if (newSideLength >= 0.00) {
        sideLength = newSideLength;
    }
    else {
        sideLength = 0.00;
    }
}

/**
 * @brief Default constructor for the Square class.
 *
 * @param newSideLength Side length of the square. Defaults to 0.00.
 *
 * @details Unlike the other constructor, this one can either take one or no parameters. It uses a default
 * parameter so if an argument is not included during instantiation, it receives a default value of 0.00.
 * If an argument is given, it's validated within the body of the method and utilizes the parent constructor
 * class. It also considers the colour data member of the class; if no colour is passed upon instantiation,
 * it defaults to "undefined".
 */
Square::Square(float newSideLength) : Shape("Square", "undefined") {
    if (newSideLength >= 0.00) {
        sideLength = newSideLength;
    }
    else {
        sideLength = 0.00;
    }
}

/**
 * @brief Destructor for the Square class.
 *
 * @details Destroys an object of Square once it has gone out of scope and prints a message.
 */
Square::~Square(void) {
    printf("\nThe square is squished ...\n");
}

/**
 * @brief Accessor for the side length of the square.
 *
 * @return The side length of the square.
 */
float Square::GetSideLength(void) {
    return sideLength;
}

/**
 * @brief Mutator for setting the side length of the square.
 *
 * @param newSideLength The new side length of the square.
 * @return True if the value is valid and set successfully, false otherwise.
 */
bool Square::SetSideLength(float newSideLength) {
    if (newSideLength >= 0.00) {
        sideLength = newSideLength;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Method to display square information.
 *
 * @details This method prints all the values of data members and the calculated results using appropriate methods.
 */
void Square::Show(void) {
    printf("Shape Information\n");
    printf("%-15s: %s\n", "Name", GetName().c_str()); // Convert string to C-style string using c_str()
    printf("%-15s: %s\n", "Colour", GetColour().c_str());
    printf("%-15s: %.2f cm\n", "Side Length", sideLength);
    printf("%-15s: %.2f cm\n", "Perimeter", Perimeter());
    printf("%-15s: %.2f square cm\n", "Area", Area());
}

/**
 * @brief Method to calculate the perimeter of the square.
 *
 * @return The calculated perimeter of the square.
 */
float Square::Perimeter(void) {
    return NUM_SIDES * sideLength;
}

/**
 * @brief Method to calculate the area of the square.
 *
 * @return The calculated area of the square.
 */
float Square::Area(void) {
    return sideLength * sideLength;
}

/**
 * @brief Method to calculate the overall dimension of the square.
 *
 * @return The calculated overall dimension of the square.
 */
float Square::OverallDimension(void) {
    return sideLength;
}
