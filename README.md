# arduino-smart-kitchen
Abstract:
	In present day, cost of LPG cylinders is very high and we need to be constantly vigilant while using it to reduce the danger.
	Usually when we heat a vessel, all the heat is not absorbed by it. Some of the heat goes to the surroundings, this heat goes unutilised usually. 
	So by using the concept of seedback effect we are generating electricity out of the heat which is not used.
	The gas stove has many smart features built in it to save us from accidents. The Ultrasonic Sensor present can help identify whether a vessel is placed on the stove or not while the regulator has been turned on. 
	The gas sensor helps in switching off the stove and in tripping the main circuit if there has been any possible leakage of the gas. This would prevent any major accidents from happening and also prevents the gas from being aflame due to the electronic circuit present.
	The user gets apt notifications about the same on his phone via the app. The gas stove can also be controlled via the smart app.


Existing Methodology & Problems:
	There are many technologies for gas detection like GSM, automatic regulator switch off, etc. But the key lies in integration and interlink to each of the systems and working as one
	The problem may be solved by a simple fan or placing an exhaust, in the long run they do not work as they can cause a problem indirectly by causing fire due to friction caused by turning of fan. 
	There are many solutions in the market available, but they are costly and not affordable by all of them and they do improve efficiency.



Proposed Methodology & Ideas:
	In case of any emergency like gas leakage it is detected by the gas sensors & then first it will switch off main power supply and alert the user by smart app.
	One of the most important feature of the app is "timed cooking”. Imagine a situation where we need to go out immediately and we have cook rice in the cooker which has to be turned off after 20 minutes.
	The gas stove gets switched off immediately after 20 minutes once set in the mobile app and also sends a message to the user that the gas stove has been turned off.
	In case we on the gas stove and don’t place the vessel, the gas stove would turn off after a couple of SECONDS.


Technology Stack:

Language Used: C Language based Arduino programming. 

Software Used: 
•	Arduino IDE
•	Android Studio
•	MIT App Inventor
•	Pololu and other Hardware divers

Hardware Used: 
•	Arduino Uno/Mega
•	HC-SR04 Ultrasonic Sensor
•	MG-995 Servo Motor
•	MQ 6 Gas Sensor
•	HC 05 Bluetooth Module
•	TEC1-12706 6A Peltier Module (Thermoelectric Cooler)



Advantages Of Using This Idea:
	It improves safety, ease of use & efficiency of the gas stove.
	It can be controlled via smart app.
	The “Timed Cooking” helps people to manage with their hectic schedule
	In case the gas stove is turned on and no vessel is placed, then, after a certain interval of time, the gas stove will turn off automatically.

