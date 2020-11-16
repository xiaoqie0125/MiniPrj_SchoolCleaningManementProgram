//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Room.h"
#include "Student.h"
#include "Manager.h"
using namespace std;

int main() {

	Manager myManager;

	bool state = true;
	while (state) {
		myManager.showMenue();
		printf("please input your option.\n");
		int opt = 0;
		cin >> opt;
		if (opt > 0 && opt < 11) {
			// Register new room
			if (opt == 1) {
				//system("cls");
				myManager.showRoomType();
				printf("please input your option.\n");
				int opt = 0;
				cin >> opt;
				if (opt > 0 && opt < 4) {
					// Register class room
					if (opt == 1) {
						string roomNo;
						float floorSize;
						float windowSize;
						float balackboardSize;
						int seatNum;

						cout << "please input room number." << endl;
						cin >> roomNo;
						cout << "please input floor size." << endl;
						cin >> floorSize;
						cout << "please input window size." << endl;
						cin >> windowSize;
						cout << "please input balackboard size." << endl;
						cin >> balackboardSize;
						cout << "please input seat number." << endl;
						cin >> seatNum;

						Room* newRoom = new ClassRoom(roomNo, floorSize, windowSize, balackboardSize, seatNum);
						myManager.registerNewRoom(newRoom);
						system("cls");
					}
					// Register office room
					else if (opt == 2) {
						//system("cls");
						string roomNo;
						float floorSize;
						float windowSize;
						int seatNum;

						cout << "please input room number." << endl;
						cin >> roomNo;
						cout << "please input floor size." << endl;
						cin >> floorSize;
						cout << "please input window size." << endl;
						cin >> windowSize;
						cout << "please input seat number." << endl;
						cin >> seatNum;

						Room* newRoom = new OfficeRoom(roomNo, floorSize, windowSize, seatNum);
						myManager.registerNewRoom(newRoom);
						system("cls");
					}
					// Register meeting room
					else if (opt == 3) {
						string roomNo;
						float floorSize;
						float windowSize;
						int tableSize;

						cout << "please input room number." << endl;
						cin >> roomNo;
						cout << "please input floor size." << endl;
						cin >> floorSize;
						cout << "please input window size." << endl;
						cin >> windowSize;
						cout << "please input table size." << endl;
						cin >> tableSize;

						Room* newRoom = new MeetingRoom(roomNo, floorSize, windowSize, tableSize);
						myManager.registerNewRoom(newRoom);
						system("cls");
					}
				}
				else {
					system("cls");
				}
			}
			// Register new student.
			if (opt == 2) {
				string stu_id;
				string name;
				cout << "please input student id." << endl;
				cin >> stu_id;
				cout << "please input student name." << endl;
				cin >> name;

				Student* newStudent = new Student(stu_id, name);
				myManager.registerNewStudent(newStudent);
				system("cls");
			}
			// Arrangement task to student for target room.
			if (opt == 3) {
				
				cout << "Start arrange task." << endl;
				myManager.arrangeTask();
				//
				getchar();
				cin.get();
				system("cls");

			}

			if (opt == 4) {
				//
				string roomNo;
				cout << "please input room number." << endl;
				cin >> roomNo;
				bool state = myManager.cleaningEnd(roomNo);
				if (state == false) {
					cout << "Can not find this room." << endl;
				}
				//
				getchar();
				cin.get();
				system("cls");
			}

			if (opt == 5) {
				//print order
				string roomNo;
				cout << "please input room number." << endl;
				cin >> roomNo;
				bool state = myManager.printOrder(roomNo);
				if (state == false) {
					cout << "Can not find this room." << endl;
				}
				//
				getchar();
				cin.get();
				system("cls");

			}

			if (opt == 6) {
				// print log
			}

			// Show room list.
			if (opt == 7) {
				myManager.showRoomList();
				getchar();
				cin.get();
				system("cls");
			}

			if (opt == 8) {
				myManager.showStudentList();
				getchar();
				cin.get();
				system("cls");
			}
			//
			if (opt == 9) {
				
				getchar();
				cin.get();
				system("cls");
			}
			//
			if (opt == 10) {
				
				getchar();
				cin.get();
				system("cls");
			}

		}
		// End program
		else if (opt == 11) {
			state = false;
		}
		// Error option.
		else {
			system("cls");
		}

	}

	return 0;
}