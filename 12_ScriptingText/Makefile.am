bin_PROGRAMS=num_guess
TRASH = num_guess num_guess.o 


clean:
	rm -rf $(TRASH)

gitclean: maintainer-clean
	git clean -fd

man: num_guess
	help2man ./num_guess > num_guess.man
