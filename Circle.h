/**
 * @file Circle.h
 * @brief Header file for the Circle class, a child class of Shape.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmers Alexia Tu, Hyungseop Lee
 *
 * @details This class is a child class of Shape that inherits publicly, adding one extra data member which holds the radius.
 * It has 9 methods and, unlike the parent class, has 2 constructors since this class will actually be instantiated
 * in the test harness. There are additional instantiation cases that need to be accounted for. In the test
 * harness, this class is used to hold user input and manipulate the data according to the formulae of a circle,
 * which can then be used to inform the user of the particular mathematical measurements of their input.
 */

#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

#define FIXED_NUM 2
#define PIE 3.1415926

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

    //overloaded operators
    Circle operator+(const Circle& op2);
    Circle operator*(const Circle& op2);
    const Circle& operator=(const Circle& op2);
    bool operator==(const Circle& op2);

};

#endif // CIRCLE_H
