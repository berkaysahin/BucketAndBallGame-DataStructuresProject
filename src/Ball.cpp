/**        
* @file  Ball.cpp  
* @description Creating an array in the heap memory area in which bucket objects are kept,
*              adding and deleting balls to the bucket, writing the RAM addresses of the balls and buckets,
*			   reversing the buckets and balls according to the selection, printing and placing the buckets and balls in reverse.
* @course Sakarya University - Data Structures Homework
* @date  03.11.2019
* @author Berkay Şahin - https://github.com/berkaysahin - https://www.linkedin.com/in/berkaysahin3/ - iletisim@berkaysahin.info
*         Özge Kurt    - https://github.com/ozgeKrt     - https://www.linkedin.com/in/%C3%B6zge-kurt-104a9b1a2/ - ozge.beydam@gmail.com */

#include "Ball.hpp"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

void Ball::setBallCharacter()
{ 
    char chars[] = "ABCDEFGHIJKLMNOPRSTUVYZX";
    Character = chars[rand() % 23];
}
char Ball::getBall()
{
	return Character;
}