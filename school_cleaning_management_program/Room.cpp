#include "Room.h"

using namespace std;

template<typename T>
int counting(T x, T y) {
	
	if (x == 0) {
		return 0;
	}

	if (x <= y) {
		return 1;
	}
	int cnt = 0;
	while (x > y) {
		cnt++;
		x -= y;
	}

	if (x > 0) {
		cnt++;
	}
	return cnt;
}

const float Room::base_size_floor = 25.0f;
const float Room::base_size_window = 25.0f;

Room::Room(const std::string rNo, const float area, const float ws)
	:_roomNo(rNo), _area(area), _window_size(ws),
	_cleaned(false), _arranged(false) {
	
	this->_mpFloorNum = counting<float>(this->_area, this->base_size_floor);
	this->_mpWindowNum = counting<float>(this->_window_size, this->base_size_window);
}

int Room::getTotalManpower() {
	
	return this->_mpFloorNum + this->_mpWindowNum;
}

void Room::printRoomInfo() {
	
	std::cout << "Room No: " << this->_roomNo << endl;
	std::cout << "Room type: " << this->getRoomTypeName() << endl;
}

void Room::room_cleaning_end() {


	std::cout << "roomNo: " << this->_roomNo << " -> end!" << std::endl;

	this->_cleaned = true;

	for (std::vector<PIC*>::iterator itr = (*this->_manPowerList).begin();
		itr != (*this->_manPowerList).end();
		itr++) {

		(*itr)->cleanEnd();

	}
}

const float ClassRoom::base_size_bborad = 10.0f;
const int ClassRoom::base_num_seat = 20;

ClassRoom::ClassRoom(const std::string rNo, const float area, const float ws
	, const float bbs, const int sn)
	:Room(rNo, area, ws), _blackboard_size(bbs), _seat_num(sn){
	
	this->_type = ROOM_TYPE::CLASS_ROOM;
	this->_mpBboradNum = counting<float>(this->_blackboard_size, this->base_size_bborad);
	this->_mpSeatNum = counting<int>(this->_seat_num, this->base_num_seat);

}

int ClassRoom::getTotalManpower() {

	int mpCnt = Room::getTotalManpower();
	mpCnt += this->_mpBboradNum + this->_mpSeatNum;
	return mpCnt;

}

void ClassRoom::setManpower(std::vector<Student*>& stuList) {

	

	int mpCnt = this->getTotalManpower();
	this->_manPowerList = new std::vector<PIC*>(mpCnt);

	std::vector<PIC*>::iterator itr_mp = this->_manPowerList->begin();
	std::vector<Student*>::iterator itr_stu = stuList.begin();

	for (int i = 0; i < this->_mpFloorNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Floor");
		*itr_mp = new PIC_Floor(*itr_stu);
	}

	for (int i = 0; i < this->_mpWindowNum; i++, itr_mp++, itr_stu++) {

		(*itr_stu)->record(this->_roomNo, "Window");
		*itr_mp = new PIC_Window(*itr_stu);
	}

	for (int i = 0; i < this->_mpBboradNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Blackboard");
		*itr_mp = new PIC_Balckboard(*itr_stu);
	}

	for (int i = 0; i < this->_mpSeatNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Seat");
		*itr_mp = new PIC_Seat(*itr_stu);
	}

}

void ClassRoom::room_cleaning(){
	
	this->printRoomInfo();
	std::cout << "start cleaning." << std::endl;
	std::vector<PIC*>::iterator itr_mp ;
	for (itr_mp = this->_manPowerList->begin(); 
		itr_mp != this->_manPowerList->end(); 
		itr_mp++) {

		(*itr_mp)->cleaning();
		//(*itr_mp)->printOrder();
	}

	this->_arranged = true;
}

void ClassRoom::printOrder() {

	this->printRoomInfo();
	for (std::vector<PIC*>::iterator itr_mp = this->_manPowerList->begin(); 
		itr_mp != this->_manPowerList->end(); 
		itr_mp++) {

		(*itr_mp)->printOrder();
	}
}

const int OfficeRoom::base_num_seat = 20;

OfficeRoom::OfficeRoom(): Room() {

}

