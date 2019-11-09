#include "Networks.h"
#include "ReplicationManagerServer.h"

using namespace std;

void ReplicationManagerServer::create(uint32 networkId)
{
	commandList.push_back(new ReplicationCommand(ReplicationAction::Create, networkId));
}

void ReplicationManagerServer::update(uint32 networkId)
{
	commandList.push_back(new ReplicationCommand(ReplicationAction::Update, networkId));
}

void ReplicationManagerServer::destroy(uint32 networkId)
{
	commandList.push_back(new ReplicationCommand(ReplicationAction::Create, networkId));
}



void ReplicationManagerServer::write(OutputMemoryStream& packet)
{
	for (list<ReplicationCommand*>::iterator it = commandList.begin(); it != commandList.end(); ++it)
	{
		packet << (*it)->networkId;
		packet << (*it)->action;

		GameObject* go = App->modLinkingContext->getNetworkGameObject((*it)->networkId);
		switch ((*it)->action)
		{
		case ReplicationAction::None:
			break;
		case ReplicationAction::Create:
			if (go)
			{
				LOG("Writting GO Creation from server");

				packet << go->position.x;
				packet << go->position.y;

				packet << go->angle;

				packet << go->order;

				packet << go->pivot.x;
				packet << go->pivot.y;

				packet << go->size.x;
				packet << go->size.y;

				packet << go->color.r;
				packet << go->color.g;
				packet << go->color.b;
				packet << go->color.a;

				packet << go->tag;

			}

			break;
		case ReplicationAction::Update:
			if (go)
			{

				packet << go->position.x;
				packet << go->position.y;

				packet << go->angle;
			}
			break;
		case ReplicationAction::Destroy:
			break;
		default:
			break;
		}

		delete *it;
		*it = nullptr;
	}

	commandList.clear();

}
