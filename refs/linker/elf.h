struct elf_filehdr {
	char magic[4] = "\177ELF"; /* magic number */
	char class;                /* address size, 1: 32 bit, 2: 64 bit */
	char byteorder;            /* 1: little-endian, 2: big-endian */
	char hversion;             /* header version, always 1 */
	char pad[9];
	short filetype;            /* file type: 1: relocatable, 2: executable, 3: shared object, 4: core image */
	short archtype;            /* 2: SPARC, 3: x86, 4: 68K, etc. */
	int fversion;              /* file version, always 1 */
	int entry;                 /* entry point if executable */
	int phdrpos;               /* file position of program header or 0 */
	int shdrpos;               /* file position of section header or 0 */
	int flags;                 /* architecture specific flags, usually 0 */
	short hdrsize;             /* size of this ELF header */
	short phdrent;             /* size of an entry in program header */
	short phdrcnt;             /* number of entries in program header or 0 */
	short shdrent;             /* size of an entry in section header */
	short phdrent;             /* number of entries in section header or 0 */
	short strsec;              /* section number that contains section name strings */
};

struct elf_proghdr {
	int type;     /* loadable code or data, dynamic linking info, etc. */
	int offset;   /* file offset of segment */
	int virtaddr; /* virtual address to map segment */
	int physaddr; /* physical address, not used */
	int filesize; /* size of segment in file */
	int memsize;  /* size of segment in memory (bigger if contains BSS) */
	int flags;    /* Read, Write, Execute bits */
	int align;    /* required alignment, invariably hardware page size */
};

struct elf_secthdr {
	int sh_name;    /* name, index into the string table */
	int sh_type;    /* section type */
	int sh_flags;   /* flag bits, below */
	int sh_addr;    /* base memory address, if loadable, or zero */
	int sh_offset;  /* file position of beginning of section */
	int sh_size;    /* size in bytes*/
	int sh_link;    /* section number with related info or zero */
	int sh_info;    /* more section-specific info */
	int sh_align;   /* alignment granularity if section is moved */
	int sh_entsize; /* size of entries if section is an array */
};