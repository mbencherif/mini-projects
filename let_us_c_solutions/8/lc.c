/*
 * lc.c
 * 
 * program to implement a 4x4 1 box missing puzzle game
 * 
 * Copyright 2015 Rohan Verma <hello@rohanverma.net>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>




int find_zero(int arr[][4])
{
	int pos = 0;
	
	for(int i = 0; i< 4; i++){
		for(int j = 0; j< 4; j++){
			if(arr[i][j] == 0)
				return pos;
			
			pos++;
		}
	}
	
	return -1;
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void clrscr()
{
	for(int i = 0; i < 24; i++){ printf("\n"); }
}

void randomize_board(int arr[][4]){

	int num_swaps = rand()%20 + 5;
	
	while(num_swaps--){
		swap(&arr[rand()%4][rand()%4], &arr[rand()%4][rand()%4]);
	}
	
}

int check_board(int arr[][4]){
	
	int won[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(arr[i][j] != won[i][j])
				return 0;
		}
	}
	
	return  1;
	
};

int main(int argc, char **argv)
{
	clrscr();
	
	srand(time(NULL));
	
	int a[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};
	randomize_board(a); //randomize the map

	int exit = 0;
	
	int moves = 0;
	
	char in;
	
	while(exit == 0)
	{


		
		printf("MOVES: %d\n", moves);
		printf("======================================\n");
		
		for(int i = 0; i< 4; i++){
			printf("\n");
			for(int j = 0; j< 4; j++){
				printf("%d\t", a[i][j]);
			}
		}
		
		printf("\n{w,s,a,d,q}? ");
		scanf("%s", &in);
		moves++;
		int z_row = find_zero(a)/4, z_col = find_zero(a)%4;
		switch(in){
			case 'w': 
				if(z_row > 0)swap(&a[z_row][z_col], &a[z_row-1][z_col]);
				break;
			case 's': 
				if(z_row < 3)swap(&a[z_row][z_col], &a[z_row+1][z_col]);
				break;
			case 'a': 
				if(z_col > 0)swap(&a[z_row][z_col], &a[z_row][z_col-1]);
				break;
			case 'd': 
				if(z_col < 3)swap(&a[z_row][z_col], &a[z_row][z_col+1]);
				break;
			case 'q': 
				exit = 1;
				break;									
		}
		clrscr();
		
		if(exit == 0) exit = check_board(a); //check if game won
		
	}
	
	return 0;
}

