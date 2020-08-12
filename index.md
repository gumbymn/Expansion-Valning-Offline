## Expansion Offline Mode
 
**Thank you to Arkensor for his Offline Mode, for without this this Offline editor would not be possible.**

This COM Mission offers the ability to edit, or explore the world of DayZ in a singleplayer environment on the Valning Map. It is developed for use with the ```DayZ-Expansion``` mod. While this mode does not represent the actual DayZ gameplay, it offers other possibilites for developers, content creators and playerS who do want to experiment around but not loose all their progress from online.

## Installation
The source of this map must be installed under your ```Steamapps\Common\DayZ\Missions``` directory. You must also have the following mods installed:
* Community Framework (CF)
* Community Online Tools (COT)
* DayZ-Expansion (Or DayZ-Expansion-Experimental)
* DayZ-Expansion-Licensed (Or DayZ-Expansion-Licensed-Experimental)
* BuilderStatics
* ValningMap

Download the mission [here](https://github.com/gumbymn/ExpansionCOM.Valning/blob/source/Latest.zip) and extract to ```Steamapps\Common\DayZ\Missions```. If you do not have a ```Missions``` file, you will need to create one.

To launch the game in Offline Mod, simply run the ```DayZCommunityOfflineMode.bat``` file in ```Steamapps\Common\DayZ\Missions\ExpansionCOM.Valning``` to start the game.

If you run into an error after launching the included batch file, copy the ```BuilderStatics``` from ```!dzsal``` to ```!Workshop``` and launch the bat file again.

If you run into an error after launching the included ```DayZCommunityOfflineMode(Exp).bat```, copy the ```BuilderStatics```, ```DayZ-Expansion-Experimental```, and ```DayZ-Expansion-Licensed-Experimental``` from ```!dzsal``` to ```!Workshop``` and launch the bat file again.

**Even though this is not directly bannable by Battleye, just to make sure: Rename your Battleye folder to Battleye.disabled, and rename the DayZ_BE.exe to DayZ_BE.exe.disabled.**

To uninstall this mission, simple delete the ```ExpansionCOM.Valning``` mission in ```Steamapps\Common\DayZ\Missions\ExpansionCOM.Valning``` and rename your .disabled folders back to their original name.

**Note:** This offline mission has been setup to utilitize both ```Expansion-Stable``` and ```Expansion-Experimental``` builds. Use ```DayZCommunityOfflineMode.bat``` to launch Offline for ```Expansion-Stable``` or ```DayZCommunityOfflineMode(EXP).bat``` to launch Offline for ```Expansion-Experimental```.

To utilize the expansion CE, edit the init.c file as seen below.
```
	//! Init server central economy
	//Hive ce = CreateHive();
	//if ( ce )
	//ce.InitOffline();
```
and change to:
```
	//! Init server central economy
	Hive ce = CreateHive();
	if ( ce )
	ce.InitOffline();
```

## Controls:
* End - Activate COT Permissions
* U - Open the COM toolbar menu.
* Y - COT Menu
* H - Teleport Player to Crosshair

## Object Editor Controls:  
* Click objects to select them.  
* Click and drag objects to move them.
* Click on nothing to deselect the current object.
* Middle Click to snap to ground (Might not be accurate)
* Spawn in new items using the object spawner menu that can be found in the toolbar.
* You can either enter values on the object editor gui or hover above the value with your mouse and use the scroll wheel to in-/decrease them.

## Future Additions
* Teleport Locations (**In Development**)
* Automatic .MAP creations

## Developers
A special thanks to the following developers for their integral part on the development of the tools needed for this project.
* [Cypher](https://github.com/CypherMediaGIT)
* [Arkensor](https://github.com/Arkensor)
* [DannyDog](https://github.com/DannyDog)
* [Jacob_Mango](https://github.com/Jacob-Mango)
* [LieutenantMaster](https://github.com/LieutenantMaster)

## Contributions
This version of the Valning Offline map was developed by [gumbymn](https://github.com/gumbymn) using the latest DayZ Expansion mod. As a contributor to this project, I claim no ownership. All rights belong to the content developer, **Avoka**.
