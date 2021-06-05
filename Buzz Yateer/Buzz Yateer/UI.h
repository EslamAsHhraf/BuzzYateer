#pragma once
#include"MarsStation.h"
#include<bits/stdc++.h>
#include <fstream>
#include <string>
#include<Windows.h>
using namespace std;
class MarsStation;
class UI
{
	MarsStation* Master;
public:
	UI(MarsStation* Master);
	void Interactive_Mode();
	void Start();
	void Mode_1();
	void Mode_2();
	void Mode_3();
	void decide();

};

