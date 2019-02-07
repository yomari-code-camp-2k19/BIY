// STL's !!!!
#pragma once
#include <vector>
#include <string>

struct cpu {
	std::string name;
	float speed;
	short unsigned int core;
	unsigned int power;
	float avgRate;
	float price;
	int minVer;
	int maxVer;
};

struct motherboard {
	std::string name;
	std::string socket;
	std::string formFactor;
	unsigned int ramSlot;
	unsigned int maxRam;
	float avgRate;
	float price;
	int minVer;
	int maxVer;
};

struct cpuCooler {
	std::string name;
	unsigned int minRpm;
	unsigned int maxRpm;
	unsigned int noiseLevel;
	float avgRate;
	float price;
	int minVer;
	int maxVer;
};

struct memory {
	std::string name, speed, type;
	int cas;
	unsigned int numModule, eachModule, size;
	float avgRating;
	float price;
	int minVer;
	int maxVer;
};

struct storage {
	std::string name, series;
	std::string form, type, capacity;
	unsigned int cache;
	float avgRate;
	float price;
	int minVer;
	int maxVer;
};

struct videoCard {
	std::string name, series, chipset;
	unsigned int memory;
	float ClkCore;
	float avgRate;
	float price;
	int minVer;
	int maxVer;
};

struct powerSupply {
	std::string name, series, form, efficiency;
	int power;
	std::string modular;
	float avgRate;
	float price;
	int minVer;
	int maxVer;
};

struct casing {
	std::string name, type;
	float price;
	int minVer;
	int maxVer;
};