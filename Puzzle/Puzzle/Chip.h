#pragma once
#include "Task.h"
#include "smart_ptr.h"
#include <string>
#include <array>
#include "Map.h"

PTR( Chip );
PTR( Mouse );
PTR( Map );

enum STATUS {
	STATUS_NONE,
	STATUS_LOCKED,
};

enum TYPE {
		TYPE_NONE,
		TYPE_A,
		TYPE_B,
		TYPE_C,
		TYPE_D,
		TYPE_E,
		TYPE_MAX,
};

struct CHIP {
	STATUS status;
	TYPE type;
};

class Chip : public Task {
public:
	static std::string getTag( ) { return "CHIP"; }
	static ChipPtr getTask( );
public:
	Chip();
	virtual ~Chip();
public:
	void setType( int idx, TYPE type );
	void setStatus( int idx, STATUS status );
	CHIP getChip( int idx );
	int getChangeNum( );
private:
	bool isLockInCross( int idx );
	void update( );
	void groupLock( int idx );
private:
	std::array< CHIP, Map::MAP_MAX >chip;
	MousePtr _mouse;
	int mouse_idx;
	MapPtr _map;
	int _change_num;
};

