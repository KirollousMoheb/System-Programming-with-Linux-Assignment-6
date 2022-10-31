# System-Programming-with-Linux-Assignment-6

## Commands
### For MBR Partitioning
- $ gcc myfdisk.c -o myfdisk
- ./myfdisk filename

### For GPT Partitioning
- $ gcc gpt.c -o gpt
- ./gpt filename

## Output
### My MBR output
```
=========================================================================================
Device     Boot       Start      End        Sectors      Size          ID          Type 
=========================================================================================
myhd1                 1          512        512          256.0K       83           Linux       
myhd2                 513        1024       512          256.0K       83           Linux       
myhd3                 1025       1536       512          256.0K       5            Extended    
myhd4                 1537       2047       511          255.5K       83           Linux       
myhd5                 1030       1300       271          135.5K       83           Linux       
myhd6                 1302       1400       99           49.5K       83           Linux       
myhd7                 1401       1536       136          68.0K       83           Linux 
```

### fdisk MBR Output
```
Device Boot Start   End Sectors   Size Id Type
myhd1           1   512     512   256K 83 Linux
myhd2         513  1024     512   256K 83 Linux
myhd3        1025  1536     512   256K  5 Extended
myhd4        1537  2047     511 255.5K 83 Linux
myhd5        1030  1300     271 135.5K 83 Linux
myhd6        1302  1400      99  49.5K 83 Linux
myhd7        1401  1536     136    68K 83 Linux
```
### My GPT output
```
=================================================================
Signature: EFI PART
Revision: 00000100
Header Size: 92
Header CRC32: -2021987573
Reserved : 0
Current LBA : 1
Backup LBA : 1953525167
First Usable LBA : 34
Last Usable LBA : 1953525134
UID : 952545AE-65EE-4FE7-A011-F08FA6C79829
Parition Entry Start LBA : 2
Number of Partition Entries : 128
Partition Entry Size : 128
CRC Partition Array : 1049545695

=================================================================
Device           Start      End        Sectors       Size     
=================================================================
/dev/sda1        2048       534527     532480       260.0M 
/dev/sda2        534528     567295     32768        16.0M 
/dev/sda3        567296     579315711  578748416    276.0G 
/dev/sda4        579315712  927473663  348157952    166.0G 
/dev/sda5        927475712  1541873663 614397952    293.0G 
/dev/sda6        1541873664 1890033663 348160000    166.0G 
/dev/sda7        1951475712 1953523711 2048000      1000.0M 
/dev/sda8        1890033664 1938862079 48828416     23.3G 
/dev/sda9        1938862080 1951475711 12613632     6.0G 
```

### fdisk GPT Output
```
Device          Start        End   Sectors  Size Type
/dev/sda1        2048     534527    532480  260M EFI System
/dev/sda2      534528     567295     32768   16M Microsoft reserved
/dev/sda3      567296  579315711 578748416  276G Microsoft basic data
/dev/sda4   579315712  927473663 348157952  166G Microsoft basic data
/dev/sda5   927475712 1541873663 614397952  293G Microsoft basic data
/dev/sda6  1541873664 1890033663 348160000  166G Microsoft basic data
/dev/sda7  1951475712 1953523711   2048000 1000M Windows recovery environment
/dev/sda8  1890033664 1938862079  48828416 23.3G Linux filesystem
/dev/sda9  1938862080 1951475711  12613632    6G Linux swap

```
