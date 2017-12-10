#pragma once
#include <vector>
#include <queue>
#include<iostream>
#include <functional>
#include "PrintJob.h"
#include "Printer.h"

class PrintQueue
{
private:
	PrintJob* task;
	int numItems;
	std::priority_queue<PrintJob*, std::vector<PrintJob*>, PrintJob> printQueue;
	std::vector<PrintJob*> orderPrinted;
	std::vector<PrintJob*> orderReceived;
	Printer printer1;
	Printer printer2;
	Printer printer3;
	Printer printer4;

public:
	PrintQueue() : numItems(0) {}
	void insertPrintQ(PrintJob* job);
	void setOrderReceived(PrintJob* j);
	PrintJob* getOrderReceived(int index)
		{ return orderReceived.at(index);}
	void printerManager(int printers);
	double getTotalPrintTime();
	void printOrderReceived();
	void printOrderPrinted();
};