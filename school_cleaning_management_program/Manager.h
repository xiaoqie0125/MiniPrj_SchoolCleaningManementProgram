#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "Room.h"
#include "Student.h"

class Manager {

public:
	Manager();

	void registerNewRoom(const Room* nRoom);
	void registerNewStudent(const Student* nStudent);
	bool arrangeTask();
	bool cleaningEnd(const std::string roomNo);
	bool printOrder(const std::string roomNo);
	void printLog(const std::string stuId);
	void showRoomList();
	void showStudentList();
	void showWorkingRoom();
	void showStudentAtRest();

	void showMenue();
	void showRoomType();

private:

	std::vector<Room*> _roomList;
	std::vector<Room*> _cRoomList;// just arranged room list
	std::vector<Student*> _stuList;

	std::vector<Room*>::iterator _roomItr;
	std::vector<Student*>::iterator _stuItr;

	int getRestStudentNum();
	void moveNextStu();

};

#endif

