// SnapshotCapturer.cpp

#include "../header/SnapshotCapturer.h"
#define SNAPSHOT_CAPTURE_DIRECTORY "snapshot.txt"
using namespace std;

SnapshotCapturer* SnapshotCapturer::capturerInstance = new SnapshotCapturer(SNAPSHOT_CAPTURE_DIRECTORY);

SnapshotCapturer::SnapshotCapturer(const string& _filename) : directory(_filename)
{
}

void SnapshotCapturer::captureSnapshot()
{
	//World::getWorldInstance()->lockWorld();
	saveOldBuf();

	ofstream output(directory);
	cout.rdbuf(output.rdbuf());

	PrintWorldMap();

	resetCoutBuf();
	//World::getWorldInstance()->unlockWorld();
}
