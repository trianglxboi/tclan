#include "clanpch.hh"
#include "statmgr.hh"

#include "statmgmt/episode.hh"
#include "statmgmt/splash.hh"
#include "statmgmt/menu.hh"

namespace tclan {

	void StateManager::Tick()
	{
		if (!s_state_manager) {
			return;
		}

		// TODO: Calculate delta time
		s_state_manager->Tick(0.0f);
	}

	void StateManager::SetState(GameState state)
	{
		if (s_state_manager) {
			if (s_state_manager->GetUnitGameState() == state) {
				return;
			}
			s_state_manager->Finish();
			delete s_state_manager;
		}

		StateManagerBase* new_state_manager = nullptr;
		switch (state)
		{
		case GameState::kEpisode: new_state_manager = new EpisodeManager(); break;
		case GameState::kSplash:  new_state_manager = new SplashManager(); break;
		case GameState::kMenu:    new_state_manager = new MenuManager(); break;
		default:
			break;
		}
		if (new_state_manager) {
			s_state_manager = new_state_manager;
			s_state_manager->Transfer();
		}
	}

} // namespace tclan
