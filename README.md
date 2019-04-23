# mini-warehouse
Mini Warehouse about 300 lines source code in C++  
Supports:  
- multilanguage item names and measures (utf-8);  
- billions of items;  
- Linux, Windows, Mac OS X operating systems.  

## How to use it?
### From the command line (terminal):

#### Add stock
**Usage:**  
ZZZBaseMiniSampleStore addStock {id} {name} {measure} {quantity} {price}  
**Sample:**  
ZZZBaseMiniSampleStore addStock 1 "green apples" kg 10 3.28  
ZZZBaseMiniSampleStore addStock 2 pears kg 18 4.92  

#### Get stock
**Usage:**  
ZZZBaseMiniSampleStore getStock {id} {quantity}  
**Sample:**  
ZZZBaseMiniSampleStore getStock 1 2  
ZZZBaseMiniSampleStore getStock 2 3  

#### Report all
**Sample:**  
ZZZBaseMiniSampleStore report all  
**Result:**  
1, green apples, kg, 8, 3.28  
2, pears, kg, 15, 4.92  

#### Report stock
**Usage:**  
ZZZBaseMiniSampleStore report {id}  
**Sample:**  
ZZZBaseMiniSampleStore report 1  
**Result:**  
1, green apples, kg, 8, 3.28  


## Original source  
http://zzz.bg/download/ZZZBaseMiniSampleStore_sources.zip  

## Original Internet site  
http://zzz.bg/zzzbase-mini/samples/store  

## How to build it?
### For Windows operating system
1. Clone the project:  
````
    git clone https://github.com/alphasoftwarebg/mini-warehouse.git c:\mini-warehouse  
````
2. Start "Developer Command Prompt" for MS Visual Studio  
3. Go to the cloned mini-warehouse project folder:  
````
    c:  
    cd c:\mini-warehouse  
````
4. Start batch file build32.bat:  
````
    build32.bat  
````
5. Go to subfolder bin  
````
    cd bin  
````
6. Use the compiled mini-warehouse program  
````
    ZZZBaseMiniSamplesStore_Windows_32bit.exe addStock 1 "green apples" kg 10 3.28  
    ZZZBaseMiniSamplesStore_Windows_32bit.exe addStock 2 pears kg 18 4.92  
    ZZZBaseMiniSamplesStore_Windows_32bit.exe getStock 1 2  
    ZZZBaseMiniSamplesStore_Windows_32bit.exe getStock 2 3  
    ZZZBaseMiniSamplesStore_Windows_32bit.exe report all  
````
### For Linux or Mac OS X operating systems
1. Clone the project:  
````
    git clone https://github.com/alphasoftwarebg/mini-warehouse.git  
````
2. Go to the cloned mini-warehouse project folder:  
````
    cd mini-warehouse  
````
3. Make mini-warehouse project:  
````
    make -g Makefile.Linux  
````
4. Go to subfolder bin  
````
    cd bin  
````
5. Use the compiled mini-warehouse program  
#### For 32 bit versions of Linux operating system
    ZZZBaseMiniSampleStore_Linux_32bit_a addStock 1 "green apples" kg 10 3.28  
    ZZZBaseMiniSampleStore_Linux_32bit_a addStock 2 pears kg 18 4.92  
    ZZZBaseMiniSampleStore_Linux_32bit_a getStock 1 2  
    ZZZBaseMiniSampleStore_Linux_32bit_a getStock 2 3  
    ZZZBaseMiniSampleStore_Linux_32bit_a report all  
#### For 64 bit versions of Linux operating system
    ZZZBaseMiniSampleStore_Linux_64bit_a addStock 1 "green apples" kg 10 3.28  
    ZZZBaseMiniSampleStore_Linux_64bit_a addStock 2 pears kg 18 4.92  
    ZZZBaseMiniSampleStore_Linux_64bit_a getStock 1 2  
    ZZZBaseMiniSampleStore_Linux_64bit_a getStock 2 3  
    ZZZBaseMiniSampleStore_Linux_64bit_a report all  
