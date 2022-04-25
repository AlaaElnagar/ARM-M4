# ARM-M4
## This repo related to ARM M4 course preparation   
![Getting Started](imgs/img1.png)

## CH0-History of ARM:
### The Beginning:<br /> 
## ⚡Acorn Computers Ltd <br />
Founded at **1980’s**.<br /> 
the reasoning behind the naming of Acorn was to be ahead of Apple computers in the telephone directory!<br />  Fast forward a few years they produce the BBC Micro, a government initiative to put a computer in every classroom in Britain with a little task of coming up with the microprocessor design for Acorn’s own 32 bit processor with little to no resources therefore the design had to be good and simple **Arm1**
<br />Development on the Acorn RISC Machine didn't start until some time around late **1983** or early **1984**<br />
**26th April 1985** **Arm2**<br />
 Acorn Archimedes which was released in 1987, was the first RISC based home computer<br />
 **1990 as Advanced RISC Machines Ltd**<br />
 tructured as a joint venture between Acorn Computers, Apple Computer (now Apple Inc.) and VLSI Technology. The reason for this was because Apple wanted to use Arm technology but didn’t want to base a product on Acorn IP – who, at the time were considered a competitor. Apple invested the cash, VLSI Technology provided the tools, and Acorn provided the **12 engineers** and with that Arm was born, and its luxury office in Cambridge – A barn!<br />
 <p align="center">
  <img src="imgs/img3.jpg" />  
</p>

  **They created**  <br />
 Cambridge Processor Unit or CPU
 in 1993 the Apple Newton was launched on Arm architecture.
t wasn't the best piece of technology, as unfortunately Apple over reached for the technology that was available for them at the time - the Newton has flaws which lowered its usability vastly. Due to these factors Arm realized they could not sustain success on single products<br />

## ARM Supply processor architecture
 The Arm processor was licensed to many semiconductor companies for an upfront license fee and then royalties on production silicon. This made Arm a partner to all these companies, effectively trying to speed up their time to market as it benefited both Arm and its partners. For me personally

## TI, Arm7, and Nokia
The crucial break for Arm came in 1993 with Texas Instruments (TI). This was the breakthrough design that gave Arm credibility and proved the successful viability of the company’s novel licensing business model. The deal drove Arm to formalize their licensing business model and also drove them to make more cost-effective products. Such deals with Samsung and Sharp proved networking within the industry was crucial in infecting enthusiastic support for Arm’s products and in gaining new licensing deals. These licensing deals also led to new opportunities for the development of the RISC architecture. Arm’s relatively small size and dynamic culture gave it a response-time advantage in product development. Arm’s hard work came to fruition in 1994, during the mobile revolution when realistic small mobile devices were a reality. The stars aligned and Arm was in the right place at the right time. Nokia were advised to use Arm based system design from TI for their upcoming GSM mobile phone. Due to memory concerns Nokia were against using Arm because of overall system cost to produce. This led to Arm creating a custom 16 bit per instruction set that lowered the memory demands, and this was the design that was licensed by TI and sold to Nokia. The first Arm powered GSM phone was the Nokia6110 and this was a massive success. The Arm7 became the flagship mobile design for Arm and has since been used by over 165 licensees and has produced over **10 Billion chips since 1994.**
<p align="center">
  <img src="imgs/img4.jpg" />
    
</p>

## Going Public
By the end of 1997, Arm had grown to become a £26.6m private business with £2.9m net income and the time had come to float the company. Although the company had been preparing to float for three years, the tech sector was in a bubble at the time and everyone involved was very apprehensive, but felt it was the right move for the company to capitalize on the massive investment in the tech sector of the time.

