#ifndef MAN_POWER_H
#define MAN_POWER_H

#include "Student.h"

#include <string>

// person in charge
class PIC {
public:

	PIC() {

	}
	PIC(const Student* SIC): _SIC(SIC){

	}

	void setStudent(const Student* stu){
		this->_SIC = stu;
	}

	virtual void cleaning() = 0;
	virtual void printOrder() = 0;
protected:

	const Student* _SIC; // student in charge
};

class PIC_Floor : public PIC {
public:
	PIC_Floor():_dustpanVolume(100) {

	}

	PIC_Floor(Student* SIC): PIC(SIC), _dustpanVolume(100) {

	}

	void setdustpanVolume(const int dpv) {
		this->_dustpanVolume = dpv;
	}

	void cleaning() {

		this->_contents.push_back("Prepare a broom and dustpan.");
		this->_contents.push_back("The dustpan volume is " + std::to_string(this->_dustpanVolume));
		this->_contents.push_back("1. Sweep the floor.");
		this->_contents.push_back("2. When the dustpan is full, go to empty it.");
		this->_contents.push_back("Repeat the above action until the floor is clean.");
	}

	void printOrder() {

		Student* student = const_cast<Student*>(this->_SIC);
		student->printStuInfo();
		for (std::vector<std::string>::iterator itr = this->_contents.begin(); itr != this->_contents.end(); itr++) {
			std::cout << *itr << std::endl;
		}
	}

private:
	
	int _dustpanVolume;
	std::vector<std::string> _contents;

};

class PIC_Window : public PIC {

public:
	PIC_Window(): _windowCleaner(100){

	}

	PIC_Window(Student* SIC) : PIC(SIC), _windowCleaner(100) {

	}

	void setwindowCleanerVolume(const int wcv) {
		this->_windowCleaner = wcv;
	}

	void cleaning() {

		this->_contents.push_back("Prepare a clean rag and window cleaner.");
		this->_contents.push_back("The window cleaner volume is " + std::to_string(this->_windowCleaner));
		this->_contents.push_back("1. Polish the window.");
		this->_contents.push_back("2. When the window cleaner is empty, go to refill it.");
		this->_contents.push_back("Repeat the above action until the window is clean.");
	}

	void printOrder() {

		Student* student = const_cast<Student*>(this->_SIC);
		student->printStuInfo();
		for (std::vector<std::string>::iterator itr = this->_contents.begin(); itr != this->_contents.end(); itr++) {
			std::cout << *itr << std::endl;
		}
	}

private:

	int _windowCleaner;
	std::vector<std::string> _contents;

};

class PIC_Seat : public PIC {

public:
	PIC_Seat() {

	}

	PIC_Seat(Student* SIC) : PIC(SIC) {

	}

	void cleaning() {

		this->_contents.push_back("You just arrange these desks in order.");
		this->_contents.push_back("Be aware of safety.");

	}

	void printOrder() {

		Student* student = const_cast<Student*>(this->_SIC);
		student->printStuInfo();
		for (std::vector<std::string>::iterator itr = this->_contents.begin(); itr != this->_contents.end(); itr++) {
			std::cout << *itr << std::endl;
		}
	}

private:
	std::vector<std::string> _contents;
};

class PIC_Balckboard : public PIC {

public:

	PIC_Balckboard():_bbEraser(100){

	}

	PIC_Balckboard(Student* SIC) : PIC(SIC), _bbEraser(100){

	}

	void cleaning() {

		this->_contents.push_back("Prepare a blackboard eraser.");
		this->_contents.push_back("Erase the balckboard until the balckboard is clean.");
	}

	void printOrder() {

		Student* student = const_cast<Student*>(this->_SIC);
		student->printStuInfo();
		for (std::vector<std::string>::iterator itr = this->_contents.begin(); itr != this->_contents.end(); itr++) {
			std::cout << *itr << std::endl;
		}
	}

private:

	int _bbEraser;
	std::vector<std::string> _contents;
};

class PIC_Officeseat : public PIC {

public:

	PIC_Officeseat(){

	}

	PIC_Officeseat(Student* SIC) : PIC(SIC){

	}

	void cleaning() {

		this->_contents.push_back("Please ask your teacher before start work.");
		this->_contents.push_back("Be carefull when cleaning.");
	}

	void printOrder() {

		Student* student = const_cast<Student*>(this->_SIC);
		student->printStuInfo();
		for (std::vector<std::string>::iterator itr = this->_contents.begin(); itr != this->_contents.end(); itr++) {
			std::cout << *itr << std::endl;
		}
	}

private:

	std::vector<std::string> _contents;
};

class PIC_Meetingtable : public PIC {

public:

	PIC_Meetingtable(): _dishcloth(100){

	}

	PIC_Meetingtable(Student* SIC) : PIC(SIC), _dishcloth(100){

	}

	void cleaning() {

		this->_contents.push_back("Prepare a clean dishcloth and some water.");
		this->_contents.push_back("1. Wipe the table using dishcloth.");
		this->_contents.push_back("2. if the dishcloth is dirty, please wash it.");
		this->_contents.push_back("Repeat the above action until the meetingtable is clean.");
	}

	void printOrder() {

		Student* student = const_cast<Student*>(this->_SIC);
		student->printStuInfo();
		for (std::vector<std::string>::iterator itr = this->_contents.begin(); itr != this->_contents.end(); itr++) {
			std::cout << *itr << std::endl;
		}
	}

private:

	int _dishcloth;
	std::vector<std::string> _contents;
};

#endif

