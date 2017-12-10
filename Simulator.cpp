#include "Simulator.h"

// create new print job every 30 seconds until all tasks are complete
void PrinterSim::startSimulation(int jobs, int printers)
{
	totalJobs = jobs;
	numPrinters = printers;
	int tick = 1,
		jobInterval = 30;

	for (int i = 0; i < totalJobs; i++)
	{
		int time = 0;
		while (time < jobInterval)
			time += tick;
		if (printers == 1)
		{
			PrintJob* newJob;
			newJob = new PrintJob;
			myQueue.setOrderReceived(newJob);
			std::cout << "\nCreating new print job...\n";
			myQueue.insertPrintQ(newJob);
		}
		else
		{
			PrintJob* job = myQueue.getOrderReceived(i);
			std::cout << "\nCreating new print job...\n";
			myQueue.insertPrintQ(job);
		}
		runSimulation();
	}
}
// use the queue's printer manager with number of printers to use
void PrinterSim::runSimulation()
{
	myQueue.printerManager(numPrinters);
}
/*----------------------------------------------------------------------*/
void PrinterSim::showStats()
{
	std::cout << "The print tasks arrived in this order:\n";
	myQueue.printOrderReceived();
	std::cout << "The print tasks were printed in this order:\n";
	myQueue.printOrderPrinted();
	std::cout << "Number of printer(s) used: "
		<< numPrinters;
	std::cout << "\nTotal time to compelete all printing tasks: ";
	std::cout << std::setprecision(2) << std::fixed << myQueue.getTotalPrintTime()
		<< " minutes.";
	std::cout << "\n---------------------------------------------------------------\n";
}