On April 17th, 1998, Arm Holdings PLC completed a joint listing on the London Stock Exchange and NASDAQ with an IPO at £5.75. The reason for the joint listing was twofold. First, NASDAQ was the market through which Arm believed it would gain the sort of valuation it deserved in the tech bubble of the time which was mainly based out of the states. Second, the two major shareholders of Arm were American and English, and Arm wished to allow existing Acorn shareholders in the UK to have continued involvement. Arm going public caused the stock to soar and turned the small British semiconductor design company into a Billion Dollar company in a matter of months!
<p align="center">
  <img src="imgs/img5.jpg" />
</p>

## reference
https://community.arm.com/arm-community-blogs/b/architectures-and-processors-blog/posts/a-brief-history-of-arm-part-1
___
## ARM categories    
![Getting Started](imgs/img6.png)
**ARM divided into 3 main categories** <br />
Cortex -A : [Application]For graphics and rich OS<br />
Cortex -R : [Response]For high response systems like antena <br />
Cortex -M :[Medium]For embedded applications <br />
**ARM categories performance**<br />

![Getting Started](imgs/img7.png)
**ARM partners**<br />

![Getting Started](imgs/img8.jpg)

**ARM Major characteristics**<br />
| High performance | Low cost | Low power <br />
|Enhanced determinisim | Ease of use | wide choices <br />

# ATmega32 VS stm32
| Comparassion    | ATmega32        |  STM 32F103C8T6 |
| :------------   |:---------------:| -----:          |
| Processor       | 8bit            | 32 bit          |
| Frequancy       | 16mhz           | 72mhz           |
| Flash           | 32K             | 64k             |
| RAM             | 2K              | 20k             |
| I/O             | 32Pin           | 35Pin           |
| Timers          | 3               |  9              |
| ADC             | 8 Channels      |  10             |
| USART           | 1               |  3              | 
| SPI             | 1               |  2              |
| I2C             | 1               |  2              |
| DMA             | N/A             |  1              |
| CAN             | N/A             |  1              |
| RTC             | N/A             |  1              |
| Power           | 5v              |  3.3v           |
 <br />
# How processor work
code is converted into machine language and stored in memory processor contains unit called control unit which contain fetching circuit to get instruction into processor then another circuit called instruction decoder satart to understand the fetched instruction, To understand instruction instruction decoder need two main informations OP code of each instruction for example ADD -->101 the second info is instruction format which divide instruction into three main parts OP code, operand1 and operand2 Another circuit is needed which is called ALU to perform opcode in selection signal to excuite opcode in operand1 and operand2 

**Register bank**
A set of registers in processor (small RAM) each location has special functionality for example 
01-PC program counter to track instructions in memory <br />
02-IR instruction register to store fetched instruction  <br />
03-ACC Acumulator which contains result from ALU <br />
04-PSW Processor status word which contains a set of flags(bits) for example overflow flag, negative flag[1111111]=255 or -1 this flag define negative one or 255, Zerro flag  <br />
05-GPR General purpose registers for fast accessing 
## Hints Dont forget to add some pictures for <br >01- beaglbone<br > 02- Intell galilio <br >03- Ti <br >
# What is new in ARM processor
ARM contains core prepherials exists in the processor <br >
01- NVIC      Nested vector interrupt controller<br >
02- SYSTIC    Timer inside the processor 24 bit <br >
03- MPU       Memory protection unit<br > 
04- ICD       in circuit debugger<br >
### Data buses <br >
01- Address bus<br > Bus neededd to address specific address
02- Data bus<br > Bus needed to transmit or receive data
03- Controll<br > bus Bus needed to send controll commands 
Bus set is a set of data, controll and address buses 
### Harvard Vs Vonnumen architecture
***Harvard is complex !***
Harvard has different asembly instructions for accessing specific bus set
if code in c then the diffult access is RAM bus set  
### Pipeliming concept 
in Harverd architecture there is different bus set for proividing excution of more than one instruction cycle at same time 

ARM Mix between harvard and von-numen
## Questions 
What is the difference between instruction cycle , clock cycle and machie cycle <br >
Clock cycle it generated from clock in hz<br >
Machine cycle the actual clock after prescaller<br >
instruction cycle number for cycle for fetching decoding and excuiting the instruction<br >
[Note]  
16/32 bit instruction is called thumb2 
insurction can be fetched in morethan one cycle for ASK ?

