#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

//GLOBAL VARIABLES
string key;
string encryptMsg;
string decryptMsg;
int eCount;
int keyLen;
int eMsgLen;
int fixKeyLen;
int msgInterval;
char messageArray[10][10];
char tempArray[10][10];
vector<char> keyVec;
vector<char> eMsgVec;
vector<char> orgMsg;
vector<int> keyList;
vector<int> keyListFinal;
char eMsg[100];
//GLOBAL VARIABLES
class transPosition {

public:

	void transPD() {
		//recieve key and encrytpted msg
		cout << "Enter your encrypted message." << endl;
		cin >> encryptMsg;
		cout << ' ' << endl;
		cout << "Enter your key." << endl;
		cin >> key;
		cout << ' ' << endl;
		//length var declaration
		keyLen = key.size();
		eMsgLen = encryptMsg.size();
		int fixKeyLen = keyLen - 1;
		//assign key to a vector
		for (int i = 0; i < keyLen; i++) {
			char charTemp = (char)key[i];
			keyVec.push_back(charTemp);
		}
		//assign msg to a vector
		for (int i = 0; i < eMsgLen; i++) {
			char charTemp = (char)encryptMsg[i];
			eMsgVec.push_back(charTemp);
		}
		//convert characters to ascii
		for (int i = 0; i < keyLen; i++) {
			keyList.push_back((char)keyVec[i]);
		}
		//calculations declaring y axis of array
		int eMsgX = eMsgLen / keyLen;
		//assign message to divided matrix
		for (int i = 0; i < keyLen; i++) { //first row of matrix;
			for (int j = 0; j < eMsgX; j++) { //down row of matrix
				messageArray[i][j] = (char)eMsgVec[eCount];
				if (eCount < eMsgLen - 1) {
					eCount++;
				}
			}
		}
		//duplicate keyList
		for (int i = 0; i < keyLen; i++) {
			keyListFinal.push_back(keyList[i]);
		}
		//sort key into first to last based on ascii values 
		for (int i = 0; i < 2; i++) { //ran twice to ensure accuracy
			for (int i = 0; i < fixKeyLen; i++) {
				int keyTemp = keyList[i];
				if (keyList[i] > keyList[i + 1]) {
					keyList[i] = keyList[i + 1];
					keyList[i + 1] = keyTemp;
				}
			}
			for (int i = fixKeyLen; i > 0; i--) {
				int keyTemp = keyList[i];
				if (keyList[i] < keyList[i - 1]) {
					keyList[i] = keyList[i - 1];
					keyList[i - 1] = keyTemp;
				}
			}
		}
		//take places of sorted key and replace with original keyList 
		for (int i = 0; i < keyLen; i++) {
			for (int j = 0; j < keyLen; j++) {
				if (keyList[i] == keyListFinal[j]) {
					keyListFinal[j] = i;
				}
			}
		}
		//print into graph 
		cout << "Graphed Result." << endl;
		cout << ' ' << endl;
		//printing keyword
		for (int i = 0; i < keyLen; i++) {
			cout << keyVec[i] << ' ';
		}
		cout << ' ' << endl;
		//printing divider
		for (int i = 0; i < keyLen; i++) {
			cout << "--";
		}
		cout << ' ' << endl;
		//printing matrix
		for (int k = 0; k < eMsgX; k++) {
			for (int i = 0; i < keyLen; i++) {
				for (int j = 0; j < keyLen; j++) {
					if (keyListFinal[i] == j) { //if keyListFinal position(i) is equal to current rotation(j) value print current placement(j)
												//flip message so that it is right side up
												//message is not in proper orientation, try experimenting with the co-ordinates to figure out how to re-organize it
						cout << messageArray[j][msgInterval] << ' '; //print out message once proper section is founD
					}
				}
			}
			if (msgInterval < eMsgX) {
				msgInterval++;
			}
			cout << ' ' << endl;
		}
		cout << ' ' << endl;
		//nested while loops and if statements to check for order of print
		for (int i = 0; i < keyLen; i++) {
			for (int j = 0; j < keyLen; j++) {

			}
		}
		//test
		cout << "---DEBUG---" << endl;
		cout << "keyList sorted" << endl;
		for (int i = 0; i < keyLen; i++) {
			cout << keyList[i] << endl;
		}
		cout << "Final Ranking" << endl;
		for (int i = 0; i < keyLen; i++) {
			cout << keyListFinal[i] << endl;
		}
		cout << "Message" << endl;
		for (int i = 0; i < eMsgLen; i++) {
			cout << eMsgVec[i] << endl;
		}
		cout << "Length of Key" << endl;
		cout << keyLen << endl;
		cout << "Message Array X Axis" << endl;
		cout << eMsgX << endl;
	}
};

//tempstorage
//cout << keyVec[i] << ' ';
//cout << '-' << ' ';
//tempstorage

int main()
{
	transPosition tp;
	tp.transPD();
	return 0;
}


