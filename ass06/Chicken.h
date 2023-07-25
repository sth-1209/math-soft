/**
 * @file Chicken.h
 * @author Shentu Hui (sth@ubuntu)
 * @brief A class of Chicken, command: cmake. | make | make install
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

/**
 * What are chicken have?
 * 
 */
class Chicken
{
private:
    int age;  /**< The age of a Chicken */
    int ID;	 /**< The ID of a Chicken */
    double weight;		/**< The weight of a Chicken */


public:
    /** 
     * Construct a chicken.
     * 
     * @param _a to set the age.
     * @param _I to set the ID.
     * @param _w to set the weight.
     */
    Chicken(int _a, int _I, double _w) : age(_a), ID(_I), weight(_w) {};

    /** 
     * Long live the chicken!
     * 
     */
    ~Chicken() {
	std::cout << "Chicken will come BACK!" << std::endl;
    };

    /** 
     * Even a duck will sing...
     * 
     */
    void sing () {
	std::cout << "Gegege!ikunikun!" << std::endl;
    };
};
