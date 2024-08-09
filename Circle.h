/**
 * @file Circle.h
 * @brief Header file for the Circle class, a child class of Shape.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmers Alexia Tu, Hyungseop Lee
 *
 * @details This class is a child class of Shape that inherits publicly, adding one extra data member which holds the radius.
 * It has 14 methods and, unlike the parent class, has 2 constructors since this class will actually be instantiated
 * in the test harness. There are additional instantiation cases that need to be accounted for. In the test
 * harness, this class is used to hold user input and manipulate the data according to the formulae of a circle,
 * which can then be used to inform the user of the particular mathematical measurements of their input.
 * UPDATE: added 4 overloaded operators and also added a const method for GetRadius to allow object parameters passed by
 * reference to still be able to use the functionality of the accessor methods
 */

#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#pragma warning(disable: 4305)

#define FIXED_NUM 2
#define PIE 3.1415926 /** Used in arhithmetic to find radius */
#define IS_EQUAL 0 /** Used to compare values within overloaded operator */
const float kSmallDiff = 0.00001; /** Used for determining if radius/sidelength are equal in overloaded operators */

 /**
  * @class Circle
  * @brief A child class of Shape that represents a circle.
  *
  * This class contains an extra data member for the radius of the circle and methods for calculating
  * its perimeter, area, and overall dimension.
  */
class Circle : public Shape {
private:
    /** @brief Radius of the circle */
    float radius;
public:
    /**
     * @brief Constructor with parameters.
     *
     * @param newColour Colour of the circle.
     * @param newRadius Radius of the circle. Defaults to 0.00.
     */
    Circle(string newColour, float newRadius = 0.00);

    /**
     * @brief Default constructor.
     *
     * @param newRadius Radius of the circle. Defaults to 0.00.
     */
    Circle(float newRadius = 0.00);
    
    /**
     * @brief Copy constructor constructor.
     *
     * @param Const reference to the object that will be copied from
     */
    Circle(const Circle& orig);

    /**
     * @brief Virtual destructor.
     *
     * @details The destructor needs to be virtual since the class has virtual functions.
     */
    virtual ~Circle(void);

    /**
     * @brief Accessor for the radius of the circle.
     *
     * @return The radius of the circle.
     */
    float GetRadius(void);

    /**
     * @brief Const accessor for the radius of the circle.
     *
     * @return The radius of the circle.
     */
    float GetRadius(void) const;

    /**
     * @brief Mutator for setting the radius of the circle.
     *
     * @param newRadius The new radius of the circle.
     * @return True if the value is valid, false otherwise.
     */
    bool SetRadius(float newRadius);

    /**
     * @brief Method to display circle information.
     */
    void Show(void);

    /**
     * @brief Method to calculate the perimeter of the circle.
     *
     * @return The perimeter of the circle.
     */
    virtual float Perimeter(void);

    /**
     * @brief Method to calculate the area of the circle.
     *
     * @return The area of the circle.
     */
    virtual float Area(void);

    /**
     * @brief Method to calculate the overall dimension of the circle.
     *
     * @return The overall dimension of the circle.
     */
    virtual float OverallDimension(void);

    /**
    * @brief Overloaded Operators
    */
    Circle operator+(const Circle& op2);
    Circle operator*(const Circle& op2);
    const Circle& operator=(const Circle& op2);
    bool operator==(const Circle& op2) const; //promises to not change operands

};

#endif // CIRCLE_H
