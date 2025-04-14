#pragma once
#ifndef CYBORG_H
#define CYBORG_H

typedef struct {
	char name[50];
	int age;
} AlienCyborg;

const char* GetAge(int age);

#endif // !CYBORG_H

