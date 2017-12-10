#pragma once
#include <cstdlib>
#include <iostream>
class PrintJob
{
private:
	int numPages,
		jobSize;
public:
	/* constructor initializes print
	job object with random number of pages */
	PrintJob() : numPages(rand() % 100 + 1) {}
	int getNumPages() const
		{ return numPages;	}
	int getJobSize() const;
	bool operator()(PrintJob* p1, PrintJob* p2);
};