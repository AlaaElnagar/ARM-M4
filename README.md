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
