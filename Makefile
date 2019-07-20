#CFLAGS = -Wall -Werror -Wextra -Wpadded -fcolor-diagnostics -fsanitize=address
CFLAGS=

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC=clang
#EXEC = libft_malloc_$(HOSTTYPE).so
EXEC = a.out
UNIT_EXEC = unit
UNIT_TEST_DIR = tests/unit

##### UNIT TEST FRAMEWORK #####

UNITY_SRC = $(addprefix $(UNIT_TEST_DIR)/, "unity/src")
UNIT_TEST_FRAMEWORK = $(addprefix $(UNITY_SRC)/, "unity.c")
UNITY_INCL_FILE = unity.h
UNIT_TEST_INCLUDES = -I $(UNITY_SRC)/$(UNITY_INCL_FILE)

##### UNIT TESTS #####

UNIT_SRC_DIR = $(addprefix $(UNIT_TEST_DIR)/, src)
UNIT_SRC_FILES = test.c test_get_padded_size.c test_create_new_link.c test_create_new_memory_block.c test_search_best_fit.c test_detach_link.c get_testing_list.c test_split_block.c test_search_link_before.c
UNIT_SRCS = $(addprefix $(UNIT_SRC_DIR)/, $(UNIT_SRC_FILES))

##### UNIT OBJS #####

UNIT_OBJ_DIR = $(addprefix $(UNIT_TEST_DIR)/, obj)
UNIT_OBJ_FILES = $(UNIT_SRC_FILES:.c=.o)
UNIT_OBJS = $(addprefix $(UNIT_OBJ_DIR)/, $(UNIT_SRC_FILES:.c=.o))

##### SOURCES #####

SRC_DIR = src
SRC_FILES = malloc.c create_new_link.c get_padded_size.c create_new_memory_block.c search_best_fit.c detach_link.c get_arena_type.c init_arena.c split_block.c search_link_before.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

##### OBJECTS #####

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

##### INCLUDES #####

INCL_DIR = includes
INCL_FILES = malloc.h
INCLUDES = -I $(INCL_DIR)/$(INCL_FILES)

##### RULES #####

all: $(EXEC)

$(EXEC): $(OBJS)
	@$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) main.c $(INCLUDES)
#	@$(CC) $(CFLAGS) -shared -o $(EXEC) $(OBJS) $(INCLUDES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@

unit: $(OBJS) $(UNIT_OBJS)
	@$(CC) -o $(UNIT_EXEC) $(UNIT_OBJS) $(OBJS) $(UNIT_TEST_FRAMEWORK) $(UNIT_TEST_INCLUDES)
	./unit

$(UNIT_OBJ_DIR)/%.o: $(UNIT_SRC_DIR)/%.c
	@mkdir -p $(UNIT_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ_DIR)

clean_unit:
	@rm -rf $(UNIT_OBJ_DIR) $(OBJ_DIR)

fclean: clean
	@rm $(EXEC)

fclean_unit: clean_unit
	@rm $(UNIT_EXEC)

re: fclean all

.PHONY: all unit clean clean_unit fclean fclean_unit re
