#pragma once
#include "TileType.h"
class State {
public:
	State(int w, int h);
	~State();
	void setLevel(TileType * tiles);
	TileType * tiles;
	int width;
	int height;
	int cx;
	int cy;
	// �ж��Ƿ��ǻ�ʤ״̬
	bool ifWin();
	// �����ƶ���ɫ
	void up();
	// �����ƶ���ɫ
	void down();
	// �����ƶ���ɫ
	void left();
	// �����ƶ���ɫ
	void right();
	// ���Ľ�ɫλ��
	void changLoc(int newcx, int newcy, int newcx2, int newcy2);
	State * clone();
	// �ж�һ��state�Ƿ����Լ���tiles���
	bool isEqual(State * tempst);
};