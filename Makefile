CC     		  = cc
CFLAGS 		  = -g
OUTPUT_OPTION = -MMD MP -o $@

SOURCE =$(wildcard *.c)
OBJS   =$(SOURCE: .c=.o)
DEPS   =$(SOURCE:.c=.d)
-include ${DEPS}

main: ${OBJS}
	${CC} -o main ${OBJS}


