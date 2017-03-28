|---------------------------------------------------
|- To use this include, simply /doevents expgain
|-              in your main script
|


#EVENT expgain "You gain party experience!!"
#EVENT expgain "You have gained an ability point!#*#"
#EVENT expgain "You have gained a group leadership point!"


Sub EVENT_expgain(fullMsg)
	/if (!${Defined[intKillCounter]}) /declare intKillCounter int outer 0
	/if (!${Defined[currentExp]}) /declare currentExp int outer 0
	/if (!${Defined[intLevel]}) /declare intLevel int outer ${Me.Level}
	/if (!${Defined[intLevelGain]}) /declare intLevelGain int outer 0
	/if (!${Defined[floatPerKill]}) /declare floatPerKill float outer 0
	/if (!${Defined[floatGained]}) /declare floatGained float outer 0
	/if (!${Defined[floatAAGained]}) /declare floatAAGained float outer 0
	/if (!${Defined[LeaderShipGain]}) /declare LeaderShipGain int outer 0
	/if (!${Defined[AAPointGain]}) /declare AAPointGain int outer 0
	/if (!${Defined[AAExpGain]}) /declare AAExpGain int outer 0
	/if (!${Defined[AAExpStart]}) /declare AAExpStart int outer ${Me.AAExp}
	/if (!${Defined[startExp]}) {
		/declare startExp int outer 0
		/varcalc startExp 330*${Me.Level}+${Me.Exp}
		/return
	}
	/if (${fullMsg.Find[You have gained a group leadership point!]}) {
		/varcalc LeaderShipGain ${LeaderShipGain}+1
	
	}
	/if (${fullMsg.Find[You have gained an ability point!]}) {
		/varcalc AAPointGain ${AAPointGain}+1
	}
	/if (${AAPointGain}>1) {
		/varcalc AAExpGain ${Math.Calc[(330-${AAExpStart})+(${AAPointGain}*300)]}
	}
	/if (${AAPointGain}==1) {
		/varcalc AAExpGain ${Math.Calc[(330-${AAExpStart})+${Me.AAExp}]}
	}
	/if (${AAPointGain}==0) {
		/varcalc AAExpGain ${Math.Calc[${Me.AAExp}-${AAExpStart}]}
	}

	/varcalc intLevelGain ${Me.Level}-${intLevel}
	/varcalc intKillCounter ${intKillCounter}+1
	/varcalc currentExp ${Math.Calc[330*${Me.Level}+${Me.Exp}]}
	/varcalc floatGained ${Math.Calc[((${currentExp}-${startExp})/330)*100]}
	/varcalc floatAAGained ${Math.Calc[${AAExpGain}/3.3]}

	/echo ------------------------------------------------------
	/if (${intKillCounter}>0) /echo - ${intKillCounter} kills in ${Int[${Math.Calc[${Macro.RunTime}/3600]}]} hours, ${Int[${Math.Calc[(${Macro.RunTime}%3600)/60]}]} mins, ${Int[${Math.Calc[(${Macro.RunTime}%60)]}]} seconds
	/if (${intKillCounter}>0) /echo - ${Math.Calc[${intKillCounter}/(${Macro.RunTime}/3600)]} kills per hour.
	/if (${intKillCounter}>0) /echo - You have gained ${floatGained}% Exp. Avg ${Math.Calc[${floatGained}/${intKillCounter}]} per kill.
	/if (${intKillCounter}>0) /echo - You have gained ${floatAAGained}% AA. Avg ${Math.Calc[${floatAAGained}/${intKillCounter}]} per kill.
	/if (${intKillCounter}>0) /echo - ${Math.Calc[(((${currentExp}-${startExp})/330)/(${Macro.RunTime}/3600))*100]}% XP per hour.
	/if (${intKillCounter}>0) /echo - ${Math.Calc[((${floatAAGained})/(${Macro.RunTime}/3600))]}% AA per hour.
	/if (${intLevelGain}>0) /echo - You have gained ${intLevelGain} level(s)
	/if (${AAPointGain}>0) /echo - You have gained ${AAPointGain} AA(s)
/return