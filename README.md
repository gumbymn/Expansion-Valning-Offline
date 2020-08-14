# Expansion Offline Mode
![Offline](https://img.shields.io/badge/build-1.8121313-orange)
 
**Thank you to Arkensor for his Offline Mode, for without this this Offline editor would not be possible.**

This Offline Mode Valning offers the ability to edit, or explore the world of DayZ in a singleplayer environment on the Valning Map. While this mode does not represent the actual DayZ gameplay, it offers other possibilites for developers, content creators and playerS who do want to experiment around but not loose all their progress from online.

This is UNOFFICIAL, so don't blame the DayZ development team if this is not working at all for you! This source combines functionality of the DayZ Expansion Mod with Avoka's Valning Map. 

## Installation
The source of this map must be installed under your ```Steamapps\Common\DayZ\Missions``` directory. You must also have the following mods installed:
* Community Framework (CF)
* Community Online Tools (COT)
* DayZ-Expansion
* DayZ-Expansion-Licensed
* BuilderStatics
* BuilderItems (Future version removed as this is included with Expansion)
* ValningMap

Download the mission [here](https://github.com/gumbymn/ExpansionCOM.Valning/blob/source/Latest.zip) and extract to ```Steamapps\Common\DayZ\Missions```. If you do not have a ```Missions``` file, you will need to create one.

To launch the game in Offline Mod, simply run the ```DayZCommunityOfflineMode.bat``` file in ```Steamapps\Common\DayZ\Missions\ExpansionCOM.Valning``` to start the game. 

If you run into an error after launching the included ```DayZCommunityOfflineMode.bat```, copy the ```BuilderItems``` and ```BuilderStatics``` from ```!dzsal``` to ```!Workshop``` and launch the bat file again.

**Even though this is not directly bannable by Battleye, just to make sure: Rename your Battleye folder to Battleye.disabled, and rename the DayZ_BE.exe to DayZ_BE.exe.disabled.**

To uninstall this mission, simple delete the ```ExpansionCOM.Valning``` mission in ```Steamapps\Common\DayZ\Missions\ExpansionCOM.Valning``` and rename your .disabled folders back to their original name.

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

## Using Expansion Custom Mapping
After placing items where you want them saved, click Export in the builder menu. The items placed will be copied to your clipboard. Open your preferred text editor (Notepad, Notepad++, Visual Studio, Visual Studio Code) and paste the text (Example below). Save the file as ```SomeFile.map```. To use offline, place the file in ```expansion\objects```. 

```
 bldr_pier_concrete2|0000.000000 0000.000000 0000.000000|0000.000000 0.000000 0.000000
 bldr_pier_concrete2|0000.000000 0000.000000 0000.000000|0000.000000 0.000000 0.000000
 bldr_pier_concrete2|0000.000000 0000.000000 0000.000000|0000.000000 0.000000 0.000000
 Land_Mil_ATC_Small|0000.000000 0000.000000 0000.000000|0000.000000 0.000000 0.000000
 Land_Misc_Well_Pump_Blue|0000.000000 0000.000000 0000.000000|0.000000 0.000000 0.000000
```

To use these objects, copy the **```.map```** file to **```mpmissions\Expansion.Valning\expansion\objects```** and edit the ```init.c``` of your server from:
```
void main()
{
	bool loadTraderObjects = false;
	bool loadTraderNPCs = false;
```
to
```
void main()
{
	bool loadTraderObjects = true;
	bool loadTraderNPCs = false;
```
Restart the server. Your custom objects will now show. To add loot, simply uncomment the line in your ```init.c``` below:
```
//GetCEApi().ExportProxyData( "7500 0 7500", 16000 );  //Center of map, radius of how far to go out and find buildings.
```
Restart the server. After the ```init.c``` finishes loading, you should have a file called ```mapgrouppos.xml``` inside **```mpmissions\Expansion.Valning\storage_1\export```**. Copy this to ```mpmissions\Expansion.Valning``` and overwrite the existing file. Comment the line out again, and restart the server. You can also copy the ```mapgrouppos.xml``` to your mission file to copy that over to your Offline.

## Future Additions
* Teleport Locations
* Automatic .MAP creations
* ~~Add support for Experimental.~~ (Added)

## Developers
A special thanks to the following developers for their integral part on the development of the tools needed for this project.
* [Cypher](https://github.com/CypherMediaGIT)
* [Arkensor](https://github.com/Arkensor)
* [DannyDog](https://github.com/DannyDog)
* [Jacob_Mango](https://github.com/Jacob-Mango)
* [LieutenantMaster](https://github.com/LieutenantMaster)

## Contributions
This version of the Valning Offline map was developed by [gumbymn](https://github.com/gumbymn) using the latest DayZ Expansion mod. 

# License
![Build](https://i.imgur.com/Z8KnJxS.png) 
<br>Arma and Dayz Public License Share Alike (ADPL-SA) 

PLEASE, NOTE THAT THIS SUMMARY HAS NO LEGAL EFFECT AND IS ONLY OF AN INFORMATORY NATURE DESIGNED FOR YOU TO GET THE BASIC INFORMATION ABOUT THE CONTENT OF THIS LICENCE. THE ONLY LEGALLY BINDING PROVISIONS ARE THOSE IN THE ORIGINAL AND FULL TEXT OF THIS LICENSE.

With this license you are free to adapt (i.e. modify, rework or update) and share (i.e. copy, distribute or transmit) the material under the following conditions:

<ul><li>Attribution - You must attribute the material in the manner specified by the author or licensor (but not in any way that suggests that they endorse you or your use of the material).</li>
<li>Noncommercial - You may not use this material for any commercial purposes.</li>
<li>Arma and Dayz Only - You may not convert or adapt this material to be used in other games than Arma and Dayz.</li>
<li>Share Alike - If you adapt, or build upon this material, you may distribute the resulting material only under the same license.</li></ul>

Full text: [https://www.bohemia.net/community/licenses/arma-and-dayz-public-license-share-alike-adpl-sa](https://www.bohemia.net/community/licenses/arma-and-dayz-public-license-share-alike-adpl-sa)

<br><sup>Updated **August 2020**</sup>
