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
 * @brief Copt constructor for the Square class.
 *
 * @param Const reference to the object that will be copied from
 *
 * @details Used in overloaded operators that returns an object variable by value or during an assignment statement. 
 * Technically not NEEDed because there is no dynamically allocated space for the members of this class, however best 
 * practices state that if you have any of the following: a copy constructor, overloaded assignment operator, or destructor,
 * then you should create all three of them. Assigns the side length of the orig object to the new object being created.
 */
Square::Square(const Square& orig) : Shape("Square", orig.GetColour()) {
    //copy side length from the original to the new data member
    sideLength = orig.sideLength;
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
 * @brief Const accessor for the side length of the square.
 *
 * @return The side length of the square.
 *
 * @details Used for overloaded operators, this method allows the const variable to still be able to use the GetSideLength() functionality
 */
float Square::GetSideLength(void) const {
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


/**
* @brief Overloaded addition operator
*
* @param const Square& op2 : another Square object to be added to the current Square object, passed by reference
*
* @return The resulting Square object after adding 2 squares together, which is returned by value by passing a
* copy of the local variable created within this method
*
* @details After adding 2 squares, the resultant will take the colour of the LHS operand, and the sidelength will be the
* sum of the LHS and RHS operands. Follows best practices by using const accessors
*/
Square Square::operator+(const Square& op2) { 
    Square temp(this->GetColour(), this->GetSideLength() + op2.GetSideLength()); //addition for sideLength
    //temp.SetColour(this->GetColour());
    //temp.SetSideLength(this->GetSideLength() + op2.GetSideLength());
    return temp; //copy constructor called....
}

/**
* @brief Overloaded multiplication operator
*
* @param const Square& op2 : another Square object to be multiplied with the current Square object, passed by reference
*
* @return The resulting Square object after multiplying 2 squares together, which is returned by value by passing a
* copy of the local variable created within this method
*
* @details After multiplying one Square by another, the resultant Square object will take the colour of the RHS operand, and
* the sidelength will be product of the LHS and RHS operands' sidelength. Follows best practices by using const accessors
*/
Square Square::operator*(const Square& op2) {
    Square temp(op2.GetColour(), this->GetSideLength() * op2.GetSideLength());
    //temp.SetColour(op2.GetColour());
    //temp.SetSideLength(this->GetSideLength() * op2.GetSideLength());
    return temp;
}

/**
* @brief Overloaded assignment operator
*
* @param const Square& op2 : another Square object whose values will be used to assign to the current Square, passed by reference
*
* @return A const reference to the current object
*
* @details Accesses the RHS Square's attributes and assigns it to the current Square's attributes/data members, this includes the
* colour and the sidelength. Follows best practices by using const accessors
*/
const Square& Square::operator=(const Square& op2) {
    //check to see if the object is being assigned to itself
    if (this != &op2) 
    {
        this->SetColour(op2.GetColour());
        this->SetSideLength(op2.GetSideLength());
    }
    return *this;
}

/**
* @brief Overloaded equal comparison operator
*
* @param const Square& op2 : a Square object that will be compared to the current Square object, passed by reference
*
* @return A boolean value indicating whether or not the two Squares are equal (true or false)
*
* @details  Compares the colour as well as the sideLength of the Squares to see if they are equal in value, if they are the method
* returns true. Since sideLength value is represented by float data-type, the operand's sideLength are compared to see if the they are
* approximately equal (with small variance). Follows best practices by using const accessors. Is of type const to promise the compiler
* that the overloaded operator will not change the operands
*/
bool Square::operator==(const Square& op2) const {
    float approxEqual = kPrecision; //a small variance between obj1 and obj2 is allowed up to this value (0.00001)
    float precisionDiff = this->GetSideLength() - op2.GetSideLength();
    if (precisionDiff < IS_EQUAL) //if the difference between the object's length is negative,
    {
        precisionDiff = -precisionDiff; //find absolute value to compare to approxEqual variable
    }
    //if the difference between LHS and RHS sideLength is less than approxEqual variable, it means they are essentially equal
    if (this->GetColour() == op2.GetColour() && precisionDiff < approxEqual) {
        return true;
    }
    else {
        return false;
    }
}