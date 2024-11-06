#ifndef TCLAN_STATMGMT_SPLASH_HH_
#define TCLAN_STATMGMT_SPLASH_HH_

#include "statmgmt/statmgr.hh"

namespace tclan {

	class SplashManager : public StateManagerBase
	{
	public:
		virtual GameState GetUnitGameState() const override { return GameState::kSplash; }
	};

} // namespace tclan

#endif // TCLAN_STATMGMT_SPLASH_HH_
