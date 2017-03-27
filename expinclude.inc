#EVENT expgain "You gain party experience!!"

Sub EVENT_expgain
	/if (!${Defined[intKillCounter]}) /declare intKillCounter int outer 0
	/if (!${Defined[currentExp]}) /declare currentExp int outer 0
	/if (!${Defined[intLevel]}) /declare intLevel int outer ${Me.Level}
	/if (!${Defined[intLevelGain]}) /declare intLevelGain int outer 0
	/if (!${Defined[floatPerKill]}) /declare floatPerKill float outer 0
	/if (!${Defined[floatGained]}) /declare floatGained float outer 0
	/if (!${Defined[startExp]}) {
		/declare startExp int outer 0
		/varcalc startExp 330*${Me.Level}+${Me.Exp}
		/return
	}
	/varcalc intLevelGain ${Me.Level}-${intLevel}
	/varcalc intKillCounter ${intKillCounter}+1
	/varcalc currentExp ${Math.Calc[330*${Me.Level}+${Me.Exp}]}
	/varcalc floatGained ${Math.Calc[((${currentExp}-${startExp})/330)*100]}
	/echo ------------------------------------------------------
	/if (${intKillCounter}>0) /echo - ${intKillCounter} kills in ${Int[${Math.Calc[${Macro.RunTime}/3600]}]} hours, ${Int[${Math.Calc[(${Macro.RunTime}%3600)/60]}]} mins, ${Int[${Math.Calc[(${Macro.RunTime}%60)]}]} seconds
	/if (${intKillCounter}>0) /echo - ${Math.Calc[${intKillCounter}/(${Macro.RunTime}/3600)]} kills per hour.
	/if (${intKillCounter}>0) /echo - You have gained ${floatGained}% Avg ${Math.Calc[${floatGained}/${intKillCounter}]} per kill.
	/if (${intKillCounter}>0) /echo - ${Math.Calc[(((${currentExp}-${startExp})/330)/(${Macro.RunTime}/3600))*100]}% per hour.
	/if (${intLevelGain}>0) /echo - You have gained ${intLevelGain} level(s)
/return