/**
 * @file Square.h
 * @brief Header file for the Square class, a child class of Shape.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmers Alexia Tu, Hyungseop Lee
 *
 * @details This class is a child class of Shape that inherits publicly, adding one extra data member which holds the side length.
 * It has 14 methods and, unlike the parent class, has 2 constructors since this class will actually be instantiated
 * in the test harness. There are additional instantiation cases that need to be accounted for. In the test
 * harness, this class is used to hold user input and manipulate the data according to the formulae of a square,
 * which can then be used to inform the user of the particular mathematical measurements of their input.
 * UPDATE: added 4 overloaded operators and also added a const method for GetSideLength to allow object parameters passed by
 * reference to still be able to use the functionality of the accessor methods
 */

#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#pragma warning(disable: 4305)

#define NUM_SIDES 4 /** Used in arithmetic, 4 sides of a square */
#define IS_EQUAL 0 /** Used to compare values within overloaded operator */
const float kPrecision = 0.00001; /** Used for determining if radius/sidelength are equal in overloaded operators */

 /**
  * @class Square
  * @brief A child class of Shape that represents a square.
  *
  * This class contains an extra data member for the side length of the square and methods for calculating
  * its perimeter, area, and overall dimension.
  */
class Square : public Shape {
private:
    /** @brief Side length of the square */
    float sideLength;

public:
    /**
     * @brief Constructor with parameters.
     *
     * @param newColour Colour of the square.
     * @param newSideLength Side length of the square. Defaults to 0.00.
     */
    Square(string newColour, float newSideLength = 0.00);

    /**
     * @brief Default constructor.
     *
     * @param newSideLength Side length of the square. Defaults to 0.00.
     *
     * @details This constructor is necessary for when instantiating with no parameters.
     */
    Square(float newSideLength = 0.00); 
    
    /**
     * @brief Copy constructor.
     *
     * @param Const reference to the object that will be copied from
     *
     * @details This constructor is necessary for using the overloaded assignment operators
     */
    Square(const Square& orig);

    /**
     * @brief Virtual destructor.
     *
     * @details The destructor needs to be virtual due to the use of virtual functions.
     */
    virtual ~Square(void);

    /**
     * @brief Accessor for the side length of the square.
     *
     * @return The side length of the square.
     */
    float GetSideLength(void);

    /**
     * @brief Const accessor for the side length of the square.
     *
     * @return The side length of the square.
     */
    float GetSideLength(void) const;

    /**
     * @brief Mutator for setting the side length of the square.
     *
     * @param newSideLength The new side length of the square.
     * @return True if the value is valid, false otherwise.
     */
    bool SetSideLength(float newSideLength);

    /**
     * @brief Method to display square information.
     */
    void Show(void);

    /**
     * @brief Method to calculate the perimeter of the square.
     *
     * @return The perimeter of the square.
     */
    virtual float Perimeter(void);

    /**
     * @brief Method to calculate the area of the square.
     *
     * @return The area of the square.
     */
    virtual float Area(void);

    /**
     * @brief Method to calculate the overall dimension of the square.
     *
     * @return The overall dimension of the square.
     */
    virtual float OverallDimension(void);

    /**
    * @brief Overloaded Operators
    */
    Square operator+(const Square& op2);
    Square operator*(const Square& op2);
    const Square& operator=(const Square& op2);
    bool operator==(const Square& op2) const; //promises to not change operands

};

#endif // SQUARE_H
