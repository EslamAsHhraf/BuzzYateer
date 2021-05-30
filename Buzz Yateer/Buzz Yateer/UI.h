#pragma once
#include"MarsStation.h"
#include<bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
class MarsStation;
class UI
{
	MarsStation* Master;
public:
	UI(MarsStation* Master);
	void ReadInputFile(ifstream& InputFile);
	void PrintinOutputFile(ofstream& OutputFile);
	void Interactive_Mode();
};

