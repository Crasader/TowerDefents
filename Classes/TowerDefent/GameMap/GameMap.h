#pragma once
#include "stdfax.h"
#include "GridPos.h"
#include "Player.h"

class WaveData
{
public:
	int PathID = 0;
	int MonsterID = 0;
	float NextDalay = 0;
};


class Wave{
public:
	float WaveTime = 0;
	vector<WaveData> wavedata;

};
#define IS_NOT_LOOP_PATH -1
class MapPath
{
public:
	MapPath(){}
	MapPath(int loopTo, std::vector<Point> pos){ this->loopTo = loopTo; this->pos = pos; }

	bool IsLoop(){ return loopTo != IS_NOT_LOOP_PATH; }
	/*if no next will return false */
	bool IsHasNext(){ return loopTo != IS_NOT_LOOP_PATH || curPos < (int)pos.size() - 1; }

	void NextPos()
	{
		curPos++;
		if (curPos >= (int)pos.size())
			curPos = loopTo;
	}
	Point getCurPos(){ return pos[curPos]; }
	int getPosCount(){ return (int)pos.size(); }
	Point getPos(int index){ return pos[index]; }
	int getLoopTo(){ return loopTo; }
private:
	int curPos = 0;
	int loopTo = IS_NOT_LOOP_PATH;
	std::vector<Point> pos;
};


class GameMap 
{
public:
	static GameMap* getInstance();
	bool init(int wrold, int level);
	void update(float dt);
	~GameMap();

	enum EGameState : int{ GS_Pause, GS_Ready, GS_NextWave, GS_CreatingMonster, GS_WaitToAllMonsterDie, GS_WaitToNextWave, GS_Win, GS_Fail, GS_WaitToEnd };
	EGameState m_state;

	/*if something be click will return ture*/
	bool onClick(Point pos);

	TMXTiledMap* getMapLayer();
	GridPos* getGridPos(int id);
	GridPos* getGridPos(Point pos);

	void SkipToNextWave();
	void UpdateNextWaveInfo();

	void clear();


private:
	GameMap();
	bool loadMap(int wrold, int level);

	static GameMap* p_myinstance;

	int m_level;
	int m_wrold;
	Size m_mapSize;
	TMXTiledMap* m_map;

	vector<GridPos*> m_gridPos;

	vector<MapPath> MonsterPath;
	vector<Wave> WaveList;
	//float startDelay;
	float waveTime;
	float monsterTime;
	int waveCount;
	int curWave;
	int curMonster;

	//bool isWin;
	//bool waveEnd;
};



