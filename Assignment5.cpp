/*
A print queue algorithm assigns printing tasks to printers based on the number of pages to be printed. 
The tasks are grouped by small jobs (less than 10 pages), medium jobs (11-25 pages), 
large jobs (26-50 pages) and very large jobs (51 pages and up). Each printer can print 7 pages per minute. 
Write a program to prioritize print jobs and simulate printing times for systems that have 1 to 4 printers.  
Assume print requests happen every 30 seconds and that requests fit into one of the four job sizes listed above.

*/
#include <iostream>
#include "Simulator.h"

using namespace std;

int main() {

	PrinterSim simulator;
	int numJobs;
	const int PRINTERS = 4;

	cout << "How many print jobs would you like to simulate? ";
	cin >> numJobs;

	// run simulation for 1, 2, 3, and 4 printers
	for (int i = 0; i < PRINTERS; i++)
	{
		simulator.startSimulation(numJobs, i+1);

		cout << endl << endl << "Simulation results for "
			<< i + 1 << " printer(s):\n\n";
		simulator.showStats();
	}
	return 0;
}
/*

PROBLEM:

Print queue only uses printer #1. It only starts printing next print job when first is complete.

*/