## ToDo
Cemsis<br >
Eclipse debugging <br >
Outlines <br >
## Lec2
***processor*** <br >
Each proecessor Control unit contains a fetching circuit for fetching the instruction and understand it using instruction format and instruction set to decode the instruction then the decoded instruction is enter to ALU to be excuited for op1,op2 and opcode which will be in the selector and then the result will bw in the accumulator <br >
***Memory*** <br >
Development time : Time of development 
Building time    : Time of building the code to get hex 
profiling        : getting memory size needed for uploading the code
Flashing         : Time of burning or flashing the code using flasher or programmer 
The code is represented in the memory using electrical signal on or off zero or one 
Memory can be implemented using:<br >
01- Capacitor  : Charged then one represented in the memory <br >
02- Transistor : Saturation mode "short circuit" which represent 1 
Open circuit mode "represent zero"

|Comparassion       |Transistor           | Capacitor      |
|----------|------------------------------|----------------|
|  Performande         |High                              |Low            |
|  Cost        |High                              |Low                |
|  Size        |Low                              |High                |
|  Power Consum.        |Low                              |High                |
|  Name.        |SRAM                              |DRAM                |

Cpacitor consume a high power because  a refreshment circuit is needed to save charge 
Note: Both DRAM And SRAM are volatile and will not save code text in the flash memory so a 
<br >***floating gate mosfet is needed***<br >
floating gate mosfet is non volatile 
01-Control gate: which receive the signal to be applied on the mosfet and need to be high power to penetrate isolator<br >
02-Isolator     : Exist between control gate and floating gate<br > 
03-Floating gate: a gate which hold the signal between source and drain<br> 
04-Source: like collector of transisor<br >
05-Drain : like transistor collector <br >
if ther a charge stored in the floating gate then Retention time will be 50 years and then it will lose it's charge 
Float gate mosfet may be:<br >
 01-charged then applied signal to gate is zerro
 <br >02-Not charged then applied signal to gate is 1
<br >Note : when the memory is cleared then it will contains ones 
Disadvantages of floating gate mosfet:
01- Nonvolatile    : Which read only for processor and processor can't write over it 
02- Need High powr : to break floating gate mosfet 
### Memories based on float gate mosfet:
***Masked ROM:***
A memory which come already programed and we can't programe it 
<br >***OTP ROM:***
A memory which can be programed only once by the user  
<br >***EPROM:***
Erasable programable ROM can be programed using burner by electricity and can be erased by ultravilot `Widdly used in weapons manufacturing `
<br >***EEPROM:***
Electricall ersable programble can be programed and erased using electricity
<br >***Flash:***
Electricall ersable programble can be programed and erased using electricity

|Comparassion       |EEPROM           | FLASH      |
|----------|------------------------------|----------------|
|  Accessing[write/erasing]         |Byte access                              |Block access            |
|  Cost        |High[need more transistors to access byte]                             |Low                |
|  Endurance        |100,000 write erase                             |10,000                |


[Note]
To undertand relation between flash and EEPROM <br >
Flash access time for example take   10us <br >
EEPROM access time for example take   1us <br >
Case1: Write one byte ``EEPROM`` Will consume 1us and ``Flash`` will consume 10 us which means EEPROM is faster for byte access 
<br >Case2: Write 100 bytes ``EEPROM`` Will consume 100us and ``Flash`` will consume 10 us which means flash is faster for block access<br >

***conclusion:***<br >
Memory divided into two main types <br >
01-Volatile     : [RAM(SRAM-DRAM)]<br >
02-Non-Volatile : [ROM(MASKED-OTP-EPROM-EEPROM-FLASH)]<br >

