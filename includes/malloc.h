#ifndef MALLOC_H
#define MALLOC_H

#define MMAP_PROT (PROT_READ | PROT_WRITE)
#define MMAP_FLAGS (MAP_ANON | MAP_PRIVATE)

// On mac, 2^21 is the max size for tiny arenas.
// 2^21 / 4096 (page size) = 512
#define MAX_TINY	512

#define MAX_SMALL	4096

#define TRUE	1
#define FALSE	0

#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct	s_header t_header;
typedef struct	s_arena t_arena;
typedef struct s_list t_list;
typedef struct s_free t_free;

struct s_header {
	size_t		size;
	void		*data;
	t_header	*next;
	t_header	*prev;
};

struct s_free {
	t_header	header;
	t_header	tiny;
	t_header	small;
};

struct s_list {
	t_header	used;
	t_free		free;
};

t_list	l;

size_t	get_padded_size(size_t size);
void	create_new_link(t_header *link);
void	*create_new_memory_block(size_t size);

/* TESTS */
void	test_get_padded_size(void);
void	test_create_new_link(void);
void	test_create_new_memory_block(void);

#endif
