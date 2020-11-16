#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Manpower.h"

enum ROOM_TYPE
{
	CLASS_ROOM,
	OFFICE_ROOM,
	MEETING_ROOM
};

class Room {

public:

	Room()
		:_roomNo("xxx"), _area(0.0f), _window_size(0.0f) {
	}

	Room(const std::string rNo, const float area, const float ws);

	Room(const Room& room) {
		// copy construction function
	}

	void printRoomInfo();

	virtual void setManpower(std::vector<Student*>& stuList) = 0;

	virtual void room_cleaning() = 0;

	virtual void printOrder() = 0;

	virtual int getTotalManpower();

	std::string getRoomNo() {
		return this->_roomNo;
	}

	virtual ~Room() {
		delete this->_manPowerList;
	}

protected:

	std::string getRoomTypeName() {
		if (this->_type == ROOM_TYPE::CLASS_ROOM)
			return "Class room";
		else if (this->_type == ROOM_TYPE::OFFICE_ROOM)
			return "Office room";
		else
			return "Meeting room";
	}

	std::string _roomNo;
	ROOM_TYPE _type;
	std::vector<PIC*>* _manPowerList;
	float _area;
	float _window_size;

	int _mpFloorNum;
	int _mpWindowNum;

	static const float base_size_floor;
	static const float base_size_window;

};

class ClassRoom : public Room {

public:

	ClassRoom() : Room() {
	}

	ClassRoom(const std::string rNo, const float area, const float ws
		, const float bbs, const int sn);

	int getTotalManpower();

	void setManpower(std::vector<Student*>& stuList);
	void room_cleaning();
	void printOrder();

private:

	float _blackboard_size;
	int _seat_num;

	int _mpBboradNum;
	int _mpSeatNum;

	static const float base_size_bborad;
	static const int base_num_seat;

};

class OfficeRoom : public Room {

public:

	OfficeRoom();

	OfficeRoom(const std::string rNo, 
		const float area, const float ws
		, const int sn);

	int getTotalManpower();

	void setManpower(std::vector<Student*>& stuList);
	void room_cleaning();
	void printOrder();

private:

	int _seat_num;

	int _mpSeatNum;

	static const int base_num_seat;
	
};


class MeetingRoom : public Room {
public:

	MeetingRoom() : Room() {

	}

	MeetingRoom(const std::string rNo, const float area, const float ws
		, const float ts);

	int getTotalManpower();

	void setManpower(std::vector<Student*>& stuList);
	void room_cleaning();
	void printOrder();

private:

	float _table_size;

	int _mpTableNum;

	static const float base_size_table;

};


#endif
