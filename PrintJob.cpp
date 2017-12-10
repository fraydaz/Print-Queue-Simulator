#include"PrintJob.h"
using namespace std;

// determine job size based on number of pages (s, m, l, xl)
int PrintJob::getJobSize() const
{
	int jobSize;
	if (numPages <= 10)
		jobSize = 1;
	else if (11 <= numPages  && numPages <= 25)
		jobSize = 2;
	else if (26 <= numPages  && numPages <= 50)
		jobSize = 3;
	else
		jobSize = 4;

	return jobSize;
}

bool PrintJob::operator()(PrintJob* p1, PrintJob* p2)
{
	return p1->getJobSize() > p2->getJobSize();
}