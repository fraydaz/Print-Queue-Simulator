#include "PrintQueue.h"

void PrintQueue::insertPrintQ(PrintJob* job)
{
	printQueue.push(job);
}
/*-------------------------------------------------------------*/
void PrintQueue::setOrderReceived(PrintJob* job)
{
	orderReceived.push_back(job);
}
/*-------------------------------------------------------------*/
void PrintQueue::printerManager(int printers)
{
	while (!printQueue.empty())
	{
		// check status of each printer
		if (printer1.printerAvail())
		{
			std::cout << "Printing on printer 1...\n";
			printer1.startPrint(printQueue.top());
			orderPrinted.push_back(printQueue.top());
			printQueue.pop();
		}

		else if (printer2.printerAvail() && printers > 1)
		{
			std::cout << "\nPrinting on printer 2...\n";
			printer2.startPrint(printQueue.top());
			orderPrinted.push_back(printQueue.top());
			printQueue.pop();
		}
		else if (printer3.printerAvail() && printers > 2)
		{
			std::cout << "\nPrinting on printer 3...\n";
			printer3.startPrint(printQueue.top());
			orderPrinted.push_back(printQueue.top());
			printQueue.pop();
		}
		else if (printer4.printerAvail() && printers == 4)
		{
			std::cout << "\nPrinting on printer 4...\n";
			printer4.startPrint(printQueue.top());
			orderPrinted.push_back(printQueue.top());
			printQueue.pop();
		}
	}
}
/*-------------------------------------------------------------*/
double PrintQueue::getTotalPrintTime()
{
	double total = printer1.getPrintTime() + printer2.getPrintTime()
		+ printer3.getPrintTime() + printer4.getPrintTime();

	printer1.resetTotalTime();
	printer2.resetTotalTime();
	printer3.resetTotalTime();
	printer4.resetTotalTime();
	return total;
}
/*-------------------------------------------------------------*/
void PrintQueue::printOrderReceived()
{
	std::vector<PrintJob*>::iterator iter;
	for (iter = orderReceived.begin(); iter != orderReceived.end(); iter++)
	{
		std::cout << (*iter)->getNumPages() << " page(s)\n";
	}
	std::cout << std::endl << std::endl;
}
/*-------------------------------------------------------------*/
void PrintQueue::printOrderPrinted()
{
	while (!orderPrinted.empty())
	{
		PrintJob* current = orderPrinted.front();
		std::cout << current->getNumPages() << " page(s)\n";
		orderPrinted.erase(orderPrinted.begin());
	}
	/*while (!printQueue.empty())
	{
		PrintJob* front = printQueue.top();
		std::cout << front->getNumPages() << std::endl;
		printQueue.pop();
	}*/
}