#include<iostream>
#include<stdio.h>
int main(void)
{
	float alt, temp, interclimb,val1, val2;
	int lowT, lowA;
	std::cout<<"\nEnter Altitude and Temperature: ";
	std::cin>>alt>>temp;
	while(alt<0 || alt>10000 || temp < -20 || temp >40)
	{
		std::cout<<"\nYour Temperature value must be between -20 and 40. Your altitude value must be between 0 and 10000. \nEnter Altitude and Temperature: ";
		std::cin>>alt>>temp;
	}
	lowA = alt/2000;
	lowT = (temp+20)/20;

	double table[6][4]=
	{
		{830.0,770.0,705.0,640.0},
		{720.0,655.0,595.0,535.0},
		{645.0,585.0,525.0,465.0},
		{530.0,475.0,415.0,360.0},
		{420.0,365.0,310.0,250.0},
		{310.0,255.0,200.0,145.0}
	};
	val1 = table[lowA][lowT] + (alt/2000.0 - lowA)*(table[lowA+1][lowT] - table[lowA][lowT]);
	val2 = table[lowA][lowT+1] + (alt/2000.0 - lowA)*(table[lowA+1][lowT+1] - table[lowA][lowT+1]);
	interclimb = val1 + ((temp+20)/20.0 - lowT)*(val2-val1);
	std::cout<<"\nExpected Climb Rate: "<<interclimb<<" ft/min";

	return 0;
}