OfficeRoom::OfficeRoom(const std::string rNo, 
	const float area, const float ws
	, const int sn)
	:Room(rNo, area, ws), _seat_num(sn) {

	this->_type = ROOM_TYPE::OFFICE_ROOM;
	this->_mpSeatNum = counting<int>(this->_seat_num, this->base_num_seat);

}

int OfficeRoom::getTotalManpower() {

	int mpCnt = Room::getTotalManpower();
	mpCnt += this->_mpSeatNum;
	return mpCnt;

}

void OfficeRoom::setManpower(std::vector<Student*>& stuList) {

	int mpCnt = this->getTotalManpower();
	this->_manPowerList = new std::vector<PIC*>(mpCnt);

	std::vector<PIC*>::iterator itr_mp = this->_manPowerList->begin();
	std::vector<Student*>::iterator itr_stu = stuList.begin();

	for (int i = 0; i < this->_mpFloorNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Floor");
		*itr_mp = new PIC_Floor(*itr_stu);
	}

	for (int i = 0; i < this->_mpWindowNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Window");
		*itr_mp = new PIC_Window(*itr_stu);
	}

	for (int i = 0; i < this->_mpSeatNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Office seat");
		*itr_mp = new PIC_Officeseat(*itr_stu);
	}

}

void OfficeRoom::room_cleaning() {

	this->printRoomInfo();

	std::cout << "start cleaning." << std::endl;
	std::vector<PIC*>::iterator itr_mp;

	for (itr_mp = this->_manPowerList->begin(); 
		itr_mp != this->_manPowerList->end(); 
		itr_mp++) {
		
		(*itr_mp)->cleaning();
	}

	this->_arranged = true;

}

void OfficeRoom::printOrder() {

	this->printRoomInfo();

	std::vector<PIC*>::iterator itr_mp;

	for (itr_mp = this->_manPowerList->begin(); 
		itr_mp != this->_manPowerList->end(); 
		itr_mp++) {
		
		(*itr_mp)->printOrder();
	}
}

const float MeetingRoom::base_size_table = 20;

MeetingRoom::MeetingRoom(const std::string rNo, 
	const float area, const float ws
	, const float ts)
	:Room(rNo, area, ws), _table_size(ts) {

	this->_type = ROOM_TYPE::OFFICE_ROOM;
	this->_mpTableNum = counting<int>(this->_table_size, this->base_size_table);

}

int MeetingRoom::getTotalManpower() {

	int mpCnt = Room::getTotalManpower();
	mpCnt += this->_mpTableNum;
	return mpCnt;

}

void MeetingRoom::setManpower(std::vector<Student*>& stuList) {

	int mpCnt = this->getTotalManpower();
	this->_manPowerList = new std::vector<PIC*>(mpCnt);

	std::vector<PIC*>::iterator itr_mp = this->_manPowerList->begin();
	std::vector<Student*>::iterator itr_stu = stuList.begin();

	for (int i = 0; i < this->_mpFloorNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Floor");
		*itr_mp = new PIC_Floor(*itr_stu);
	}

	for (int i = 0; i < this->_mpWindowNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Window");
		*itr_mp = new PIC_Window(*itr_stu);
	}

	for (int i = 0; i < this->_mpTableNum; i++, itr_mp++, itr_stu++) {
		
		(*itr_stu)->record(this->_roomNo, "Meeting table");
		*itr_mp = new PIC_Meetingtable(*itr_stu);
	}

}

void MeetingRoom::room_cleaning() {

	this->printRoomInfo();

	std::cout << "start cleaning." << std::endl;

	std::vector<PIC*>::iterator itr_mp;

	for (itr_mp = this->_manPowerList->begin(); 
		itr_mp != this->_manPowerList->end(); 
		itr_mp++) {
		
		(*itr_mp)->cleaning();
	}

	this->_arranged = true;
}

void MeetingRoom::printOrder() {

	this->printRoomInfo();

	std::vector<PIC*>::iterator itr_mp;

	for (itr_mp = this->_manPowerList->begin(); 
		itr_mp != this->_manPowerList->end(); 
		itr_mp++) {

		(*itr_mp)->printOrder();
	}
}