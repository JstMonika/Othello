#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

// ███████████████████████████████▀█░░░░░░░█▀▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀█████▌███▀▀███████▐███████████▌
// █████████████████████████████▀░░▐▌░░▄▄▄█░░░░░░░░░░▀██░░░░░░░░▄████▄▄▄▄▄███████▄▄▄▄▄▄▄▄██████▄███████▀███████████▌
// ███████████████████████████▀░░░░░█▄▄█▀▀░░░░░░▄▄██▀▀▀▀░░░▄▄▄▀▀██████████████████████████▀███▀███████▌▐███░███████▌
// ██████████████████████████▄░▀░░░▄██░░░░░░▄░▄█▀▀░░░▄▄▄█████░░░▀█████████████████████████░██▌░▐████▐█░▐███░▐██████▌
// ████████████████████████░░█▄░░░░▀░█▄░░░▄█▀░░░░░▄▄██▀░▀████░░░░░████████████████████████▄██░░█████▐█░███▌░▀█▄████▌
// ██████████████████████░█░░▀█░░▄░░░░█░█▀░░░░▄▄██▌███░░░▀██▌░░░░░████████████████████████▐██░░████▌▐▀░███░░░░█████▌
// ████████████████████▀░░▀█░▄▐█░▀▄░░░▀▌░░▄▄███████░██▌░░░███░░░░░░█████████████████▐█████▐█▌░░████▌█░░███░░░░█████▌
// ██████████████████▀░░░░░▐█▀░█▄░▐░░░░█▄██████████░▀██░░░▐██░░░░░░█████████████████▐█████▐█▌░░████░▀░░███░░░░█████▌
// █████████████████░░░░░░░░█████▄░█▄██████████████▄░▐█▄░░░██▌░░░░░████████████████▀██████▐█░░▐████░░░▐██▌░░░░█████
// ███████████████▀░░░░░░░░▄██▄▄▀█▄█████████████████░▀█▌░░░▐█▌░░░░░░▄▀█████▀▀▀▀▀▀▀▀▀▀▀████▄█░░▐███▌░░░▐██░░░░▐████▌
// ██████████████▀░░░░░░░▄█▀░░█▄████████████████████▌░▐█░░░░██░░░▄▄█▀▀▀░░░░░░░░░░░░░░░░░░░▀▀█▄████▀░░░▐█▌░░░░▐████
// █████████████░░░░░░░▄█▀░░▄▄██████████████████████░░░█▌░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀███▀░░░▐█▀░░░░████▀
// ███████████▀░░░░░▄█▀░░░▄█████████████████████████▌░░▐█░▄▄███████▄░░░▄▄█████▌░░░░░░░░░░░░░░░░░░▀▄▄░▄██░░░░░████
// ██████████░░░░▄▄▀▀░░░▄███████████████████████████▌░░▀▄█▀░██████████████████▀░░░▄░▐░░░░░░░░░░░░░░▀▄▄█▌░░░░▐███▀
// ████████▀░░▄▄▄█░░░▄████████████████████████████▐███▄█▀░▄██████████████████▀░░░░▌░▐░░░░░░░░░░░░░░░░██░░░░░████
// ███████▀░░▀▀░░░░▄████████████▀█████████████████▌█▌██░░████████████████████▌░░░▐▀░█░░░░░░░░░░░░░░░░▄██░░░░███▀
// ▀█████▄▄▄▄░░░░▄██▄░█████▄█████░███████████████████▀░▄█░▀▀█▀▀███░░░▀▀██████▌░░░█░▄█░░░░░░░░░░░░░░░░▐▀▀█░░░██▌
// ░░███▀█▄░█░▄▄█████▄░█████▄▀█▀▀▄░█▀███████████████▀░▄█░░░░░░░█▌░░░░░░░░░░██▀░░▐▀░██░░▄▄░░░░░░░░░░░░█░░▀█░▐██
// ░█▌░▀█░█▄▀█████████▄░▐████▄▀▀░░░░▀██████████████▀░░█░░░░░░░░█░░░░░░░░░░██▀░░▄█░███░░▐▌░░░░░░░░░░░▐▌░░░▀███▌
// █▀█▄░▀█░▀░█▐████████▌░▀████░░░░░░░▀▀██▄▐██░███▀█░░▐▀░░░░░░░▐▀░░░░░░░░▄██▀░░▄█▄██▐██░█▌░░░░░░░░░░░█░░░░░▀██
// █▄░▀█░░░░░▀█▀█████████░▀████░░░░░░░░▀██▄▐████░░░░▄▌░░░░░▄░░░░░░░░░░░░▀░▀░░▄█▄██▀▀█▌░█▌░░░░░░░░░░░▌░░░░░░▐▌
// ██▄░░░░░░░▄█░▀████████▄░░████░░░░░░░░▀██░███░░░░░▀▌░░░░░▀▄░░░░░░░░░░░░░░░▄▄█▀▀░░░██▐█▌░░░░░░░░░░▐▀░░░░░▄░█
// ██▌░░░░░░░███▄▀████████▄░░███▄░░░░░░░░▀█▌▐█▄░░░░░░▌░░░░░░▀█▄░░░░░░░░░░░▀▀▀░░░░░░░▐███░░░░░░░░░░░█░▄░░░░█░▐▄
// ▀█▌░░░░░░▐████▄░▀███████░░░▀██░░░░░░░░░░██▀▌░░░░▄░█░░░░░░░░▀░░░░░░░░░░░░░░░░▄▄██▀░███░░░░░░░░░░░▌░▌░░░░▐░▀▌
// ░▀▌░░░░░░▐▄▀███▄░▀███▄███░░░▀██░░░░░░░░░██░▐▄░░░▌░▐░▄▄▄▄▄░░░░░░░░░░░░░░░▄▄██▀▀░░░░██▌░░░░░░░░░░▐░░█░░░░▀▌░▌
// █░█░░░░░░░▀▀▄████░░███▄▀▀▄░░░▀█░░░░░░░░▐▀░▀░█░▄█▌░▐▄░░▀▀███▄▄░░░░░░░░░▄███▄▄▄▄▄▄░░██▀░░░░░░░░░░▄░░█░░░░░█░▌
// ▐███░░░░░░░░▀█████▄░▀██▄░░░░░░░░░░░░░░░█░░░░▀███▌░▀▌▄▄███▀▀▀░░▄░░░░░░░░░░▀▀▀▀▀▀▀░░▐█░░░░░░░░░░░▀░▄█▌░░░░▐░▌
// █████▄░░░░░░░░▀▀███▄░▀██▄░░░░░░░░░░░░░▐▀░░░░████▀░▄▌▀▀░░░░░░░░▀░░░░░░░░░░░░░░░░░░░▐▌░░░░░░░░░░░░░███░░░░▀▌▌
// ███▌░▀█▄░░░░░░░░░▀██░░▀██▄░░░░░░░░░░░░█░░░░█████░░█▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░▄████░░░░░█▌
// ███▌░░░▀█░░░░░░░░░░▀█▄▄░▀█▄░░░░░░░░░░░▌░░░▄████▌░▄▌░░░░░░░░░░░░░░░▄▄░░░░░░░░░░░░░▄▌░░░░░░░░░░░▄█████▌░░░░▀█
// ███▌░░░░▀█▄░░░░░░░░░░░▀▀███▄░░░░░░░░░▐▌░░▄█████▀░█░░░░░░░░░░░░▄▄▄▄█░░░░░░░░░░░░░░█░░░░░░░░░░░████████░░░░░█
// ▀███░░░░░░█▄░░░░░░░░░░░░░░▀▀█▄▄░░░░░░▐▌░░█████▌░░▐▄░░░░░░░░░░▀▀░░▐░░░░░░░░░░░░░░█▀░░░░░░░░░▄█████████▌░░░░▐▌
// ░░░▀█░░░░░░▀█▄░░░░░░░░░░░░░░░░▀▀▄▄▄░░▐▌░▐█████░░░▄█▄░░░░░░░░░░░░░░░░░░░░░░░░░░░▐▀░░░░░░░░▄████████████▄░░░░█
// ░░░░▀█░░░░░░░▀▄░░░░░░░░░░░░░░░░░░░▀▀█▄█░█████▀░░▄███▄░░░░░░░░░░░░░░░░░░░░░░░░░█▀░░░░░░░░▄██████████████░░░░▀▌
// ░░░░░░█▄░░░░░░░█▄░░░░░░░░░░░░░░░░░░░░░▀▀████▀░░███████▄░░░░░░░░░░▄▄▄██▄▄▄▄▄░▄█▀░░░░░░▄█████████████████░░░░░█
// ░░░░░░░█▄░░░░░░░▀█▄░░░░░░░░░░░░░░░░░░░░░░▀▀█▄▄██████████░░░░░░░░▄█████▄░░██▀▀█▄▄▄▄▄▄███████████████████▌░░░░▀▄
// █▄░░░░░░▀█░░░░░░░░▀▀▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀██████░░█▄░░░▀▀█▄░░░▀▀█▄▀█████████████░░░░░█
// ███▄░░░░░▀█▄░░░░░░░░░▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░█░░░░░░░░░░░░░░██████████████░░█░░▐▄
// ░░▀█▄░░░░░░█▄░░░░░░░░░░▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐█████▌░░▀░░░░░░░░░░░░░░█████████████▄░▐▄░░▌
// ░░░░░░░░░░░░▀█░░░░░░░░░░░▀▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐██████░░▄░░░░░░░░░░░░░░░████████████▌░▀▌░░▌
// ░░░░░░░░░░░░░░█▄░░░░░░░░░░░░▀▀█▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐██████░░█░░░░░░░░░░░░░░░▀███████████▌░░█░░▌
// ░░░░░░░░░░░░░░░▀█░░░░░░░░░░░░░░░░░▀█▀▀█▄▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░░██████▀░▄▀░░░░░░░░░░░░░░░░███████████▀░░▐░░▌
// ░░░░░░░░░░░░░░░░░▀█▄▄░░░░░░░░░░░░░██░▄██████▀▀▀██▄▄▄▄▄░░░░░░░░░░░░███████▄▄█░░░░▄░░░░░░░░░▄▄░▐██████████░░░▐░▄▀
// ██░░░░░░░░░░░░░░░░░░▀▀█▄▄░░░░░░░▄███░███████▌▀▄███▀░░▀▀▀████▄▄▄▄▄███████▐██▌▀▀▀░▄▀▀▀▄░░░█▄▄██▐█████████▌░░░█░█
// ░▀██▄░░░░░░░░░░░░░░░░░░░▀▀█▄░░▄████████████▀█▄▄█▀░░░░░░▐███▀▀░░░░██████▀████▄▀█░▀░░░▀██▄░░░░▀██████████▌░░░▌▐▀
// ░░░▀▀█▄░░░░░░░░░░░░░░░░░░░░░▀▀████████▄███▌▄█▐▀▄▄▄▄▄▄▄░▐█▀░░░░░░░░▀████████████▀▀▀▀▀▀██▀░░░░▄██████████░░░▐█▌
// ░░░░░░▀██▄░░░░░░░░░░░░░░░░░░░░█▀███░▐▌█▀███▀▐██████████████████████████████████████████▄▄▄▄▄██████████▌░░▄██
// ░░░░░░░░▀▀█▄░░░░░░░░░░░░░░░░░▐███▀█▄▄█▀░██▀███████████████████████████████████████████████████████████░░▄█▀
// █▄▄░░░░░░░░▀▀░░░░░░░░░░░░░░░░▀██████▄█▄▄▐████████████████████████████████████████████████████████████▌░▄█
// ░▀▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀██████████████████████████████████████████████████████████████▄█▀
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐████████████████████████████████████████████████████████████▀
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄██████████████████████████████████████████████████████████▀▀
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄██████████████████████████████████████████████████████████▀
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄██▀░░██████████████████████████████████████████████████████
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐█▀▄▄▄▄█████████████████████████████████████████████████░▐██
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄███████████████████████████████████████████████████████▌░▐█
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░░▀▀

