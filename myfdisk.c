#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  uint8_t status;
  uint8_t first_chs[3];
  uint8_t partition_type;
  uint8_t last_chs[3];
  uint32_t lba;
  uint32_t sector_count;

} PartitionEntry;

char * convertSize(uint64_t bytes){
 static char str[20];

  long gb = 1024 * 1024 * 1024;
  long mb = 1024 * 1024;
  long kb = 1024;
  if( bytes >= gb){
  sprintf(str,"%0.1fG",(float)bytes/gb);
  } 
  if( bytes >= mb){
  sprintf(str,"%0.1fM",(float)bytes/mb);
  } 
  if( bytes >= kb){
  sprintf(str,"%0.1fK",(float)bytes/kb);
  } else{
  sprintf(str,"%ldB",bytes);
  }
return str;
}

int
main (int argc, char **argv)
{


  char buf[512];
  int extended_index = -1;
  uint32_t extended_partition_start = 0;
  int fd = open (argv[1], O_RDONLY);
  int partition_count = 1;
  read (fd, buf, 512);
  PartitionEntry *partitionentryptr = (PartitionEntry *) & buf[446];
  printf
    ("=========================================================================================\n");
  printf ("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s \n", "Device",
	  "Boot", "Start", "End", "Sectors", "  Size", "     ID",
	  "      Type");
  printf
    ("=========================================================================================\n");

  int i;
  for (i = 0; i < 4; i++)
    {
      if (partitionentryptr[i].sector_count == 0)
	{
	  continue;
	}
      printf ("%s%-5d %-5c       %-10u %-10u %-12u %s       %-12X %-12s\n",
	      argv[1], partition_count++,
	      partitionentryptr[i].status == 0x80 ? '*' : ' ',
	      partitionentryptr[i].lba,
	      partitionentryptr[i].lba + partitionentryptr[i].sector_count -
	      1, partitionentryptr[i].sector_count,
	      convertSize((uint64_t)partitionentryptr[i].sector_count *
			   512) ,
	      partitionentryptr[i].partition_type,
	      partitionentryptr[i].partition_type ==
	      0x83 ? "Linux" : partitionentryptr[i].partition_type ==
	      5 ? "Extended" : "else");

      if (partitionentryptr[i].partition_type == 0x05)
	{
	  extended_index = i;
	}
    }

  if (extended_index != -1)
    {

      int j = 0;

      extended_partition_start = partitionentryptr[extended_index].lba;
      lseek (fd, extended_partition_start * 512, SEEK_SET);
      read (fd, buf, 512);
      while ((partitionentryptr[0].partition_type != 0))
	{


	  extended_partition_start += partitionentryptr[j].lba;
	  //printf("%d\n",partitionentryptr[j].lba);
	  printf
	    ("%s%-5d %-5c       %-10u %-10u %-12u %s       %-12X %-12s\n",
	     argv[1], partition_count++,
	     partitionentryptr[0].status == 0x80 ? '*' : ' ',
	     extended_partition_start,
	     extended_partition_start + partitionentryptr[0].sector_count - 1,
	     partitionentryptr[0].sector_count,
	     convertSize((uint64_t)partitionentryptr[0].sector_count *512) ,
			   partitionentryptr[0].partition_type,
	     partitionentryptr[0].partition_type ==
	     0x83 ? "Linux" : partitionentryptr[0].partition_type ==
	     5 ? "Extended" : "else");

	  //  printf("dd%d\n",extended_partition_start);

	  if (partitionentryptr[1].partition_type == 0)
	    {
	      break;
	    }
	  else
	    {
	      //printf("%d\n",extended_partition_start);
	      extended_partition_start += partitionentryptr[j].sector_count;
	      lseek (fd, (extended_partition_start) * 512, SEEK_SET);
	      read (fd, buf, 512);

	      j = 0;
	      printf
		("%s%-5d %-5c       %-10u %-10u %-12u %s       %-12X %-12s\n",
		 argv[1], partition_count++,
		 partitionentryptr[0].status == 0x80 ? '*' : ' ',
		 extended_partition_start + partitionentryptr[0].lba,
		 extended_partition_start + partitionentryptr[0].sector_count,
		 partitionentryptr[0].sector_count,
	      convertSize((uint64_t)partitionentryptr[0].sector_count *
			   512),
		 partitionentryptr[0].partition_type,
		 partitionentryptr[0].partition_type ==
		 0x83 ? "Linux" : partitionentryptr[0].partition_type ==
		 5 ? "Extended" : "else");

	      extended_partition_start += partitionentryptr[0].sector_count;
	      lseek (fd, (extended_partition_start) * 512, SEEK_SET);
	      read (fd, buf, 512);
	    }
	}

    }


  return 0;
}
