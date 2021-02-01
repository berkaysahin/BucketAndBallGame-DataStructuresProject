/**        
* @file  Ball.hpp  
* @description Creating an array in the heap memory area in which bucket objects are kept,
*              adding and deleting balls to the bucket, writing the RAM addresses of the balls and buckets,
*			   reversing the buckets and balls according to the selection, printing and placing the buckets and balls in reverse.
* @course Sakarya University - Data Structures Homework
* @date  03.11.2019
* @author Berkay Şahin - https://github.com/berkaysahin - https://www.linkedin.com/in/berkaysahin3/ - iletisim@berkaysahin.info
*         Özge Kurt    - https://github.com/ozgeKrt     - https://www.linkedin.com/in/%C3%B6zge-kurt-104a9b1a2/ - ozge.beydam@gmail.com */

#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
using namespace std;

class Ball{
    private:
	    char Character;
    public:
        void setBallCharacter();
        char getBall();
};
#endif