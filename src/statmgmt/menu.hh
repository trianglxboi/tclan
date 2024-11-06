#ifndef TCLAN_STATMGMT_MENU_HH_
#define TCLAN_STATMGMT_MENU_HH_

#include "statmgmt/statmgr.hh"

namespace tclan {

	class MenuManager : public StateManagerBase
	{
	public:
		virtual GameState GetUnitGameState() const override { return GameState::kMenu; }
	};

} // namespace tclan

#endif // TCLAN_STATMGMT_MENU_HH_
