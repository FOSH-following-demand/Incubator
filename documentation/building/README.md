## Getting started with assembly

This equipment is an incubator, designed to keep the contents at a constant temperature above the ambient temperature. It is an insulated box (a cooler box) that contains a heater (lightbulb), a temperature sensor and some electronics and software that will control the temperature to keep it constant at the level input by the user.

The primary use case is microbiology. It is essential for many protocols to have optimal growth temperature for important microrganisms such as _Escherichia coli_ bacteria. However, mst biology labs in Cameroon and elsewhere in resource-constrained contexts are under-equipped due to the high cost of lab equipment. Other use cases include a drying chamber and a yoghurt maker.

To build the device you will need to undertake some basic soldering and load software onto an Arduino Uno microcontroller but you do not need to have prior experience as there are many tutorials and guides online. This build could be completed by one person in less than a day with all materials and facilities available.

If you have questions you can contact [@LabMboa](https://twitter.com/labmboa?lang=en) on Twitter or via email mboalab@gmail.com

<img src="https://github.com/FOSH-following-demand/Incubator/blob/master/documentation/images/electronics_enclosure.jpg" width="33%"/> <img src="https://github.com/FOSH-following-demand/Incubator/blob/master/documentation/images/incubator_team.jpg" width="33%"/> <img src="https://github.com/FOSH-following-demand/Incubator/blob/master/documentation/images/closed_incubator_frontview.jpg" width="33%"/> 
<br>

## Gathering your materials

The list of components and tools required can be found in the [Bill of Materials](https://github.com/FOSH-following-demand/Incubator/blob/master/hardware/BOM/BOM.md). 

<br>


## Build Steps

### Assembling the electronics
1.	Gather all necessary equipment, electronics and sensors listed in the [BOM](https://github.com/FOSH-following-demand/Incubator/blob/88bb84b1b9b74473d8da1b99ba0d825d767e2a87/hardware/BOM/BOM.md), keep your soldering kit and Digital multimeter ready to check connections and normal operation after soldering. 
2.	Using a breadboard, Carefully connect all the sensors and other modules to the Arduino Uno microprocessor following the equipment’s [electronic circuit diagrams](https://github.com/FOSH-following-demand/Incubator/blob/88bb84b1b9b74473d8da1b99ba0d825d767e2a87/hardware/electronics/incubator_bb.jpg). Most connections are made through jumpers, relay module, light bulb and power supply module are connected with standard IEC Electrical power cables.
3.	Using a multimeter make sure all connections are ok and that the current flows normally.
4.	Connect the Arduino UNO board to a computer with the latest version of Arduino IDE installed using a USB-Arduino Uno cable.
5.	Open the [Incubator.ino](https://github.com/FOSH-following-demand/Incubator/blob/88bb84b1b9b74473d8da1b99ba0d825d767e2a87/software/Incubator.ino) software and click on verify to make sure that the entire necessary libraries are installed.
6.	Select the right port and Upload the program to the board.
7.	Turn on the On/Off button and make sure the incandescent bulb comes on and all electronic parts work normally. 

### Constructing the electronics enclosure
8.	Use the 2D CAD files: [Incubator_Enclosure](https://github.com/FOSH-following-demand/Incubator/blob/88bb84b1b9b74473d8da1b99ba0d825d767e2a87/hardware/enclosure/Incubator_Enclosure_MboaLab.pdf), to laser-cut plywood or acrylic to make the electronic enclosure of the incubator. 4-5mm colored acrylic is recommended. Use acrylic glue to assemble cut pieces and first mount the base of the box. 
9.	At this point, place the base above the cooler box cover at the location you want the electronic box to fit (center position preferred); 
10.	Use an electric drill to make a hole at the center and bottom of the box, crossing the acrylic and the entire depth of the cooler box cover. 
11.	Send light bulb cable through the created hole and carefully place electronic parts inside the box; Double side tape can be used to fix elements in the box
12.	Place the bulb holder below the cooler box cover and place an incandescent bulb. 
13.	Turn on the circuit and check if the light bulb is switched on and other sensors are operational
14.	Shut down and solder where applicable.

### Integrating the electronics with the cooler box
15.	Carefully fix the electronic control box on top of the cooler box lid using double-sided tape.
16.	Make sure to adjust the distance of the cable, keeping a distance of 3cm between the light bulb and the bottom of the cooler box cover. 
17.	Use the electric drill to make another hole on the side of the main body of the cooler box for the temperature sensor cable, and place the sensor inside the cooler box.
18.	After checking that everything is still operational, place the acrylic cover on top of the electronic box (don’t use acrylic glue to seal the box) the cover should remain easily removable for maintenance.

### Checking that it works
19.	Use a separate thermometer to verify that the temperature reaches and is maintained at the correct set point.
20.	Check and follow [Using](https://github.com/FOSH-following-demand/Incubator/blob/e79139635490b86b92911df16381e2448330a7f6/documentation/using/using.md) for Operation Manual to ensure normal use and behavior of the equipment.

