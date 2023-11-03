# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sliashko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 15:52:58 by sliashko          #+#    #+#              #
#    Updated: 2023/10/05 15:53:00 by sliashko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = fdf
INCS = -Iinclude -Iminilibx

# Compiler and flags
CC = gcc
CFLAGS =  $(INCS)

#Directories
SRCDIRS = parser gnl utils draw minilibx
INCDIR = include
OBJDIR = obj
BINDIR = bin
MINLIBXDIR = minilibx
MINLIBX = $(MINLIBXDIR)/minilibx.a

# Source and object files
SOURCES = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
OBJECTS = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCES))



# Default rule
all: $(TARGET)

# Rule to create the target
$(TARGET): $(OBJECTS)
# -C - shows the directory
#this line below builds a minlibx.a library
	@make -C minilibx_macos
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files
$(OBJDIR)/%.o: %.c 
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@


# Clean rule
clean:
	@make clean -C minilibx_macos
	rm -rf $(OBJDIR)

fclean:
	rm $(TARGET)

re: clean fclean all

.PHONY: all clean
