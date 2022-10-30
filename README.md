# System-Programming-with-Linux-Assignment-6

## Commands
- $ gcc myfdisk.c -o myfdisk
- ./myfdisk filename


## My output
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

## fdisk -l Output
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
