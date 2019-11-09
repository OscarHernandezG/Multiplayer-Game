#pragma once
#include <list>


enum class ReplicationAction
{ 
	None,
	Create,
	Update, 
	Destroy
};

struct ReplicationCommand
{
	ReplicationCommand(ReplicationAction action, uint32 networkId) : action(action), networkId(networkId) {}

	ReplicationAction action = ReplicationAction::None;
	uint32 networkId = 0u;
};

class ReplicationManagerServer 
{
public:
	void create(uint32 networkId);
	void update(uint32 networkId);
	void destroy(uint32 networkId);

	void write(OutputMemoryStream& packet);
	// More members... 

public:
	std::list<ReplicationCommand*> commandList;
};
