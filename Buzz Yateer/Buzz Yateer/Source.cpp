#include"MarsStation.h"
int main()
{	
	string Input = "Input.txt";
	string Output = "Output.txt";
	MarsStation MS(Input, Output);
	MS.ReadInputFile();
	MS.Simulate();
	MS.PrintinOutputFile();
	return 0;
}