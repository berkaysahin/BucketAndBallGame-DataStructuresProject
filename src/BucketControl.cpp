/**        
* @file  BucketControl.cpp  
* @description Creating an array in the heap memory area in which bucket objects are kept,
*              adding and deleting balls to the bucket, writing the RAM addresses of the balls and buckets,
*			   reversing the buckets and balls according to the selection, printing and placing the buckets and balls in reverse.
* @course Sakarya University - Data Structures Homework
* @date  03.11.2019
* @author Berkay Şahin - https://github.com/berkaysahin - https://www.linkedin.com/in/berkaysahin3/ - iletisim@berkaysahin.info
*         Özge Kurt    - https://github.com/ozgeKrt     - https://www.linkedin.com/in/%C3%B6zge-kurt-104a9b1a2/ - ozge.beydam@gmail.com */

#include "BucketControl.hpp"
#include "Bucket.hpp"
#include "Ball.hpp"
#include <cstdlib>
#include <stdlib.h>

void BucketControl::ChangeBuckets(int Bucket1, int Bucket2, Bucket **BucketsArray)
{
	
	Bucket *tmpBucket;
	tmpBucket = BucketsArray[Bucket1 - 1];
	BucketsArray[Bucket1 - 1] = BucketsArray[Bucket2 - 1];
	BucketsArray[Bucket2 - 1] = tmpBucket;
}

void BucketControl::ChangeBalls(int Ball1, int Ball2, Bucket** BucketsArray)
{
	Ball *tmpBall;
	tmpBall = BucketsArray[Ball1 - 1]->ball;
	BucketsArray[Ball1 - 1]->ball = BucketsArray[Ball2 - 1]->ball;
	BucketsArray[Ball2 - 1]->ball = tmpBall;
}

void BucketControl::PutTheBucketsInReverseOrder(int BucketCount, Bucket** BucketsArray)
{ 
	Bucket *tmpBucket;
	for (int i = 0;i < BucketCount; i++)
	{
		tmpBucket = BucketsArray[BucketCount - 1];
		BucketsArray[BucketCount - 1] = BucketsArray[i];
		BucketsArray[i] = tmpBucket;

		BucketCount--;
	}
}

void BucketControl::PutTheBallsInReverseOrder(int BucketCount, Bucket **BucketsArray)
{
	Ball *tmpBall;
	for (int i = 0;i < BucketCount; i++)
	{
		tmpBall = BucketsArray[BucketCount - 1]->ball;
		BucketsArray[BucketCount - 1]->ball = BucketsArray[i]->ball;
		BucketsArray[i]->ball = tmpBall;

		BucketCount--;
	}
}

void BucketControl::SetBalls(Bucket** BucketsArray, int BucketCount){
	for (int i = 0;i < BucketCount; i++){
		BucketsArray[i]->createBall();
	}
}

void BucketControl::DeleteBalls(int BucketCount, Bucket **BucketsArray)
{
	for(int i = 0; i < BucketCount; i++){
		BucketsArray[i]->deleteBall();
	}
}
