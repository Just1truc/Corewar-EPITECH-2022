##
## EPITECH PROJECT, 2022
## Corewar
## File description:
## Makefile
##

COREWAR	=	corewar

ASM		=	asm

.PHONY: all
all:
	make -C $(COREWAR)
	make -C $(ASM)

.PHONY: clean
clean:
	make clean -C $(COREWAR)
	make clean -C $(ASM)

.PHONY: fclean
fclean:	clean
	make fclean -C $(COREWAR)
	make fclean -C $(ASM)

.PHONY:	re
re:
	make re -C $(COREWAR)
	make re -C $(ASM)
