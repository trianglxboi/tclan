#include "clanpch.hh"
#include "statmgmt/statmgr.hh"

using namespace tclan;

int main(int argc, char** argv)
{
	StateManager::SetState(GameState::kSplash);

	while (StateManager::GetState() != GameState::kNone) {
		StateManager::Tick();
	}
}
