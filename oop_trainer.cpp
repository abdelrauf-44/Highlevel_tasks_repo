/**
 * @file oop_trainer.cpp
 * @brief Demonstration of Object-Oriented Programming concepts in C++
 * @author Abdelrauf
 * @date October 23, 2025
 * 
 * This program demonstrates key OOP concepts including:
 * - Abstract classes
 * - Inheritance
 * - Encapsulation
 * - Polymorphism
 * - Constructors
 * - Method overriding
 */

#include <iostream>

using std::string; 

/**
 * @class AbstractEmployee
 * @brief Abstract base class that defines an interface
 * 
 * This abstract class contains a pure virtual function which
 * forces derived classes to implement the askforprom method.
 */
class AbstractEmployee{
    /**
     * @brief Pure virtual function for promotion requests
     * 
     * This function must be implemented by all derived classes.
     * Using = 0 makes it a pure virtual function, which makes this an abstract class.
     */
    virtual void askforprom() = 0;
};

/**
 * @class Employee
 * @brief Concrete class implementing the AbstractEmployee interface
 * 
 * This class demonstrates encapsulation by providing controlled access
 * to private attributes through getter and setter methods.
 */
class Employee:AbstractEmployee{
    // All the attributes are private by default
protected: // Protected members can be accessed by derived classes
    string Name;     ///< Employee's name
    string Company;  ///< Company where employee works
    int Age;         ///< Employee's age
 
public:
    /**
     * @brief Set the employee's name
     * @param name The new name
     */
    void setName(string name){
        Name = name;
    }
    
    /**
     * @brief Get the employee's name
     * @return The employee's name
     */
    string getName(){
            return Name;
        }

    /**
     * @brief Get the employee's company
     * @return The company name
     */
    string getCompany(){
        return Company;
    }

    /**
     * @brief Set the employee's company
     * @param company The new company name
     */
    void setCompany(string company){
        Company = company;
    }

    /**
     * @brief Get the employee's age
     * @return The employee's age
     */
    int getAge(){
        return Age;
    }

    /**
     * @brief Set the employee's age
     * @param age The new age
     * @note This method has a naming conflict with setCompany - should be renamed to setAge
     */
    void setCompany(int age){
        Age = age;
    }
   
    /**
     * @brief Virtual method to introduce the employee
     * 
     * This method is declared virtual to enable polymorphism,
     * allowing derived classes to override it.
     */
    virtual void introduce_yourself(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    
    /**
     * @brief Constructor for the Employee class
     * @param name The employee's name
     * @param company The company name
     * @param age The employee's age
     */
    Employee(string name, string company, int age){
        Name = name;
        Company = company; 
        Age = age;
    }

    /**
     * @brief Implementation of the abstract askforprom method
     * 
     * Determines if an employee gets promoted based on age.
     */
    void askforprom(){
        if (Age > 40){
            std::cout << Name << " got promoted" << std::endl;
        }
        else{
            std::cout << Name << " Sorry, no promotion available yet" << std::endl;           
        }
    }
};

/**
 * @class Developer
 * @brief Class representing a software developer
 * 
 * This class inherits from Employee and demonstrates inheritance
 * by extending the base class with additional attributes and methods.
 */
class Developer: public Employee{
    // Developer can access protected members but not private members of Employee
public:
    string Fav_pl;  ///< Developer's favorite programming language
    
    /**
     * @brief Constructor for the Developer class
     * @param name The developer's name
     * @param company The company name
     * @param age The developer's age
     * @param fav_pl Favorite programming language
     * 
     * Uses constructor initialization list to call base class constructor
     */
    Developer(string name, string company, int age, string fav_pl): Employee(name, company, age){
        Fav_pl = fav_pl;
    }
    
    /**
     * @brief Display developer's programming language preference
     */
    void geek(){
        std::cout << Name << " is a " << Fav_pl << " geek" << std::endl;
    }
    
    /**
     * @brief Overridden method demonstrating polymorphism
     * 
     * This demonstrates method overriding, a form of runtime polymorphism.
     */
    void introduce_yourself(){
        std::cout << "I am a developer specialized in " << Fav_pl << std::endl;
    }
};

/**
 * @class Teacher
 * @brief Class representing a teacher
 * 
 * This class also inherits from Employee, demonstrating
 * how multiple classes can inherit from a common base class.
 */
class Teacher:public Employee{ // By default the inheritance is private 
public:
    string Subject;  ///< Subject taught by the teacher
    
    /**
     * @brief Method for lesson preparation
     * 
     * Shows how derived classes can add their own methods.
     */
    void preprelesson(){
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
    
    /**
     * @brief Constructor for the Teacher class
     * @param name The teacher's name
     * @param company The school/institution name
     * @param age The teacher's age
     * @param subject Subject taught by the teacher
     */
    Teacher(string name, string company, int age, string subject): Employee(name, company, age){
        Subject = subject;
    }
};

/**
 * @brief Main function - entry point of the program
 * @return 0 on successful execution
 * 
 * Demonstrates creation and use of different objects,
 * illustrating inheritance, polymorphism, and method overriding.
 */
int main(){
    // Create an Employee object
    Employee Emp1 = Employee("Max", "UTM", 33);
    // Alternative way (not used):
    // Emp1.Name = "Max";
    // Emp1.company = "UTM"; 
    // Emp1.Age = 55; 
    
    // Call method on the Employee object
    Emp1.introduce_yourself();

    // Create another Employee object
    Employee Emp2 = Employee("Hex", "UKT", 66);
    
    // Use setter method to modify property
    Emp2.setName("KAKA");
    Emp2.introduce_yourself();
    
    // Create a Developer object (derived from Employee)
    Developer Emp3 = Developer("Dex", "EEE", 22, "C++"); 
    
    // Call methods on different objects
    Emp1.askforprom();
    Emp2.askforprom();
    Emp3.geek();
    Emp3.askforprom();
    
    // Create a Teacher object (also derived from Employee)
    Teacher Emp4 = Teacher("ELON", "WEW", 34, "English");
    Emp4.introduce_yourself();
    Emp4.askforprom();
    Emp4.preprelesson();
    
    // Demonstrate polymorphism using a base class pointer
    Employee* e1 = &Emp3; 
    e1->introduce_yourself(); // Calls Developer's version due to virtual function
    
    return 0;
}

/**
 * CONSTRUCTORS RULES: 
 * 1. Doesn't have a return type
 * 2. Has the same name as the class it belongs to 
 * 3. Must be public for beginners 
 */

/**
 * ABSTRACTION: 
 * Hiding complex things behind procedures that make things look simple.
 * Abstract classes cannot be instantiated directly and may contain
 * pure virtual functions that derived classes must implement.
 */

/**
 * POLYMORPHISM (many forms):
 * Allows objects to be treated as instances of their parent class
 * while executing methods specific to their actual derived class.
 * 
 * Two types:
 * 1. Compile-time (static) polymorphism - function overloading
 * 2. Runtime (dynamic) polymorphism - function overriding with virtual functions
 */

/**
 * ENCAPSULATION:
 * Bundling of data and methods that operate on that data within a single unit (class),
 * and restricting access to some of the object's components.
 */

/**
 * INHERITANCE:
 * Mechanism where a new class inherits properties and behavior 
 * from an existing class. The existing class is called the base/parent class,
 * and the new class is the derived/child class.
 */