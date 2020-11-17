#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

class Action {
public:
	Action():_roomNo("000"), _charge("none") {

	}
	Action(std::string roomNo, std::string charge): _roomNo(roomNo), _charge(charge) {

	}

	void print() {
		std::cout << "roomNo: " << this->_roomNo << " charge: " << this->_charge << std::endl;
	}

private:
	const std::string _roomNo;
	const std::string _charge;
};


class Student {

public:
	Student() : _stu_id(""), _name(""), _state(true)  {

	}

	Student(const std::string stu_id, const std::string name) : _stu_id(stu_id), _name(name), _state(true) {

	}

	std::string getStudentID() {
		return _stu_id;
	}

	void printLog() {

		std::cout << "name: " << this->_name << std::endl;

		for (std::vector<Action>::iterator itr = this->ActionList.begin();
			itr != this->ActionList.end();
			itr++) {

			(*itr).print();
		}
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