int value_table[8][8]
{
	{1600,	-350,	300,	250,	250,	300,	-350,	1600},
	{-350,	-600,	300,	200,	200,	300,	-600,	-350},
	{300,	300,	150,	67,		67,		150,	300,	300},
	{250,	200, 	67,		67,		67,		67,		200,	250},
	{250,	200, 	67,		67,		67,		67,		200,	250},
	{300,	300,	150,	67,		67,		150,	300,	300},
	{-350,	-600,	300,	200,	200,	300,	-600,	-350},
	{1600,	-350,	300,	250,	250,	300,	-350,	1600},
};

struct Point {
    int x, y;
	Point(int a, int b) : x(a) , y(b) {}
	Point operator+(const Point& a)
	{ return Point(this->x+a.x, this->y+a.y); }
};

const int SIZE = 8;
using arr = std::array< std::array<int, SIZE>, SIZE >;
using pai = std::pair<Point, int>;

int player;
arr board;
std::vector<Point> next_valid_spots;
vector<Point> find_valid(arr, int);

int cal(const arr& source, int player)
{
	int count = 0;
	
	bool survive[SIZE][SIZE];
	int number = 0;
	memset(survive, 0, sizeof(survive));
	
	int c[2][4] = {{0, 0, SIZE-1, SIZE-1}, {SIZE-1, 0, SIZE-1, 0}};
	for (int i = 0; i < 4; i++)
		if (source[c[0][i]][c[1][i]] == player)
			survive[c[0][i]][c[1][i]] = true;
		
	for (int i = 0; i < SIZE; i++)
	{
		
		for (int k = 0; k < SIZE; k++)
		{
			if (source[i][k] != player)
				continue;
			if (!i and !k)
				continue;
			
			bool good = true;
			
			if (i-1 >= 0 and !survive[i-1][k])
				good = false;
			if (k-1 >= 0 and !survive[i][k-1])
				good = false;
			
			if (good)
				survive[i][k] = true;
		}
		
		for (int k = SIZE-1; k >= 0; k--)
		{
			if (source[i][k] != player)
				continue;
			if (!i and k == SIZE-1)
				continue;
			
			bool good = true;
			
			if (i-1 >= 0 and !survive[i-1][k])
				good = false;
			if (k+1 < SIZE and !survive[i][k+1])
				good = false;
			
			if (good)
				survive[i][k] = true;
		}
	}

	for (int i = SIZE-1; i >= 0; i--)
	{
		for (int k = 0; k < SIZE; k++)
		{
			if (source[i][k] != player)
				continue;
			if (i == SIZE-1 and !k)
				continue;
			
			bool good = true;
			
			if (i+1 < SIZE and !survive[i+1][k])
				good = false;
			if (k-1 >= 0 and !survive[i][k-1])
				good = false;
			
			if (good)
				survive[i][k] = true;
		}
			
		
		for (int k = SIZE-1; k >= 0; k--) 
		{
			if (source[i][k] != player)
				continue;
			if (i == SIZE-1 and k == SIZE-1)
				continue;
			
			bool good = true;
			
			if (i+1 < SIZE and !survive[i+1][k])
				good = false;
			if (k+1 < SIZE and !survive[i][k+1])
				good = false;
			
			if (good)
				survive[i][k] = true;
		}
	}
	
	/*
	cout << endl << player << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int k = 0; k < SIZE; k++)
			cout << source[i][k] << ' ';
		cout << endl;
	}
	
	cout << "---->" << endl;
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int k = 0; k < SIZE; k++)
		{
			cout << survive[i][k] << ' ';
			if (survive[i][k])
				number++;
		}
		cout << endl;
	}	
	*/
	
	count += number * 175;
	
	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			if (source[i][k] == player)
				count += value_table[i][k];
			
	count += find_valid(source, player).size() * 125;
		
	return count;
}