## Micro controller architecture 
processor contains bus set and flash also contains a bus set which allows processr to be able to access flash one of buses in the bus set is the data bus wich able to connect to a ***specific locations with a specific word size or location width*** so each processor contains memory size to be able to connect a specic size of memory based on address bus and processor contains a specific word size to be able to implement [fetch-decode-excuite]cycles on it 

## Harvard Vs Vonnumnen 

## ARM Architecture 
Arm is internally harvard architecture which appear as vonnumen have single bus set And contains three main bus set<br >
01- IBUS :Instruction Bus -->|------------ |              
02- DBUS :Data Bus-------->|   Bus Matrix   | ------>single Bus set      <br >
03- SBus :System Bus ------>|------------ |          <br >

Bus matrix convert addresses by adding offsets to the address nedded by the processor when one of the BUS set is need to communicate with other memories of RAM, Flash and IO Memory 
## Lec3
ARM Set a protocol to the vendor to follow through manufacturing 
the protocol is called **AMBA** Advanced microcontroller architecture AMBA contains a set of protocols which can be followed by the vendor, The main two protocols in AMBA are <br >
01- AHB Advanced High Performance bus 
      - High Power<br >
      - Complex design wiring  <br >
      - Multi master "More than one prepherial can start communication"
      - Full douplex<br >

02- APB Advanced Peripheral bus<br >
      - Low Power<br >
      - less complexity<br >
      - Low performance <br >

The bus set which out of bus matrix is AHB advanced high performance bus
the peripherials made by vendor will be coonnected to this AHB protocol for example RCC <br >
there is a bridge which is used to convert from AHB to APB as shown 
<p align="center">
  <img src="imgs/img12.png" />
</p>
Note in the above picture all not in red colour is designed by ARM 
if all prepherials are connected to AHBspeed[72Mhz] it will consume a high power so connect to more lower power protocol APB2 is higher speed[72Mhz] than APB1[36Mhz]

# Steps of programming the chip :
01- Know about needed documents to read from 
02- Know prepherial Bus[AHP-APB] from ST document 
## The Documments 
***ARM*** : Programming manual if you need to get information about coreprepheral<br >
***ST***  : Register description for getting information about vendor prepherial <br >

To know the bus which the prepherial will be connected to open st document "Register description" to get the conected bus 
## AHP Bus connected prepherials 
Note Boundery address is the register reserved addresses 
<p align="center">
  <img src="imgs/img9.png" />
</p>
APB2 
<p align="center">
  <img src="imgs/img10.png" /> 
</p>
APB1
<p align="center">
  <img src="imgs/img11.png" /> 
</p>

--------------------------------------------------------------------
## Software development cycle 
<p align="center">
  <img src="imgs/img13.png" /> 
</p>

01-***RFQ***:At starting of the project business analyst responsible communicate with the customer to make RFQ `Request for qutation`Document which based on defining cost and time of the project <br >
02-***CRS***:Customer requirement specification detailed technical requirement in the SW which developed by the technical team which converted RFQ into CRS 
The Requirements may be done by `system engineer` who define that  <br >
HSI : Hardware software interface to define hardware requirement document which is hardware team responsibility  <br >
SRS : Software requirement specification document which is sw team responsibility  <br >
03-`System ARchitect`: a person who responsible for making static architecture and dynamic architecture to produce HLD Document `High level design document`<br > 
<p align="center">
  <img src="imgs/img14.png" /> 
</p>

***Static Architecture*** : define system software component in layerd model or layerd diagram which named as  [sw component = sw module =sw driver] and consist of:<br >
01-MCAL : contains in controller prepherial : DIO,ADC,UART.....[FirmaWare Engineer responsibility]<br >
02-HAL  : Hardware abstraction layer [FirmaWare Engineer responsibility]:Motor,TFT,WIFI...........<br >
03-APP  : Main which contain the system sequences [Application Engineer responsibility]<br >
Note : any component can call a component from the layers which is down 
one of the common component in the static architecture is the Lib which is called by the other layer and can no't call any layer for example `stdTypes`<br >
Static architecture contains a tables of function names, Arguments and return values <br >
***dynamic Architecture*** :contains all informations related to [Excution time of each function - function ram consumption - ROM consumption `flash` ]<br >
04-`Designer` design a diagram for each function using UML language which descripe how it will work according to system architect requirements as memory and excution time  [Flow chart "Activity diagram", State machine, state chart , sequance diagram] the designer responsible for making ***CDD*** document or each software component <br >
<p align="center">
  <img src="imgs/img15.png" /> 
