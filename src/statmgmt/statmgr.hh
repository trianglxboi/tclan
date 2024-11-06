#ifndef TCLAN_STATMGMT_STATMGR_HH_
#define TCLAN_STATMGMT_STATMGR_HH_

namespace tclan {

	enum class GameState
	{
		kNone = 0,
		kSplash, kMenu, kEpisode
	};

	// Base class of all state managers
	class StateManagerBase
	{
	public:
		virtual ~StateManagerBase() = default;

		virtual void Transfer() { }
		virtual void Tick(float dt) { }
		virtual void Finish() { }

		virtual GameState GetUnitGameState() const = 0;
	};

	// Static organization unit to make the state system work
	class StateManager
	{
	public:
		static void Tick();
		static void SetState(GameState state);

		static bool HasValidState() { return s_state_manager && s_state_manager->GetUnitGameState() != GameState::kNone; }
		static GameState GetState() { return HasValidState() ? s_state_manager->GetUnitGameState() : GameState::kNone; }
		static StateManagerBase* GetStateManager() { return s_state_manager; }
	private:
		inline static StateManagerBase* s_state_manager = nullptr;
	};

} // namespace tclan

#endif // !TCLAN_STATMGMT_STATMGR_HH_
