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


# Original source  
http://zzz.bg/download/ZZZBaseMiniSampleStore_sources.zip  

# Original Inretnet site  
http://zzz.bg/zzzbase-mini/samples/store  
