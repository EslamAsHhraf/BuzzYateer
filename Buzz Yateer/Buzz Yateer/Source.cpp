#include"MarsStation.h"
int main()
{
	int x;
	cin >> x;
	string Input = "Input.txt";
	string Output = "Output.txt";
	MarsStation MS(Input, Output);
	MS.GetInput();
	MS.Set_Mode(x);
	MS.Simulate();
	MS.GetOutput();
	//.Choose_Mode(x);
	return 0;
}