</p>

05-`Developer` responsible for 
DDD :detailed design document which is an optional step as psoducode for the system  and made by developer <br >
06-unit testing : for each function  `by developer`<br >
07-Component testing : each swc alone testing  `tester`  <br >
09-integration testing : integration of all software components `tester` responsibility<br >
10-Validation testing  : Upploading the sw on the board and done by `validator`  <br >
Other supporting positions in the development : Quality assuarance and tooling 

# Q&A
ARM IS HYPERD :actually arm is Harvard but it is working as vonnument because of bus matrix  <br >
01-What advantages of core prepherials : fast access and reusability incase of dealing with the same core such as  stM4 like  TIVA M4 software <br >
02-what is cash memory : sram exists in the processor and faster than external ram and slower than GPR <br >

------------------------
Files in c .h and .c : .c is compiled file and .h is included inside .c file 
Note file Guard is very important to avoid calling more than one file at the same time 
<p align="center">
  <img src="imgs/img16.png" /> 
</p>

### Clock system :
is a periodic pulses to organise fetch microcycle, decode microcycle and excuite microcycle cycle 
main types of clock may be </p>
01- Electrical </p>
02- Mechanical </p>
        -Ceramic `Oscilator`</p>
        -Crystal `Resenator`</p>
Note settling time is the time needed to reach steady state 
<p align="center">
  <img src="imgs/img17.png" /> 
</p>

# Lec4

ARm is Harvard Architecture but act as vonnumen becuase of bus matrix
The main step to deal with any prepherial is to know the the bus which will be connected to to know it's clock frequency will be suitable or not<br >
***RCC*** :Reset and clock controll responsible for controller reset and adjust system clock, this prepherial is vendor prepherial made by ST to controll arm processor clock <BR >
`Processor Bus matrix, AHP, APP and bridges are made by ARM `
<p align="center">
  <img src="imgs/img18.png" /> 
</p>

RCC CAN supply three types of clocks and connected bypass through xtal1 pin and xtal2 not connected <br >
HSI : High speed interanal "Interanl clock" of RC type provide 8Mhz 

HSE : High speed external "External connected clock" may be RC or Crystal type `4-16 Mhz incase of Crystal` type and up to `25 Mhz incase of RC`

PLL : Phase locked loop to amplify the clock <span style="color: green"> can work with internal clock to amplify it, PLL internal clock is RC</span>

Note: Processor able to work with 72 Mhz but from PLL<br >
Rcc provide processor clock selection  

<p align="center">
  <img src="imgs/img19.png" /> 
</p>

RCC : Responsible for Enabling and disabling clock which will be passed to the controller 
Q: Does prepherial consume power incase of enable bit is off answer is Yes 
<br > Because there is a circuit which is called `enable check circuit` check if prepherial enable pin is active or not, we can disable enable check circuit by switching off the clock using RCC 
  
So rcc can be use used to enable prepherial clock and select clock value 
<br >

Elements which have clock by default are :<br >
01 - RCC <br >
02 - Core prepherial 
<p align="center">
  <img src="imgs/img20.png" /> 
</p>

<span style="color: red"> [NOTE] : There is a memory buffer register responsible for data instruction to fetch data  </span>
<span style="color: green"><br> Crystal connected to micro controller XTAL1 and XTAL2 where RCC is connected to external vcc ...? <br>Becuase RCC need stable dc without ribbles and microcontroller output dc not sharp dc   </span><br>
<span style="color: red">  How pll works internally...?  </span>
