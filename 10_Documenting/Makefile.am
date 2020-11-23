bin_PROGRAMS=num_guess
pkgdata_DATA=ru/LC_MESSAGES/num_guess.mo

TRASH =  messages*.pot num_guess num_guess.o *.po~ ru num_guess.md

@DX_RULES@

ru/LC_MESSAGES/num_guess.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	num_guess.pot num_guess.c
	xgettext -k_ -c num_guess.c -o messages.new.pot
	cp num_guess.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

clean:
	rm -rf $(TRASH)

gitclean: maintainer-clean
	git clean -fd

doxy-mainpage: num_guess
	echo "/// @mainpage" > num_guess.md
	echo "# @PACKAGE_NAME@" >> num_guess.md
	LC_ALL=C ./num_guess --help >> num_guess.md

man: num_guess
	help2man ./num_guess > num_guess.man
