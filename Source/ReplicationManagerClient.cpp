#include "Networks.h"
#include "ReplicationManagerClient.h"

void ReplicationManagerClient::Read(const InputMemoryStream& packet)
{
	uint32 networkId; packet >> networkId;

	ReplicationAction action; packet >> action;

	switch (action)
	{
	case ReplicationAction::None:
		break;
	case ReplicationAction::Create:
	{
		GameObject* newGo = Instantiate();

		if (newGo)
		{
			packet >> newGo->position.x;
			packet >> newGo->position.y;

			packet >> newGo->angle;

			packet >> newGo->order;

			packet >> newGo->pivot.x;
			packet >> newGo->pivot.y;

			packet >> newGo->size.x;
			packet >> newGo->size.y;

			packet >> newGo->color.r;
			packet >> newGo->color.g;
			packet >> newGo->color.b;
			packet >> newGo->color.a;

			packet >> newGo->tag;

			App->modLinkingContext->registerNetworkGameObjectWithNetworkId(newGo, networkId);
		}
	}
	break;
	case ReplicationAction::Update:
	{
		GameObject* go = App->modLinkingContext->getNetworkGameObject(networkId);

		if (go)
		{
			packet >> go->position.x;
			packet >> go->position.y;
					  
			packet >> go->angle;

		}
	}
	break;
	case ReplicationAction::Destroy:
		GameObject* go = App->modLinkingContext->getNetworkGameObject(networkId);

		if (go)
		{
			App->modLinkingContext->unregisterNetworkGameObject(go);

			Destroy(go);
		}
		break;
	default:
		break;
	}
}
