#pragma once
#include<iostream>
#include <cstdlib>
#include<iomanip>
#include "PrintQueue.h"

class PrinterSim
{
private:
	int totalJobs,
		numPrinters;
	PrintQueue myQueue;

public:
	PrinterSim() {}
	void startSimulation(int jobs, int printers);
	void runSimulation();
	void showStats();
};