#include <iostream>
#include <string>
using namespace std;

#include "header.h"
#include "manusia.h"

int main() { //composisi
	manusia* varManusia = new manusia("jono");
	delete varManusia;
	return 0;
}