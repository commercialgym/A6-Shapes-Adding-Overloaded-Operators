/**
 * @file Shape.h
 * @brief Header file for the Shape class, an abstract base class used for Circle and Square classes.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmer Alexia Tu, Hyungseop Lee
 *
 * @details This class is an abstract base class that will be used for the Circle and Square classes. It has two data
 * members and 9 methods. Its constructors will also be used by its subclasses' constructors by chaining them
 * together. This project is and class is the first time we implement the use of pure virtual functions. This is also
 * the first time that we don't have a destructor for a class that we created constructors for. This is because no objects of
 * the Shape class will be instantiated.
 */

#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <cstdio>
#include <iostream>
#include <string> 
#include <new.h>
using namespace std;

#define MAX_SHAPE 50
#define MAX_COLOUR 10

/**
 * @class Shape
 * @brief An abstract base class for various shapes.
 *
 * This class contains the common attributes and methods that will be shared by derived shape classes
 * such as Circle and Square.
 */
class Shape
{
private:
    /** @brief Name of the shape */
    string name;
    /** @brief Colour of the shape */
    string colour;

public:

    /**
     * @brief Constructor with default parameters.
     *
     * @param newName The name of the shape. Defaults to "Unknown".
     * @param newColour The colour of the shape. Defaults to "Undefined".
     */
    Shape(string newName = "Unknown", string newColour = "Undefined");

    /** @brief Gets the name of the shape.
     * @return The name of the shape.
     */
    string GetName(void);

    /** @brief Const accessor, Gets the colour of the shape.
     * @return The colour of the shape.
     */
    string GetColour(void) const;

    /** @brief Gets the colour of the shape.
     * @return The colour of the shape.
     */
    string GetColour(void); //need to overload

    /**
     * @brief Sets the name of the shape.
     *
     * @param newName The new name of the shape.
     * @return True if the name was set successfully, false otherwise.
     */
    bool SetName(string newName);

    /**
     * @brief Sets the colour of the shape.
     *
     * @param newColour The new colour of the shape.
     * @return True if the colour was set successfully, false otherwise.
     */
    bool SetColour(string newColour);

    /** @brief Pure virtual function to calculate the perimeter of the shape.
     * @return The perimeter of the shape.
     */
    virtual float Perimeter(void) = 0;

    /** @brief Pure virtual function to calculate the area of the shape.
     * @return The area of the shape.
     */
    virtual float Area(void) = 0;

    /** @brief Pure virtual function to calculate the overall dimension of the shape.
     * @return The overall dimension of the shape.
     */
    virtual float OverallDimension(void) = 0;

};

#endif // SHAPE_H
