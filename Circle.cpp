/**
 * @file Circle.cpp
 * @brief Source file for the Circle class.
 *
 * @project A-04 Shapes : Laying The Foundation
 * @date 07-13-2024
 * @programmers Alexia Tu, Hyungseop Lee
 *
 * @details This file contains the class definition for the Circle class including
 * constructor, destructor, accessor, mutator, and methods.
 */

#include "Shape.h"
#include "Circle.h"

 /**
  * @brief Constructor for the Circle class.
  *
  * @param newColour Colour of the circle.
  * @param newRadius Radius of the circle.
  *
  * @details This constructor initializes all the data members using the base class constructor which is
  * Shape(), and also validates the values to check if they are in range or not.
  */
Circle::Circle(string newColour, float newRadius) : Shape("Circle", newColour) {
    if (newRadius >= 0.00) {
        radius = newRadius;
    }
    else {
        radius = 0.00;
    }
}

/**
 * @brief Default constructor for the Circle class.
 *
 * @param newRadius Radius of the circle. Defaults to 0.00.
 *
 * @details This default constructor can take a float as a parameter. If an argument is not included during instantiation,
 * it receives a default value of 0.00 which is indicated in this prototype. It is also important to consider the colour data
 * member of the class. If upon instantiation there was no colour passed, it should be "undefined". It is still necessary to validate
 * the float newRadius in the case that a parameter is used upon instantiation.
 */
Circle::Circle(float newRadius) : Shape("Circle", "undefined") {
    if (newRadius >= 0.00) {
        radius = newRadius;
    }
    else {
        radius = 0.00;
    }
}

/**
 * @brief Destructor for the Circle class.
 *
 * @details Destroys the object and prints a message for output.
 */
Circle::~Circle(void) {
    printf("\nThe circle is broken ...\n");
}

/**
 * @brief Accessor for the radius of the circle.
 *
 * @return The radius of the circle.
 *
 * @details This method returns the radius data member.
 */
float Circle::GetRadius(void) {
    return radius;
}

/**
 * @brief Const accessor for the radius of the circle.
 *
 * @return The radius of the circle.
 *
 * @details This overloaded method returns the radius data member, used for overloaded operators when using best practices,
 * allows the const variable to still access this method
 */
float Circle::GetRadius(void) const{
    return radius;
}

/**
 * @brief Mutator for setting the radius of the circle.
 *
 * @param newRadius The new radius of the circle.
 * @return True if the value is in the right range, otherwise false.
 *
 * @details This method validates the value to check if it is in the right range or not.
 */
bool Circle::SetRadius(float newRadius) {
    if (newRadius >= 0) {
        radius = newRadius;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Method to display circle information.
 *
 * @details This method prints all the values of data members.
 */
void Circle::Show(void) {
    printf("Shape Information\n");
    printf("%-15s: %s\n", "Name", GetName().c_str()); // Convert string to C-style string using c_str()
    printf("%-15s: %s\n", "Colour", GetColour().c_str());
    printf("%-15s: %.2f cm\n", "Radius", radius);
    printf("%-15s: %.2f cm\n", "Circumference", Perimeter());
    printf("%-15s: %.2f square cm\n", "Area", Area());
}

/**
 * @brief Method to calculate the perimeter of the circle.
 *
 * @return The calculated perimeter of the circle.
 *
 * @details This method calculates the value of the perimeter.
 */
float Circle::Perimeter(void) {
    return FIXED_NUM * PIE * radius;
}

/**
 * @brief Method to calculate the area of the circle.
 *
 * @return The calculated area of the circle.
 *
 * @details This method calculates the value of the area.
 */
float Circle::Area(void) {
    return PIE * (radius * radius);
}

/**
 * @brief Method to calculate the overall dimension of the circle.
 *
 * @return The calculated overall dimension of the circle.
 *
 * @details This method calculates the value of the overall dimension.
 */
float Circle::OverallDimension(void) {
    return FIXED_NUM * radius;
}

/**
* @brief Overloaded addition operator
* 
* @param const Circle& op2 : another Circle object to be added to the current Circle object, passed by reference
* 
* @return The resulting circle object after adding 2 circles together, which is returned by value by passing a
* copy of the local variable created within this method
* 
* @details When adding two circles, the resultant will take the colour of the circle on the LHS and 
* the radius will be the sum of the LHS and RHS operand's radii. Follows best practices by using const accessors
*/
Circle Circle::operator+(const Circle& op2) {
    Circle temp; 
    temp.SetColour(this->GetColour());
    temp.SetRadius(this->GetRadius() + op2.GetRadius());
    return temp;
}

/**
* @brief Overloaded multiplication operator
*
* @param const Circle& op2 : another Circle object to be multiplied by the current Circle object, passed by reference
* 
* @return The resulting circle object after multiplying 2 circles together, which is returned by value by passing a
* copy of the local variable created within this method
* 
* @details The resultant of multiplying two circle object together takes the colour of the circle on the RHS, and it's
* radius is the product of the LHS and RHS operand's radii. Follows best practices by using const accessors
*/
Circle Circle::operator*(const Circle& op2) {
    Circle temp;
    temp.SetColour(op2.GetColour());
    temp.SetRadius(this->GetRadius() + op2.GetRadius());
    return temp;
}

/**
* @brief Overloaded assignment operator
*
* @param const Circle& op2 : another Circle object whose values will be used to assign to the current circle's, passed by reference
*
* @return A const reference to the current object
*
* @details Accesses the RHS Circle's attributes and assigns it to the current Circle's attributes/data members, this includes the 
* colour and the radius. Follows best practices by using const accessors
*/
const Circle& Circle::operator=(const Circle& op2) {//----------slide 14
    this->SetColour(op2.GetColour());
    this->SetRadius(op2.GetRadius());
    return *this;
}

/**
* @brief Overloaded equal comparison operator 
*
* @param const Circle& op2 : another Circle object that will be compared to the current Circle, passed by reference
*
* @return A boolean value indicating whether or not the two Circles are equal (true or false)
*
* @details Compares the colour as well as the radius of both the circles to see if they are equal in value, if they are the method 
* returns true. Since radius value is represented by float data-type, the operand's radii are compared to see if the they are
* approximately equal (with small variance). Follows best practices by using const accessors. Is of type const to promise the compiler
* that the overloaded operator will not change the operands
*/
bool Circle::operator==(const Circle& op2) const{//----------slide 22
    float approxEqual = kSmallDiff; //a small variance between obj1 and obj2 is allowed up to this value (0.00001)
    float precisionDiff = this->GetRadius() - op2.GetRadius();
    if (precisionDiff < IS_EQUAL)
    {
        precisionDiff = -precisionDiff; //find absolute value to compare to approxEqual variable
    }
    //if the difference between LHS and RHS radii is less than approxEqual variable, means they are essentially equal
    if (this->GetColour() == op2.GetColour() && precisionDiff < approxEqual) {
        return true;
    }
    else {
        return false;
    }
}