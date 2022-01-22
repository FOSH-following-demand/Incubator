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
2.	Using jumpers and dupont wires, Carefully connect all the sensors and other modules to the Arduino Uno Rev.3 microprocessor and to the breadboard following the equipment’s [electronic circuit diagrams](https://github.com/FOSH-following-demand/Incubator/blob/88bb84b1b9b74473d8da1b99ba0d825d767e2a87/hardware/electronics/incubator_bb.jpg). Use a standard IEC 1.5mm Electrical cable to connect the relay module, light bulb and power supply module.
3.	Using a digital multimeter, check all connections and the normal flows of current in the whole electric circuit.

### Uploading the software to the arduino board
4.	Connect the Arduino UNO board to a computer with the latest version of [Arduino IDE](https://www.arduino.cc/en/software) installed using a USB 2.0 A to B Cable.
5.	Open the [Incubator.ino](https://github.com/FOSH-following-demand/Incubator/blob/88bb84b1b9b74473d8da1b99ba0d825d767e2a87/software/Incubator.ino) software and on the software interface, click on **verify** to make sure all necessary libraries are installed. Wait until the message **Done compiling** and specific information about the program appears as shown on the picture <img src="https://github.com/FOSH-following-demand/Incubator/blob/master/documentation/images/Program%20Upload1.png" width="33%"/> .   
6.	Select the right port and on the software interface click on **upload** to upload the program to the board. Wait until the message **Done uploading** is displayed. 

### Constructing the electronics enclosure and Integrating the electronics
7.	Use the 2D CAD file: [Incubator_Enclosure](https://github.com/FOSH-following-demand/Incubator/blob/88bb84b1b9b74473d8da1b99ba0d825d767e2a87/hardware/enclosure/Incubator_Enclosure_MboaLab.pdf), to laser-cut plywood or acrylic to make the electronic enclosure of the incubator. 5mm colored acrylic or 4mm plywood is recommended. Use acrylic glue or Wood glue to assemble cut pieces and first mount the base of the box. 
8.	At this point, place the base above the cooler box cover at the location you want the electronic box to fit (center position preferred); 
9.	Use an electric drill to make a hole (1cm) crossing the acrylic and the entire depth of the cooler box cover.
10.	Drill another hole (1cm) on the side, just below the handle of the cooler box.
11.	Send the temperature sensor inside the cooler box through the created hole on the side. 
12.	Send light bulb cable through the created hole on the cooler box cover and carefully place all electronic parts inside the electronics enclosure.
13.	Use double side tape to fix the electronic enclosure to the cooler box cover.
14.	Screw the bulb holder on the donwnside of the cooler box cover and place an incandescent bulb. 
15.	Turn on the circuit and check if the light bulb is switched on and other sensors are operational.
16.	Place the cover of the electronic box (don’t use acrylic glue or Wood glue to seal the box) the cover should remain easily removable for maintenance.

### Checking that it works
17.	Use a separate thermometer to verify that the temperature reaches and is maintained at the correct set point.
18.	Check and follow [Using](https://github.com/FOSH-following-demand/Incubator/blob/e79139635490b86b92911df16381e2448330a7f6/documentation/using/using.md) for Operation Manual to ensure normal use and behavior of the equipment.

