#ifndef TCLAN_STATMGMT_EPISODE_HH_
#define TCLAN_STATMGMT_EPISODE_HH_

#include "statmgmt/statmgr.hh"

namespace tclan {

	class EpisodeManager : public StateManagerBase
	{
	public:
		virtual GameState GetUnitGameState() const override { return GameState::kEpisode; }
	};

} // namespace tclan

#endif // TCLAN_STATMGMT_EPISODE_HH_
