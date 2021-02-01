/**        
* @file  Bucket.cpp  
* @description Creating an array in the heap memory area in which bucket objects are kept,
*              adding and deleting balls to the bucket, writing the RAM addresses of the balls and buckets,
*			   reversing the buckets and balls according to the selection, printing and placing the buckets and balls in reverse.
* @course Sakarya University - Data Structures Homework
* @date  03.11.2019
* @author Berkay Şahin - https://github.com/berkaysahin - https://www.linkedin.com/in/berkaysahin3/ - iletisim@berkaysahin.info
*         Özge Kurt    - https://github.com/ozgeKrt     - https://www.linkedin.com/in/%C3%B6zge-kurt-104a9b1a2/ - ozge.beydam@gmail.com */

#include "Bucket.hpp"
#include "Ball.hpp"
#include <cstdlib>
#include <stdlib.h>

void Bucket::RandomColor()
{
	int RndColor = rand() % 13 + 1;
	BucketColor = RndColor;
}

int Bucket::getColor()
{
	return BucketColor;
}

void Bucket::createBall()
{
	ball = new Ball();
	ball->setBallCharacter();
}

void Bucket::deleteBall()
{
	ball = NULL;
	delete ball;
}