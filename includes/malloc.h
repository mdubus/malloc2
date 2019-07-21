#ifndef MALLOC_H
#define MALLOC_H

#define MMAP_PROT (PROT_READ | PROT_WRITE)
#define MMAP_FLAGS (MAP_ANON | MAP_PRIVATE)

// On mac, 2^21 is the max size for tiny arenas.
// 2^21 / 4096 (page size) = 512
#define MAX_TINY	512
#define MAX_SMALL	4096

#define TINY	0
#define SMALL	1
#define LARGE	2

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
	t_header	*next;
	t_header	*prev;
};

struct s_list {
	t_header	*used;
	t_header	*free[2];
};

t_list	l;

size_t		get_padded_size(size_t size);
void		create_new_link(t_header **link);
void		*create_new_memory_block(size_t size);
t_header	*search_best_fit(t_header *list, size_t size);
void		detach_link(t_header **list, t_header *link);
void		*ft_malloc(size_t size);
int			init_arena(int arena_type);
int			get_arena_type(size_t size);
void		split_block(t_header **link, int arena_type, size_t size);
t_header	*search_link_before(t_header *link, t_header *list);
void		insert_link_after(t_header **before, t_header **link);
void		insert_link_in_list(t_header **list, t_header **link);
void		ft_putnbr(size_t nbr);
size_t		ft_strlen(const char *s);
void		ft_putstr(char *str);
char		*ft_utoa_base_r(char *buf, unsigned long long n, unsigned base);

/* TESTS */
void		test_get_padded_size(void);
void		test_create_new_link(void);
void		test_create_new_memory_block(void);
void		test_search_best_fit(void);
void		test_detach_link(void);
void		test_split_block(void);
t_header	*get_testing_list(void);
void		test_search_link_before(void);
void		test_insert_link_after(void);

#endif
