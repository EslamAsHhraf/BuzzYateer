#pragma once
#include"MarsStation.h"
#include<bits/stdc++.h>
using namespace std;
class MarsStation;
class UI
{
	MarsStation* Master;
public:
	UI(MarsStation* Master);
	void ReadInputFile(ifstream& InputFile);
	void PrintinOutputFile(ofstream& OutputFile);
};

