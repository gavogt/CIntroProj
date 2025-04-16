#pragma once
#ifndef CYBORG_H
#define CYBORG_H

#include <time.h>

typedef struct {
	int id;
	int age;
	char name[50];
	struct tm created;

} AlienCyborg;

const char* GetAge(int age);

#endif // !CYBORG_H

