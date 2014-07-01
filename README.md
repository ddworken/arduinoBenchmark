readme.md

arduinoBenchmark
================
###Note that the design/calculations of this benchmark have not been finalized yet. Any values/methods of calculating scores are subject to change. 
A benchmarking suite meant to be run on Arduinos. This was created because there is very little concrete data comparing different Arduinos in a quantitative manner. 

Usage
================
Download benchmark.ino and open it in the Arduino IDE. Upload to the Arduino and monitor the Serial Monitor for data on Arduino performance. If you want to contribute your data to this project, please copy and paste it into a new issue titled "Data: \<Name of Arduino\>" so it can be added to the data listing. 

Data
================
| Arduino Model | EEPROM Read | EEPROM Write | Integer Addition/Subtraction | Integer Multiplication | Integer Division | Floating Point Addition/Subtraction |Floating Point Multiplication | Floating Point Division | Analog Read | 
| ------------- |:-----------:| ------------:|-----------------------------:|-----------------------:|-----------------:| -----------------------------------:| ----------------------------:| -----------------------:| -----------:|
|Uno            | 1868        | 1724         | 138                          | 138                    | 3117             | 2845                                | 2374                         | 6557                    | 1120        |
|Micro          | 2213        | 1729         | 139                          | 141                    | 2945             | 2847                                | 2359                         | 6611                    | null        |
