/*********** superblock.c program ************/

#include <ext2fs/ext2_fs.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// typedef u8, u16, u32 SUPER for convenience
typedef unsigned char           u8;
typedef unsigned short          u16;
typedef unsigned int            u32;
typedef struct ext2_super_block SUPER;

SUPER *sp;
char   buf[1024];
int    fd, block_size, inode_size;
int    print(char *s, u32 x) { printf("%-30s = %8d\n", s, x); }

int super(char *device) {
    fd = open(device, O_RDONLY);
    if (fd < 0) {
        printf("open %sfailed\n", device);
        exit(1);
    }
    lseek(fd, (long)1024 * 1, 0);  // block 1 on FD, offset 1024 on HD
    read(fd, buf, 1024);
    sp = (SUPER *)buf;  // as a super block structure

    // check EXT2 FS magic number:
    printf("%-30s = %8x ", "s_magic", sp->s_magic);
    if (sp->s_magic != 0xEF53) {
        printf("NOT an EXT2 FS\n");
        exit(2);
    }
    printf("EXT2 FS OK\n");

    print("s_inodes_count", sp->s_inodes_count);
    print("s_blocks_count", sp->s_blocks_count);
    print("s_r_blocks_count", sp->s_r_blocks_count);
    print("s_free_inodes_count", sp->s_free_inodes_count);
    print("s_free_blocks_count", sp->s_free_blocks_count);
    print("s_first_data_block", sp->s_first_data_block);
    print("s_log_block_size", sp->s_log_block_size);
    print("s_blocks_per_group", sp->s_blocks_per_group);
    print("s_inodes_per_group", sp->s_inodes_per_group);
    print("s_mnt_count", sp->s_mnt_count);
    print("s_max_mnt_count", sp->s_max_mnt_count);

    printf("%-30s = %8x\n", "s_magic", sp->s_magic);
    printf("s_mtime = %s", ctime(&sp->s_mtime));
    printf("s_wtime = %s", ctime(&sp->s_wtime));

    block_size = 1024 * (1 << sp->s_log_block_size);

    printf("block size = %d\n", block_size);
    printf("inode size = %d\n", sp->s_inode_size);
}
char *device = "mydisk";  // default device name

int main(int argc, char *argv[]) {
    if (argc > 1)
        device = argv[1];
    super(device);
}
