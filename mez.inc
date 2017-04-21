#turbo
Sub Mez
	/declare loopz int local
	/declare targetID int local ${Target.ID}
	/if (${SpawnCount[npc los radius 40 notid ${Target.ID}]}) {
	/for loopz 1 to ${SpawnCount[npc los radius 40 notid ${Target.ID}]}
			/attack off
			/target ${NearestSpawn[${loopz},npc los radius 40 notid ${Target.ID}]}
			/delay 1
			/say ^mez
			/delay 1
			/target ${Spawn[${targetID}]}
			/attack on
			/delay 25
	/next loopz
	/return
	}
	| /say Nothing to mez

/return
