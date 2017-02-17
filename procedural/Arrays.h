#pragma once
#ifndef Arrays.h
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
#endif // !Arrays.h

namespace Array {

	/*
	 * Find Max
	 * @args int
	 * return int
	 */
	int max_number(int arr[]) {
		int max_number=0;
		for (int i = 0;i<sizeof(arr);i++) {
			if (max_number < arr[i]) {
				max_number = arr[i];
			}
		}
		return max_number;
	}

	void Display(string input) {
		cout << "this is me "<<input;
	}
}