void read_board(std::ifstream& fin) {
    fin >> player;
	cout << "Player: " << player << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> board[i][j];
        }
    }
}

void read_valid_spots(std::ifstream& fin) {
    int n_valid_spots;
    fin >> n_valid_spots;
    int x, y;
    for (int i = 0; i < n_valid_spots; i++) {
        fin >> x >> y;
        next_valid_spots.push_back({x, y});
    }
}

Point dir[8] = {
	Point(0, 1),
	Point(1, 1),
	Point(1, 0),
	Point(1, -1),
	Point(0, -1),
	Point(-1, -1),
	Point(-1, 0),
	Point(-1, 1)
};

inline bool inside_board(int x, int y) {
	return (x >= 0 and x < SIZE and y >= 0 and y < SIZE);
}

void flip_discs(arr& state, Point center, int tplayer) {
    for (Point i: dir) {
        // Move along the direction while testing.
        Point p = center + i;
        if (state[p.x][p.y] != 3-tplayer)
            continue;
        std::vector<Point> discs({p});
        p = p + i;
        while (inside_board(p.x, p.y) && state[p.x][p.y] != 0) {
            if (state[p.x][p.y] == tplayer) {
                for (Point s: discs) {
					// cout << "fliping......";
                    state[s.x][s.y] = tplayer;
					// cout << state[s.x][s.y] << tplayer << endl;
                }
                break;
            }
            discs.push_back(p);
            p = p + i;
        }
    }
}

