#include"MarsStation.h"
int main()
{
	
	string Input = "Input.txt";
	string Output = "Output.txt";
	MarsStation MS(Input, Output);
	MS.GetInput();
	MS.Simulate();
	MS.GetOutput();
	return 0;
}