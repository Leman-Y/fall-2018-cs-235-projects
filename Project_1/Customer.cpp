/*
Customer.cpp
Leman Yan
Professor Tiziana Ligorio
CSCI 235, Fall 2018, Project 1
Description: Implement functions for class Customer
*/

#include <iostream>
#include <string>
#include "Customer.hpp"

//Implement default constructor
Customer::Customer()
{
	name_="";
	defective_device_="unknown";
	wait_time_=0;
}

//Implement parameterized constructor
Customer::Customer(string name, string device, int wait_time)
{
	name_=name;
	defective_device_=device;
	wait_time_=wait_time;
}


std::string Customer::getName()
{
	return name_;
}

std::string Customer::getDevice()
{
	return defective_device_;
}

int Customer::getWaitTime()
{
	return wait_time_;
}

void Customer::updateWaitTime(int new_wait_time)
{
	wait_time_ = new_wait_time;
}

	