vector<Point> find_valid(arr state, int player)
{
	vector<Point> tmp;
	
	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
		{
			if (state[i][k])
				continue;
			
			for (int m = 0; m < 8; m++)
			{
				bool good = false;
				int curi = i+dir[m].x, curk = k+dir[m].y;
				
				if (inside_board(curi, curk) and state[curi][curk] + player == 3)
				{
					while (inside_board(curi, curk) and state[curi][curk])
					{
						if (state[curi][curk] == player)
						{
							tmp.push_back(Point(i, k));
							
							good = true;
							break;
						}
						
						curi += dir[m].x;
						curk += dir[m].y;
					}
					
					if (good)
						break;
				}
			}
		}
		
	return tmp;
}

pai dfs(int step, arr state, int alpha, int beta, bool Max, int tplayer)
{
	if (step--)
	{
		// vector<pai> check;
		
		pai ret = make_pair(Point(-1, -1), ((Max) ? -1e9 : 1e9));
		
		vector<Point> valid_location = find_valid(state, tplayer);
		
		if (valid_location.size())
		{
			for (auto i : valid_location)
			{
				if (alpha >= beta)
					break;
				
				// cout << '(' << i.x << ", " << i.y << ") ";
				arr next_state = state;
				
				next_state[i.x][i.y] = tplayer;
				flip_discs(next_state, i, tplayer);
				
				// cout << "Go (" << i.x << ", " << i.y << ") -----------------" << endl;
				pai v = dfs(step, next_state, alpha, beta, !Max, 3-tplayer);
				// cout << "--------------------------" << endl << endl;
				
				v.first.x = i.x;
				v.first.y = i.y;
				
				// check.push_back(v);
				
				if (Max)
				{
					alpha = max(alpha, v.second);
					ret = (v.second > ret.second) ? v : ret;
				}
				else
				{
					beta = min(beta, v.second);
					ret = (v.second < ret.second) ? v : ret;
				}
				
				// modifying alpha and beta.
			}
			
			/*
			cout << "Go down depth: " << step << " ------------> " << tplayer << endl;
			for (auto i : check)
				cout << "{(" << i.first.x << ", " << i.first.y << "), " << i.second << "} ";
			cout << endl;
			cout << "return " << "{(" << ret.first.x << ", " << ret.first.y << "), " << ret.second << "}" << endl;
			*/
			
			return ret;
		}
		else
		{
			pai v = dfs(step, state, alpha, beta, !Max, 3-tplayer);
			
			return v;
		}
	}
	else
		return make_pair(Point(-1, -1), cal(state, player) - cal(state, 3-player));
}

void write_valid_spot(std::ofstream& fout) {
    // Point p = next_valid_spots[index];
    // Remember to flush the output to ensure the last action is written to file.
	
	ofstream out_step;
	out_step.open("check.txt");
	
	int steps = 1;
	while (steps <= 50)
	{
		pai tmp = dfs(steps, board, -1e9, 1e9, true, player);
		
		fout << tmp.first.x << " " << tmp.first.y << std::endl;
		fout.flush();
		
		out_step << "{(" << tmp.first.x << ", " << tmp.first.y << "), " << tmp.second << "} -> " << steps << endl;
		
		steps++;
	}
	
	out_step.close();
}

int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    read_valid_spots(fin);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}
