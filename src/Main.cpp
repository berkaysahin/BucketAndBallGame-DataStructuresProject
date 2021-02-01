/**        
* @file  Main.cpp  
* @description Creating an array in the heap memory area in which bucket objects are kept,
*              adding and deleting balls to the bucket, writing the RAM addresses of the balls and buckets,
*			   reversing the buckets and balls according to the selection, printing and placing the buckets and balls in reverse.
* @course Sakarya University - Data Structures Homework
* @date  03.11.2019
* @author Berkay Şahin - https://github.com/berkaysahin - https://www.linkedin.com/in/berkaysahin3/ - iletisim@berkaysahin.info
*         Özge Kurt    - https://github.com/ozgeKrt     - https://www.linkedin.com/in/%C3%B6zge-kurt-104a9b1a2/ - ozge.beydam@gmail.com */

#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include "Bucket.hpp"
#include "BucketControl.hpp"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_ALL, "Turkish");
    srand(time(0));
	//srand (time(NULL));
	system("cls");

	int BucketCount, Select;

	do{
		cout << "How many buckets to create: ";
		cin >> BucketCount;
	}while(BucketCount < 1);

    BucketControl *bucketControl = new BucketControl;

	Bucket **BucketArray = new Bucket *[BucketCount];

	Bucket *tmpBucket;
    
	for (int i = 0;i < BucketCount;i++)
	{
		tmpBucket = new Bucket();
		BucketArray[i] = tmpBucket;
	}

	for (int i = 0;i < BucketCount; i++){
        BucketArray[i]->RandomColor();
    }
	
	char ballChar;

	do
	{
		cout << endl;
		for (int i = 0;i < BucketCount;i++)
		{	
			if(BucketArray[i]->ball == 0){
				ballChar = '-';
			}else{
				ballChar = BucketArray[i]->ball->getBall();
			}

			cout << i + 1 << ". Bucket" << endl;

            SetConsoleTextAttribute(hConsole, BucketArray[i]->getColor());
			cout << "  .|." << endl;
			cout << " .   ." << endl;
			cout << ".     ." << endl;
			cout << "#     #" << endl;
			cout << "#  " << ballChar << "  #" << endl;
			cout << "#     #" << endl;
			cout << "#######" << endl;

			cout << "Bucket RAM Adress: " << BucketArray[i] << endl;

			cout << "Ball RAM Adress: ";
			BucketArray[i]->ball == 0 ? cout << "NULL":  cout << BucketArray[i]->ball;

			SetConsoleTextAttribute(hConsole, 15);

			cout << endl << endl;
		}
		
		cout << endl;
		cout << "[1]. Place balls " << endl;
		cout << "[2]. Delete balls" << endl;
		cout << "[3]. Swap buckets" << endl;
		cout << "[4]. Swap balls" << endl;
		cout << "[5]. Put the buckets in reverse order" << endl;
		cout << "[6]. Put the balls in reverse order" << endl;
		cout << "[7]. Exit";
		cout << endl << ">> ";
		cin >> Select;
		
		switch (Select)
		{
		case 1:
			bucketControl->SetBalls(BucketArray, BucketCount);
			break;
		case 2:
			bucketControl->DeleteBalls(BucketCount, BucketArray);
			break;
		case 3:
			int firstBucket, secondBucket;
			cout << "1. Bucket: ";
			cin >> firstBucket;
			cout << "2. Bucket: ";
			cin >> secondBucket;
            
			if(Select > 0 || Select <= BucketCount){
				bucketControl->ChangeBuckets(firstBucket, secondBucket, BucketArray);
			}
			break;
		case 4:
			int firstBall, secondBall;
			cout << "1. Ball: ";
			cin >> firstBall;
			cout << "2. Ball: ";
			cin >> secondBall;
			if(Select > 0 || Select <= BucketCount){
				bucketControl->ChangeBalls(firstBall, secondBall, BucketArray);
			}
            break;
		case 5:
			bucketControl->PutTheBucketsInReverseOrder(BucketCount, BucketArray);
            break;
		case 6:
			bucketControl->PutTheBallsInReverseOrder(BucketCount, BucketArray);
            break;
		case 7:
			break;
		default:
			cout << "Use menu numbers."<< endl; 
			continue;
		}
	} while (Select != 7);

	for (int i = 0;i < BucketCount; i++){
		bucketControl->DeleteBalls(BucketCount, BucketArray);
	}

	delete  BucketArray, tmpBucket, bucketControl;

	cin.get();
	cin.ignore();
	return 0;
}