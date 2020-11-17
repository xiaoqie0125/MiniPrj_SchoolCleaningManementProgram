#include "Manager.h"

Manager::Manager() {

	//this->_roomItr = this->_roomList.begin();
	//this->_stuItr = this->_stuList.begin();

}

void Manager::showMenue() {
	std::cout << "==========MENU==========" << std::endl;
	std::cout << "1.  Register new room." << std::endl;
	std::cout << "2.  Register new student." << std::endl;
	std::cout << "3.  Arrange task." << std::endl;
	std::cout << "4.  Cleaning end." << std::endl;
	std::cout << "5.  Print order." << std::endl;
	std::cout << "6.  Print log." << std::endl;
	std::cout << "7.  Show room list." << std::endl;
	std::cout << "8.  Show student list." << std::endl;
	std::cout << "9.  Show working room." << std::endl;
	std::cout << "10. Show student at rest." << std::endl;
	std::cout << "11. End program." << std::endl;
}

void Manager::showRoomType() {
	std::cout << "==========ROOM TYPE==========" << std::endl;
	std::cout << "1.  Class room." << std::endl;
	std::cout << "2.  Ofiice room." << std::endl;
	std::cout << "3.  Metting room." << std::endl;
}

void Manager::registerNewRoom(const Room* nRoom) {
	//
	if (this->_roomList.size() == 0) {
		this->_roomList.push_back(const_cast<Room*>(nRoom));
		this->_roomItr = this->_roomList.begin();
		return;
	}
	int dist = this->_roomItr - this->_roomList.begin();
	this->_roomList.push_back(const_cast<Room*>(nRoom));
	this->_roomItr = this->_roomList.begin() + dist;
}

void Manager::registerNewStudent(const Student* nStudent) {
	//
	if (this->_stuList.size() == 0) {
		this->_stuList.push_back(const_cast<Student*>(nStudent));
		this->_stuItr = this->_stuList.begin();
		return;
	}
	int dist = this->_stuItr - this->_stuList.begin();
	this->_stuList.push_back(const_cast<Student*>(nStudent));
	this->_stuItr = this->_stuList.begin() + dist;
}

bool Manager::arrangeTask() {

	bool state = false;
	this->_cRoomList.clear();

	//(*this->_stuItr)->printStuInfo();

	if (this->_roomList.size() == 0) {
		return state;
	}

	while (true) {

		if (this->_roomItr == this->_roomList.end() ) {
			std::cout << "There are no rooms need to cleaning." << std::endl;
			break;
		}

		int mpNum = (*this->_roomItr)->getTotalManpower(); 

		if (mpNum > this->getRestStudentNum()) {
			std::cout << "There are not enougn students go to working." << std::endl;
			break;
		}
		
		std::vector<Student*> arrangeStuList;
		for (int i = 0; i < mpNum; i++) {

			if ((*this->_stuItr)->isArranged() == true) {
				this->moveNextStu();
				i--;
			}

			(*this->_stuItr)->changeState(); // false -> true
			arrangeStuList.push_back(*this->_stuItr);
			this->moveNextStu();
		}

		(*this->_roomItr)->setManpower(arrangeStuList);

		(*this->_roomItr)->room_cleaning();

		this->_cRoomList.push_back(*this->_roomItr);

		this->_roomItr++;
		state = true;
	}

	return state;

}

int Manager::getRestStudentNum() {
	int cnt = 0;
	for (std::vector<Student*>::iterator tmpItr = this->_stuList.begin(); tmpItr != this->_stuList.end(); tmpItr++) {
		if ((*tmpItr)->isArranged() == false) {
			cnt++;
		}
	}
	return cnt;
	
}

void Manager::moveNextStu() {

	while (1) {
		
		int rNum = this->getRestStudentNum();
		if (rNum == 0) {
			this->_stuItr = this->_stuList.begin();
			break;
		}

		this->_stuItr++;

		if (this->_stuItr == this->_stuList.end()) {
			this->_stuItr = this->_stuList.begin();
		}

		if ((*this->_stuItr)->isArranged() == false) {
			break;
		}
	}

}

bool Manager::cleaningEnd(const std::string roomNo) {
	bool state = false;
	for (std::vector<Room*>::iterator itr = this->_roomList.begin(); itr != this->_roomList.end(); itr++) {
		if (roomNo == (*itr)->getRoomNo()) {
			if ((*itr)->isCleaned() == true) {
				std::cout << "the room " << roomNo << " is already cleand." << std::endl;
				break;
			}
			(*itr)->room_cleaning_end();
			state = true;
			break;
		}
	}


	return state;
}

bool Manager::printOrder(const std::string roomNo) {
	bool state = false;
	for (std::vector<Room*>::iterator itr = this->_roomList.begin(); itr != this->_roomList.end(); itr++) {
		if (roomNo == (*itr)->getRoomNo()) {
			(*itr)->printOrder();
			state = true;
			break;
		}
	}
	return state;

}

bool Manager::printLog(const std::string stuId) {
	bool state = false;
	for (std::vector<Student*>::iterator itr = this->_stuList.begin();
		itr != this->_stuList.end();
		itr++) {

		if (stuId == (*itr)->getStudentID()) {
			(*itr)->printLog();
			state = true;
		}
	}

	return state;
}

void Manager::showRoomList() {

	std::cout << "There are " << this->_roomList.size() << " rooms." << std:: endl;
	for (std::vector<Room*>::iterator itr = this->_roomList.begin(); itr != this->_roomList.end() ; itr++) {
		(*itr)->printRoomInfo();
	}
}

void Manager::showStudentList() {

	std::cout << "There are " << this->_stuList.size() << " students." << std::endl;
	for (std::vector<Student*>::iterator itr = this->_stuList.begin(); itr != this->_stuList.end(); itr++) {
		(*itr)->printStuInfo();
	}
}

bool Manager::showWorkingRoom() {

	bool state = false;

	std::cout << "show working room." << std::endl;

	for (std::vector<Room*>::iterator itr = this->_roomList.begin(); 
		itr != this->_roomList.end(); 
		itr++) {

		if ((*itr)->isArranged() == true && (*itr)->isCleaned() == false) {
			(*itr)->printRoomInfo();
			state = true;
		}
	}

	return state;
}


bool Manager::showStudentAtRest() {
	bool state = false;

	std::cout << "show working room." << std::endl;

	for (std::vector<Student*>::iterator itr = this->_stuList.begin();
		itr != this->_stuList.end();
		itr++) {

		if ((*itr)->isArranged() == false ) {
			(*itr)->printStuInfo();
			state = true;
		}
	}

	return state;
}
