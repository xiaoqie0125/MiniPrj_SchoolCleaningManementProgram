#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

class Action {
public:
	Action();
	Action(std::string roomNo, std::string charge);

private:
	std::string _roomNo;
	std::string _charge;
};


class Student {

public:
	Student() : _stu_id(""), _name(""), _state(true)  {

	}

	Student(const std::string stu_id, const std::string name) : _stu_id(stu_id), _name(name), _state(true) {

	}

	void changeState() {
		this->_state = !this->_state;
	}

	bool isArranged() {
		return !this->_state;
	}

	void record(const std::string roomNo, const std::string charge) {
		Action action(roomNo, charge);
		this->ActionList.push_back(action);
	}

	void printStuInfo() {
		std::cout << "id: " << this->_stu_id << std::endl;
		std::cout << "name: " << this->_name << std::endl;
	}

private:
	std::string _stu_id;
	std::string _name;
	bool _state;
	std::vector<Action> ActionList;
	
};

#endif
