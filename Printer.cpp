// Printer.h is a header file containing a Printer class
// that gets print jobs from the PrintQueue and calculates
// total printing time for each printer. It also contains a 
// function that returns the printer status
#include "Printer.h"
#include <iostream>

void Printer::startPrint(PrintJob* current)
{
	int pages = current->getNumPages();
	double printTime = (pages / PRINT_RATE) * 60;	// seconds
	int time = 0;
	int tick = 1;
	while (time < printTime)
	{
		time += tick;
		// printer is busy
		isFree = false;
	}
	std::cout << "Printing complete...\n";
	totalTime += printTime / 60;
	isFree = true;
}
bool Printer::printerAvail()
{
	if (isFree)
		return true;
	else
		return false;
}
