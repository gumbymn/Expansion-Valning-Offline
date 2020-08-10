@echo off

taskkill /F /IM DayZ_x64.exe /T

RD /s /q "storage_-1" > nul 2>&1

cd ../../

<<<<<<< HEAD
start DayZ_x64.exe -mission=.\Missions\ExpansionCOM.Valning -nosplash -noPause -noBenchmark -filePatching -doLogs -scriptDebug=true "-mod=!Workshop\@DayZ-Expansion-Experimental;!Workshop\@DayZ-Expansion-Licensed-Experimental;!Workshop\@CF;!Workshop\@Community-Online-Tools;!Workshop\@BuilderStatics;!Workshop\@Valning Map;"
=======
start DayZ_x64.exe -mission=.\Missions\ExpansionCOM.Valning -nosplash -noPause -noBenchmark -filePatching -doLogs -scriptDebug=true "-mod=!Workshop\@DayZ-Expansion-Experimental;!Workshop\@DayZ-Expansion-Licensed-Experimental;!Workshop\@CF;!Workshop\@Community-Online-Tools;!Workshop\@BuilderItems;!Workshop\@Valning Map;"
>>>>>>> 3f9d4ddc7cfcea21481e91c25f7b67301d0d9edb
