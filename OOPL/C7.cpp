/**
 * * Eshan Nahar
 * Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and returns the population of the state
 */

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	map<string, long> statePopulation;
	statePopulation["First"] = 39538223;
	statePopulation["Second"] = 29145505;
	statePopulation["Third"] = 21538187;
	statePopulation["Fourth"] = 20201249;
	statePopulation["Fifth"] = 13002700;
	statePopulation["Sixth"] = 12812508;
	statePopulation["Seventh"] = 11799448;
	statePopulation["Eighth"] = 10711908;
	statePopulation["Ninth"] = 10439388;
	statePopulation["Tenth"] = 10077331;
	
	string stateName;
	cout << "Enter name of a state: ";
	getline(cin, stateName);
	auto it = statePopulation.find(stateName);
	if(it != statePopulation.end()) cout << "Population of " << stateName << " is " << it->second << endl;
	else cout << "State not present\n";
	return 0; 
}