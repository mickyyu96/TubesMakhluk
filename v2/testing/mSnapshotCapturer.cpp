// mSnapshotCapturer.cpp
#include "../header/World.h"
#include "../header/Rabbit.h"
#include "../header/LMakhluk.h"
#include "../header/SnapshotCapturer.h"
#include <iostream>
using namespace std;


int main()
{
	SnapshotCapturer::getCapturerInstance()->captureSnapshot();
	cout << "Snapshot saved as snapshot.txt, please check it now!" << endl;
	system("PAUSE");
	
	World::getWorldInstance()->getObjects()->Add(new Rabbit(Point(10,10)));
	SnapshotCapturer::getCapturerInstance()->captureSnapshot();
	cout << "New snapshot has been saved as snapshot.txt, please check it now!" << endl;
	system("PAUSE");
	
	return 0;
}
