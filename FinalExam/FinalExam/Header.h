#pragma once

#include <iostream>

using namespace std;

class Person
{
public:
	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }

protected:

	int age;
	string name;
	bool health;
	string position;
};

class HealthyPerson : public Person {

public:
	void setHealthy(bool Healthy) { this->health = Healthy; }
	void checkNeighbor(Person person) {
		if (person.position == "up") {

			person.health == false;

		}
		if (person.position == "down") {

			person.health == false;

		}
		if (person.position == "left") {

			person.health == false;

		}
		if (person.position == "right") {

			person.health == false;

		}
	}

private:

	

};

class SickPerson : public Person {

public:

	void setHealthy(bool Healthy) { this->healthy = Healthy; }
	void checkNeighbor(Person person) {
		if (person.position == "up") {

			person.health == false;

		}
		if (person.position == "down") {

			person.health == false;

		}
		if (person.position == "left") {

			person.health == false;

		}
		if (person.position == "right") {

			person.health == false;

		}

		turns++;
	}
	void setTurns(int turns) { this->turns = turns; }
private:

	bool healthy = false;
	int turns;


};

class RecoveredPerson : public Person {

public:

private:

	const bool healthy = true;

};

class ImmunedPerson : public Person {

	void checkSick(Person person) {

		if (person.health == false) {

			if (this->turn > 3) {

				healthy = false;

			}
		}

	}


private:

	bool healthy = true;
	bool hasVaccine = true;
	int turn;

};

