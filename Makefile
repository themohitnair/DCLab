name ?= default

all: $(name).c
		gcc -fopenmp $(name).c && ./a.out

clean:
		@rm -rf a.out