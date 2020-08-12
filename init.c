#define EXPANSION_LOOT_SPAWN_POSITION_THINGY

#include "$CurrentDir:\\Missions\\ExpansionCOM.Valning\\core\\BaseModuleInclude.c"

#include "$CurrentDir:\\Missions\\ExpansionCOM.Valning\\expansion\\ExpansionObjectSpawnTools.c"
#include "$CurrentDir:\\Missions\\ExpansionCOM.Valning\\expansion\\missions\\MissionConstructor.c"

Mission CreateCustomMission(string path)
{
	return new CommunityOfflineClient();
}

void main()
{
	bool loadTraderObjects = true;
	bool loadTraderNPCs = false;

	string MissionWorldName = "empty";
	GetGame().GetWorldName(MissionWorldName);
	
	if (MissionWorldName != "empty")
	{
		//! Spawn mission objects and traders
		FindMissionFiles(MissionWorldName, loadTraderObjects, loadTraderNPCs);
	}
	
	//! Init server central economy
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();
}
