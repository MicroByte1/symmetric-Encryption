// Encryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

static char Key[] = { 0,1,2,3,4,5,77,82,56,211,25,27,89,89,59,90,12,24,67,98,56,59,23,25,77,89,233,234,212,123,145,215,27,70,189,188,167,167,45,144,145,165,187,156,173,25,213,217 };


void Encrypt(char data[], int size) {
	int len = sizeof(Key);
	for (int i = 0; i < size; i++) {
		data[i] ^= Key[i % len];
		data[i] ^= Key[(i + 1) % len];
		data[i] ^= Key[(i + 2) % len];
	}
}
void Decrypt(char data[], int size) {
	int len = sizeof(Key);
	for (int i = 0; i < size; i++) {
		data[i] ^= Key[(i + 2) % len];
		data[i] ^= Key[(i + 1) % len];
		data[i] ^= Key[i % len];
	}
}



int main()
{
	char data[32];
	cout << "Enter the Data to Encrypt it : " << endl;
	cin >> data;

	cout << "Before Encryption : ";
	cout << data << endl;
	cout << "After Encryption : " << endl;
		Encrypt(data, sizeof(data));
	cout << data << endl;

	Decrypt(data, sizeof(data));
	cout << "After Decryption : ";
	cout << data << endl;
}
