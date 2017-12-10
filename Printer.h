// Printer.h is a header file containing a Printer class
// that gets print jobs from the PrintQueue and calculates
// total printing time for each printer. It also contains a 
// function that returns the printer status
#pragma once
#include "PrintJob.h"

class Printer
{
private:
	PrintJob* task;
	bool isFree;
	const double PRINT_RATE = 7.0; // 7 pages / min
	double totalTime = 0.0; // total time for each printer

public:
	Printer() :	isFree(true) {}
	void startPrint(PrintJob* current);
	bool printerAvail();
	double getPrintTime()
		{ return totalTime; }
	void resetTotalTime()
		{ totalTime = 0.0; }
};