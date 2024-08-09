/**
 * @file Shape.cpp
 * @brief Source code for the Shape class.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmers Alexia Tu, Hyungseop Lee
 *
 * @details This source file contains the implementation of the Shape class. It includes a constructor, 2 accessors,
 * and 2 mutators.
 */

#include "Shape.h"

 /**
  * @brief Constructor for the Shape class.
  *
  * @param newName Potential type of shape.
  * @param newColour Potential colour of shape.
  *
  * @details This is a constructor that takes two string inputs, representing the object shape and colour, and validates
  * the input to confirm that they are within the range of what is allowed to be assigned to the data members. If the shape is not
  * within range, it is set to "Unknown", and if the colour is not in range, it is set to "undefined". It validates by comparing the
  * strings to each of the allowed values to see if it matches, and the string also has to be within the length of the max allowed length.
  */
Shape::Shape(string newName, string newColour) {
    if ((newName == "Circle" || newName == "Square" || newName == "Unknown") && newName.length() <= MAX_SHAPE) {
        name = newName;
    }
    else {
        name = "Unknown";
    }

    if ((newColour == "red" || newColour == "green" || newColour == "blue" ||
        newColour == "yellow" || newColour == "purple" || newColour == "pink" ||
        newColour == "orange" || newColour == "undefined") && newColour.length() <= MAX_COLOUR) {
        colour = newColour;
    }
    else {
        colour = "undefined";
    }
}

/**
 * @brief Accessor for the name of the shape.
 *
 * @return The name of the shape.
 *
 * @details This method safely returns the value of the name by utilizing the string class. The name is the type of shape of the object.
 */
string Shape::GetName(void) {
    return name;
}

/**
 * @brief Accessor for the colour of the shape.
 *
 * @return The colour of the shape.
 *
 * @details This method safely returns the value of the colour by utilizing the string class, returning the colour of the object.
 */
string Shape::GetColour(void) const {//change to const to use GetColour() in overloading operation
    return colour;
}

/**
 * @brief Accessor for the colour of the shape.
 *
 * @return The colour of the shape.
 *
 * @details This method safely returns the value of the colour by utilizing the string class, returning the colour of the object.
 */
string Shape::GetColour(void) {
    return colour;
}

/**
 * @brief Mutator for setting the name of the shape.
 *
 * @param newName The new name of the shape.
 * @return True if the value is valid, false otherwise.
 *
 * @details This method validates the input value to ensure it is proper in terms of words or length.
 */
bool Shape::SetName(string newName) {
    if ((newName == "Circle" || newName == "Square" || newName == "Unknown") && newName.length() <= MAX_SHAPE) {
        name = newName;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Mutator for setting the colour of the shape.
 *
 * @param newColour The new colour of the shape.
 * @return True if the value is valid, false otherwise.
 *
 * @details This method validates the input value to ensure it is proper in terms of words or length.
 */
bool Shape::SetColour(string newColour) {
    if ((newColour == "red" || newColour == "green" || newColour == "blue" ||
        newColour == "yellow" || newColour == "purple" || newColour == "pink" ||
        newColour == "orange" || newColour == "undefined") && newColour.length() <= MAX_COLOUR) {
        colour = newColour;
        return true;
    }
    else {
        return false;
    }
}
